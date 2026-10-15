#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]]constexpr ll INF = 4000000000000000000;
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second); }
template <typename T> vector<T>& sumvec(vector<T>& a) {ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T> vector<T>& vecin(vector<T>& a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) {SORT(a); REVERSE(a); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

vector<vector<ll>> A,B;
ll n,k;
ll t;
bool check(ll x){
    //cout << "x = " << x << el;
    for(ll i = 0; i < n; i++)for(ll j = 0; j < n; j++) B[i][j] = (A[i][j] < x ? 1 : 0);
    for(ll i = 0; i < n; i++)for(ll j = 1; j < n; j++) B[i][j] += B[i][j-1];
    for(ll j = 0; j < n; j++)for(ll i = 1; i < n; i++) B[i][j] += B[i-1][j];
    //for(ll i = 0; i < n; i++) cout << B[i] << el;
    for(ll i = 0; i+k-1 < n; i++)for(ll j = 0; j+k-1 < n; j++){
        ll cnt = B[i+k-1][j+k-1] - (j > 0 ? B[i+k-1][j-1] : 0) - (i > 0 ? B[i-1][j+k-1] : 0) + (i > 0 && j > 0 ? B[i-1][j-1] : 0);
        //cout << pair(i,j) << " : " << cnt << el;
        if(cnt >= t) return true;
    }
    return false;
}

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> k;
    t = k*k - k*k/2;
    A.resize(n);
    B.resize(n);
    for(ll i = 0; i < n; i++){
        A[i].resize(n);
        B[i].resize(n);
        vecin(A[i]);
    }
    ll l = 0, r = inf, m = inf/2;
    while(r-l > 1){
        bool b = check(m);
        if(b) r = m;
        else l = m;
        m = (l+r)/2;
    }
    cout << m << el;

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}