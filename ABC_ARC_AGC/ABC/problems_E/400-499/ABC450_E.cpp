#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1e9; [[maybe_unused]]constexpr ll INF = 4e18;
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U, typename V> bool range(T a, U x, V b) { return ((a) < (x) && (x) < (b)); } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) { return square(a.first) + square(a.second); } template <typename T> vector<T> &sumvec(vector<T> &a) { ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i - 1]; return a; } template <typename T> vector<T> &vecin(vector<T> &a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) { SORT(a); REVERSE(a); return a; } template <typename T, typename U> T &IOTA(T &a, U b) { iota(a.begin(), a.end(), b); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

ll len[100];
ll V[100][26];
ll A[10010][26], B[10010][26];

// 文字 'a'+id が Fkの0~p文字目に何個含まれるか
ll f(int id, int k, ll p){
    if(p < 0) return 0;
    ll res = 0;
    if(k == 1) return A[p][id];
    if(k == 2) return B[p][id];
    if(len[k-1] <= p) res = V[k-1][id] + f(id,k-2,p-len[k-1]);
    else res = f(id,k-1,p);
    return res;
}

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    string X,Y;
    ll q;
    cin >> X >> Y >> q;
    len[1] = X.size(), len[2] = Y.size();
    for(int i = 0; i < (int)X.size(); i++){
        if(i > 0) rep(j,26) A[i][j] = A[i-1][j];
        A[i][X[i]-'a']++;
    }
    for(int i = 0; i < (int)Y.size(); i++){
        if(i > 0) rep(j,26) B[i][j] = B[i-1][j];
        B[i][Y[i]-'a']++;
    }
    rep(i,26) V[1][i] = A[X.size()-1][i];
    rep(i,26) V[2][i] = B[Y.size()-1][i];
    ll lim;
    for(int i = 3; i < 100; i++){
        len[i] = len[i-1] + len[i-2];
        for(int j = 0; j < 26; j++) V[i][j] = V[i-1][j] + V[i-2][j];
        if(len[i] >= 1e18 + 100){
            lim = i;
            break;
        }
    }
    rep(query,q){
        ll l,r; cin >> l >> r; l--,r--;
        char c; cin >> c;
        cout << f(c-'a',lim,r) - f(c-'a',lim,l-1) << el;
    }


    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}