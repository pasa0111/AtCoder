#include <bits/stdc++.h> /*  ^__________^  */
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) {return a * a;} template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) {os << "(" << p.first << ", " << p.second << ")"; return os;} template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> auto sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second); } template <typename T> vector<T>& sumvec(vector<T>& a) {ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T> vector<T>& vecin(vector<T>& a) {for (auto &x:a) cin >> x; return a;}
template <typename T> T &SORT(T &a) {sort(a.begin(), a.end()); return a;} template <typename T> T& REVERSE(T &a) {reverse(a.begin(), a.end()); return a;} template <typename T> T &RSORT(T &a) {sort(a.rbegin(),a.rend()); return a;} template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) {os << "{"; bool f = 1; for (const auto &x : a) {if (!f) os << ","; f = 0; os << x;} return os << "}";} template <typename T> vector<vector<T>>& sumvec2d(vector<vector<T>>& A){ll h = A.size(); if(h == 0) return A; ll w = A[0].size(); for(ll i = 0; i < h; i++)for(ll j = 1; j < w; j++) A[i][j] += A[i][j-1]; for(ll j = 0; j < w; j++)for(ll i = 1; i < h; i++) A[i][j] += A[i-1][j]; return A;} pair<ll,ll> dirvec(pair<ll,ll> a, pair<ll,ll> b){ll dx = a.first-b.first, dy = a.second-b.second; if(dx == 0 && dy == 0) return pair(-1,0); else if(dx == 0) return pair(0,1); else if(dy == 0) return pair(1,0); if(dx < 0){dx = -dx; dy = -dy;} ll g = gcd(dx,abs(dy)); dx /= g, dy /= g; return pair(dx,dy);}
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

namespace atcoder {
template<int id = 0> struct dynamic_modint {
    using mint = dynamic_modint;
  public:
    static void set_mod(int m) { assert(1 <= m); _mod = (unsigned int)(m); }
    static int mod() { return (int)(_mod); }
    static mint raw(int v) { mint x; x._v = v; return x; }
    dynamic_modint() : _v(0) {}
    template <class T> dynamic_modint(T v) {
        long long x = (long long)(v % (long long)(mod()));
        if (x < 0) x += mod();
        _v = (unsigned int)(x);
    }
    unsigned int val() const { return _v; }
    mint& operator++() { _v++; if (_v == _mod) _v = 0; return *this; }
    mint& operator--() { if (_v == 0) _v = _mod; _v--; return *this; }
    mint operator++(int) { mint result = *this; ++*this; return result; }
    mint operator--(int) { mint result = *this; --*this; return result; }
    mint& operator+=(const mint& rhs) { _v += rhs._v; if (_v >= _mod) _v -= _mod; return *this; }
    mint& operator-=(const mint& rhs) { _v -= rhs._v; if (_v >= _mod) _v += _mod; return *this; }
    mint& operator*=(const mint& rhs) { unsigned long long z = _v; z *= rhs._v; _v = (unsigned int)(z % _mod); return *this; }
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
        long long a = _v, b = mod(), u = 1, v = 0;
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
    static inline unsigned int _mod = 998244353;
};
}
using mint = atcoder::dynamic_modint<0>;
// using Mint = atcoder::dynamic_modint<1>;  // 2つ使いたいとき
// mint::set_mod(m)   mを法にする

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(15);

    ll n,m; cin >> n >> m;
    mint::set_mod(m);
    vector<ll> A(n), B(n-1); vecin(A); vecin(B);

    vector<ll> S(n-1);
    S[0] = B[0];
    for(ll i = 1; i < n-1; i++) S[i] = S[i-1]+(i%2 == 0 ? B[i] : -B[i]);

    vector<mint> V(n);
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        V[i] = (i > 0 ? (i%2 == 0 ? -S[i-1] : S[i-1]) : 0) - A[i];
        ans += V[i].val();
    }

    vector<pair<mint,ll>> Q(n);
    for(ll i = 0; i < n; i++){
        if(i%2 == 0) Q[i] = pair(m-V[i],-m);
        else Q[i] = pair(V[i]+1,m);
    }
    sort(Q.begin(),Q.end(),[](auto a, auto b){
        return a.first.val() < b.first.val();
    });
    
    ll pre = 0, idx = 0, d = (n%2 == 0 ? 0 : 1), f = ans;
    while(idx < n && Q[idx].first == 0) idx++;
    while(idx < n){
        ll now = Q[idx].first.val();
        f += d*(now-pre);
        while(idx < n && Q[idx].first == now){
            f += Q[idx].second;
            idx++;
        }
        ans = min(ans,f);
        pre = now;
    }
    cout << ans << el;

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}