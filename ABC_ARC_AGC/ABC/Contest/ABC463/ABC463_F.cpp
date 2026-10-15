#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second); }
template <typename T> vector<T>& sumvec(vector<T>& a) {ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T> vector<T>& vecin(vector<T>& a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) {sort(a.rbegin(),a.rend()); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
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

namespace atcoder {
#ifndef ATCODER_INTERNAL_CEIL_POW2
#define ATCODER_INTERNAL_CEIL_POW2
namespace internal {
    int ceil_pow2(int n) {
        int x = 0;
        while ((1U << x) < (unsigned int)(n)) x++;
        return x;
    }
}
#endif
template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) update(i);
    }
    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }
    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size; r += size;
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1; r >>= 1;
        }
        return op(sml, smr);
    }
    S all_prod() const { return d[1]; }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) { sm = op(sm, d[l]); l++; }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) { sm = op(d[r], sm); r--; }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }
  private:
    int _n, size, log;
    std::vector<S> d;
    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};
}
using namespace atcoder;
//segtree<S, op, e>
struct S{
    ll value;
    ll size;
    ll copy;
};
S op(S a, S b){
    if(a.value > b.value) return a;
    else if(a.value == b.value) return {a.value, a.size+b.size, a.copy+b.copy};
    else if(a.value < b.value) return b;
}
S e(){return -INF;} // op(x,e) = x

// seg(vector<S>(n)) 初期化
// set(i,x) i番目の要素をxに書き換え
// get(i) i番目の要素を取得
// prod(l,r) [l,r)をopで計算
// all_prod() [0,n)をopで計算

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n; cin >> n;
    const ll m = 2*n;
    vector<ll> A(m); vecin(A);
    segtree<S,op,e> T(m);
    rep(i,n) T.set(i,{A[i],1,0});
    vector<mint> P(m,1);
    for(ll i = 0; i < m; i+=2){
        if(A[i] < A[i+1]-1) P[i] = 0;
        else if(A[i] == A[i+1]-1){
            P[i] = 1/(mint)2;
            T.set(i,{A[i],1,1});
        }
        else if(A[i] == A[i+1]+1){
            P[i+1] = 1/(mint)2;
            T.set(i,{A[i+1],1,1});
        }
        else if(A[i] > A[i+1]+1) P[i+1] = 0;
    }
    for(ll i = 0; i < m; i+=2){
        if(T.get(i).copy == 1){
            T.set(i,{A[i],1,0});
            //S x = T.all_prod();
        }
    }

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}