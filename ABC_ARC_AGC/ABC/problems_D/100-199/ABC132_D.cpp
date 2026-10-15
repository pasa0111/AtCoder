#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second); }
template <typename T> vector<T>& sumvec(vector<T>& a) {ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T> vector<T>& vecin(vector<T>& a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) {sort(a.rbegin(),a.rend()); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

constexpr ll lim = 4010, MOD = 1000000007;

constexpr ll modpow(ll a, ll b) {
    ll res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = (res*a) % MOD;
        a = (a*a) % MOD;
        b >>= 1;
    }
    return res;
}

struct FactTable {
    std::array<ll, lim> fact{};
    std::array<ll, lim> invFact{};
};

constexpr FactTable precompute() {
    FactTable res{};
    res.fact[0] = 1;
    for (ll i = 1; i < lim; i++) res.fact[i] = (res.fact[i - 1] * i) % MOD;
    res.invFact[lim - 1] = modpow(res.fact[lim - 1], MOD - 2);
    for (ll i = lim - 2; i >= 0; i--) res.invFact[i] = (res.invFact[i + 1] * (i + 1)) % MOD;
    return res;
}

constexpr auto TABLE = precompute();

constexpr ll nCr(ll n, ll r) {
    if (n < 0 || r < 0 || n < r) return 0;
    ll num = TABLE.fact[n];
    ll den = (TABLE.invFact[r] * TABLE.invFact[n - r]) % MOD;
    return (num * den) % MOD;
}

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n,k; cin >> n >> k;
    for(ll i = 1; i <= k; i++) cout << (nCr(k-1,i-1) * nCr(n-k+1,i))%MOD << el;

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}