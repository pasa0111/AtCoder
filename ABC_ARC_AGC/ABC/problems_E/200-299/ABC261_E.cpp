#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1e9; [[maybe_unused]]constexpr ll INF = 4e18;
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second); }
template <typename T> vector<T>& sumvec(vector<T>& a) {ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T> vector<T>& vecin(vector<T>& a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) {SORT(a); REVERSE(a); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

ll f(ll a, ll t, ll b){
    ll res = -1;
    if(t == 1) res = (a&b);
    else if(t == 2) res = (a|b);
    else res = (a^b);
    return res;
}

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n,c; cin >> n >> c;
    vector<ll> A(n),T(n);
    rep(i,n) cin >> T[i] >> A[i];
    vector<vector<bool>> B(30,vector<bool>(n+1));
    vector<vector<bool>> C(30,vector<bool>(n+1));

    ll x = 0;
    rep(i,30) x += (1<<i);
    rep(i,30) B[i][0] = 1;
    for(ll j = 1; j <= n; j++){
        x = f(x,T[j-1],A[j-1]);
        rep(i,30) B[i][j] = (((x>>i)&1) == 1 ? 1 : 0);
    }
    x = 0;
    rep(i,30) C[i][0] = 0;
    for(ll j = 1; j <= n; j++){
        x = f(x,T[j-1],A[j-1]);
        rep(i,30) C[i][j] = (((x>>i)&1) == 1 ? 1 : 0);
    }

    x = c;
    for(ll j = 1; j <= n; j++){
        ll y = 0;
        for(ll i = 0; i < 30; i++){
            if(((x>>i)&1) == 1) y += (B[i][j]<<i);
            else y += (C[i][j]<<i);
        }
        cout << y << el;
        x = y;
    }

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}