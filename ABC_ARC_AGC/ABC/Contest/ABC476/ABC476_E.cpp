#include <bits/stdc++.h> /*  ^__________^  */
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1, 1, 0, 0, -1, -1, 1, 1}; [[maybe_unused]] constexpr ll DY[8] = {0, 0, -1, 1, -1, 1, -1, 1};
#define rep(i,n) for (ll i = 0; i < (ll)(n); i++)
template <ranges::range R> requires(!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a); template <typename T> using PLqueue=priority_queue<T>; template <typename T,typename U> ostream &operator<<(ostream &os,const pair<T,U> &p){os << "(" << p.first << ", " << p.second << ")"; return os;} template <typename T, typename U> istream &operator>>(istream &is, pair<T, U> &p){is >> p.first >> p.second; return is;} template <typename T> vector<T> rotate(vector<T> &S){assert(!S.empty()); int h = S.size(), w = S[0].size(); vector<T> res(w); for (int i = 0; i < w; i++) res[i].resize(h); for (int i = 0; i < w; i++) {for(int j = 0; j < h; j++) {res[i][j] = S[j][w - 1 - i];}} return res;} template <typename T> T &SORT(T &a){sort(a.begin(),a.end()); return a;} template <typename T> T &REVERSE(T &a){reverse(a.begin(), a.end()); return a;} template <ranges::range R> requires(!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) {if constexpr (is_same_v<ranges::range_value_t<R>, string>) {bool f = true; for (const auto &x : a) {if (!f) os << '\n'; f = false; os << x; } return os;} else{os << "{"; bool f = 1; for (const auto &x:a) {if (!f) os << ","; f = 0; os << x;} return os << "}";}}
template <typename T> using PGqueue=priority_queue<T,vector<T>,greater<T>>; template <typename T> vector<vector<T>> &sumvec2d(vector<vector<T>> &A) {ll h = A.size(); if(h == 0) return A; ll w = A[0].size(); for(ll i = 0; i < h; i++) for(ll j = 1; j < w; j++) A[i][j] += A[i][j-1]; for(ll j = 0; j < w; j++) for(ll i = 1; i < h; i++) A[i][j] += A[i - 1][j]; return A;} pair<ll, ll> dirvec(pair<ll, ll> a, pair<ll, ll> b) {ll dx = a.first-b.first, dy = a.second-b.second; if(dx == 0 && dy == 0) return pair(0,0); else if(dx == 0) return pair(0,1); else if(dy == 0) return pair(1, 0); if(dx < 0){dx = -dx; dy = -dy;} ll g = gcd(dx,abs(dy)); dx /= g, dy /= g; return pair(dx,dy);} template <typename T> vector<T> &vecin(vector<T> &a){for(auto &x:a) cin >> x; return a;} template <typename T> T &RSORT(T &a){sort(a.rbegin(), a.rend()); return a;} template <typename T> vector<T> &sumvec(vector<T> &a){ll b = a.size(); for(ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T,typename U> bool chmax(T& a, U b){if(a < b){a = b; return true;} return false;}
template <typename T> T square(T a){return a*a;}  struct set_stage{set_stage(){ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(20);}}set_stage_0w0; template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) {return {a.first+b.first, a.second+b.second};} template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b){return {a.first - b.first, a.second - b.second};} template <typename T> auto intpow(T a, ll b){using Ret = std::conditional_t<std::is_integral_v<T> && (sizeof(T) < sizeof(ll)), ll, T>; assert(b >= 0); Ret res = 1; Ret base = a; while(b){if(b & 1) res *= base; b >>= 1; if(!b)break; base *= base;} return res;} ll intpow(ll a,ll b,ll c){assert(b >= 0 && c > 0); ll res = 1%c; ll base = a%c; while(b){if(b & 1) res = (res*base)%c; b >>= 1; if(!b) break; base = (base*base)%c;} return res;} template <typename T,typename U> bool chmin(T& a, U b){if(a > b){a = b; return true;} return false;}
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

namespace atcoder {
#ifndef PAS4_INTERNAL_CEIL_POW2
  #define PAS4_INTERNAL_CEIL_POW2
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
    void assign(S val) {
        for (int i = 0; i < size; i++) {
            d[size + i] = (i < _n) ? val : e();
        }
        for (int i = size - 1; i >= 1; i--) update(i);
    }
    void assign(const std::vector<S>& v) {
        assert(int(v.size()) == _n);
        for (int i = 0; i < size; i++) {
            d[size + i] = (i < _n) ? v[i] : e();
        }
        for (int i = size - 1; i >= 1; i--) update(i);
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
//segtree<S,op,e>
struct S{
    ll min_value;
    ll min_idx;
    ll max_value;
    ll max_idx;
};
S op(S a, S b){
    S res = {-1,-1,-1,-1};
    if(a.min_value <= b.min_value){
        res.min_value = a.min_value;
        res.min_idx = a.min_idx;
    }
    else {
        res.min_value = b.min_value;
        res.min_idx = b.min_idx;
    }

    if(a.max_value >= b.max_value){
        res.max_value = a.max_value;
        res.max_idx = a.max_idx;
    }
    else {
        res.max_value = b.max_value;
        res.max_idx = b.max_idx;
    }
    return res;
}
S e(){return {INF,-1,-INF,-1};} // op(x,e) = x

// seg(vector<S>(n)) 初期化
// set(i,x) i番目の要素をxに書き換え
// get(i) i番目の要素を取得
// prod(l,r) [l,r)をopで計算
// all_prod() [0,n)をopで計算
// assign(x) すべての要素をxに置き換える
// assign(vec) 要素をvecに置き換える

int main(){
    ll n,m; cin >> n >> m;
    vector<ll> P(n); vecin(P); rep(i,n) P[i]--;
    segtree<S,op,e> T(n);
    rep(i,n) T.set(i,{P[i],i,P[i],i});
    while(m--){
        ll l,r; cin >> l >> r; l--,r--;
        auto [max_value,max_idx,min_value,min_idx] = T.prod(l,r+1);
        T.set(min_idx,{max_value,min_idx,max_value,min_idx});
        T.set(max_idx,{min_value,max_idx,min_value,max_idx});
    }
    rep(i,n) cout << T.get(i).min_value + 1 << ' ';
    cout << el;
}