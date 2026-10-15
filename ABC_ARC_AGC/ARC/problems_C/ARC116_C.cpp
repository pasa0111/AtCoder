#include <bits/stdc++.h> /*  ^__________^  */
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1, 1, 0, 0, -1, -1, 1, 1}; [[maybe_unused]] constexpr ll DY[8] = {0, 0, -1, 1, -1, 1, -1, 1};
#define rep(i,n) for (ll i = 0; i < (ll)(n); i++)
template<typename T> using PLqueue=priority_queue<T>; template<typename T> using PGqueue = priority_queue<T,vector<T>,greater<T>>; template<typename T> T square(T a){return a * a;} template<typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p){os << "(" << p.first << ", " << p.second << ")"; return os;} struct set_stage {set_stage() { ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(20); } } set_stage; template<typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template<typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second};} template<typename T,typename U> auto sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second);} ll intpow(ll a, ll b){assert(b >= 0); ll res = 1; while(b){if(b&1) res *= a; b >>= 1; if(!b) break; a *= a;} return res;}
template<typename T, typename U> istream &operator>>(istream &is, pair<T, U> &p) { is >> p.first >> p.second; return is; } template<typename T> vector<T> rotate(vector<T> &S) { assert(!S.empty()); int h = S.size(), w = S[0].size(); vector<T> res(w); for (int i = 0; i < w; i++) res[i].resize(h); for (int i = 0; i < w; i++) { for (int j = 0; j < h; j++) { res[i][j] = S[j][w - 1 - i]; } } return res; } template<typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template<typename T> T &REVERSE(T &a) {reverse(a.begin(), a.end()); return a;} template<ranges::range R> requires(!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { if constexpr (is_same_v<ranges::range_value_t<R>, string>) { bool f = true; for (const auto &x : a) { if (!f) os << '\n'; f = false; os << x; } return os; } else { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; } }
template<typename T> vector<vector<T>> &sumvec2d(vector<vector<T>> &A) { ll h = A.size(); if (h == 0) return A; ll w = A[0].size(); for(ll i = 0; i < h; i++) for (ll j = 1; j < w; j++) A[i][j] += A[i][j - 1]; for (ll j = 0; j < w; j++) for (ll i = 1; i < h; i++) A[i][j] += A[i - 1][j]; return A; } pair<ll, ll> dirvec(pair<ll, ll> a, pair<ll, ll> b) { ll dx = a.first - b.first, dy = a.second - b.second; if (dx == 0 && dy == 0) return pair(0, 0); else if (dx == 0) return pair(0, 1); else if (dy == 0) return pair(1, 0); if(dx < 0){dx = -dx; dy = -dy;} ll g = gcd(dx, abs(dy)); dx /= g, dy /= g; return pair(dx, dy); } template<typename T> vector<T> &vecin(vector<T> &a) { for (auto &x : a) cin >> x; return a; } template<typename T> T &RSORT(T &a) {sort(a.rbegin(), a.rend()); return a; } template<typename T> vector<T> &sumvec(vector<T> &a) { ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i - 1]; return a; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

namespace atcoder {
template<int m> struct static_modint {
    using mint = static_modint;
  public:
    static constexpr int mod() { return m; }
    static mint raw(int v) { mint x; x._v = v; return x; }
    static_modint() : _v(0) {}
    template <class T> static_modint(T v) {
        long long x = (long long)(v % (long long)(m));
        if (x < 0) x += m;
        _v = (unsigned int)(x);
    }
    unsigned int val() const { return _v; }
    mint& operator++() { _v++; if (_v == m) _v = 0; return *this; }
    mint& operator--() { if (_v == 0) _v = m; _v--; return *this; }
    mint operator++(int) { mint result = *this; ++*this; return result; }
    mint operator--(int) { mint result = *this; --*this; return result; }
    mint& operator+=(const mint& rhs) { _v += rhs._v; if (_v >= m) _v -= m; return *this; }
    mint& operator-=(const mint& rhs) { _v -= rhs._v; if (_v >= m) _v += m; return *this; }
    mint& operator*=(const mint& rhs) { unsigned long long z = _v; z *= rhs._v; _v = (unsigned int)(z % m); return *this; }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }
    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }
    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) { if (n & 1) r *= x; x *= x; n >>= 1; }
        return r;
    }
    mint inv() const {
        long long a = _v, b = m, u = 1, v = 0;
        while (b) { long long t = a / b; a -= t * b; std::swap(a, b); u -= t * v; std::swap(u, v); }
        return mint(u);
    }
    friend mint operator+(const mint& lhs, const mint& rhs) { return mint(lhs) += rhs; }
    friend mint operator-(const mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }
    friend mint operator*(const mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }
    friend mint operator/(const mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }
    friend bool operator==(const mint& lhs, const mint& rhs) { return lhs._v == rhs._v; }
    friend bool operator!=(const mint& lhs, const mint& rhs) { return lhs._v != rhs._v; }
    friend std::istream& operator>>(std::istream& os, mint& rhs) { long long v; os >> v; rhs = mint(v); return os; }
    friend std::ostream& operator<<(std::ostream& os, const mint& rhs) { return os << rhs._v; }
  private:
    unsigned int _v;
};
}

using mint = atcoder::static_modint<998244353>;
// using mint = atcoder::static_modint<1000000007>;


/*

Ai+1 = k Ai (k = 1,2,...)

掛け算だからすぐに m を越えそう

初項をsとする
条件を満たすAの例: s s s 2s 2s 6s 6s 36s 72s ...
sの係数            1     2     6   36  72

sからスタートして、mを越えないようにsに2以上の整数を掛けていく
s --> 2s --> 4s --> 12s --> 24s ...

s,2s,4sを使って長さnのAを構成する方法の数 = n個の⚪︎の間に2つの仕切りを入れる場合の数

s  s   2s   4s 4s
⚪︎ ⚪︎ | ⚪︎ | ⚪︎ ⚪︎ 

*/

int M[200010][20];

int main(){
    constexpr int lim = 300000;
    vector<mint> F(lim), Finv(lim);
    F[0] = 1;
    for(int i = 1; i < lim; i++) F[i] = F[i-1]*i;
    Finv[lim-1] = 1/F[lim-1];
    for(int i = lim-2; i >= 0; i--) Finv[i] = Finv[i+1]*(i+1);

    int n,m; cin >> n >> m;
    mint ans = 0;
    auto dfs = [&](this auto&& dfs, int s, int cnt)-> void {
        M[s][cnt]++;
        for(int k = 2; s*k <= m && cnt+1 <= n; k++) dfs(s*k,cnt+1);
    };

    for(int s = 1; s <= m; s++) dfs(s,1);
    for(ll i = 1; i <= m; i++) for(ll d = 1; d < 20 && d <= n; d++) ans += M[i][d] * F[n-1]*Finv[d-1]*Finv[n-d];
    cout << ans << el;
}