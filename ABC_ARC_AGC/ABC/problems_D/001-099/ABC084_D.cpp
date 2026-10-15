#pragma region mytemplate

#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <cctype>
#include <chrono>
#include <cassert>
#include <numeric>
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using namespace std;
using ll = long long;
#define rep(i,j) for(ll i = 0, jjjjjjjjjj = (j); i < jjjjjjjjjj; i++)
#define vecall(vec) vec.begin(),vec.end()
#define MP make_pair
#define MT make_tuple
#define el '\n'
[[maybe_unused]] const ll inf = 2000000000;
[[maybe_unused]] const ll INF = 9000000000000000000;

template <typename T> using PLqueue = priority_queue<T>;
template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>;
template <typename T>               T            square(T a){return a*a;}
template <typename T, typename U, typename V> bool range(T a,U x,V b){return ((a) < (x) && (x) < (b));}
template <typename T, typename U>   ostream&     operator<<(ostream& os, const pair<T, U>& p){os << "(" << p.first << ", " << p.second << ")";return os;}
template <typename T, typename U>   pair<T, U>   operator+(const pair<T, U>& a, const pair<T, U>& b){return {a.first + b.first, a.second + b.second};}
template <typename T, typename U>   pair<T, U>   operator-(const pair<T, U>& a, const pair<T, U>& b){return {a.first - b.first, a.second - b.second};}
template <typename T, typename U>   pair<U,T>    pairswap(const pair<T,U>& a){return MP(a.second,a.first);}
template <typename T, typename U>   ll           abs(const pair<T, U>& a){return square(a.first)+square(a.second);}
template <typename T, typename U>   vector<T>&   operator+=(vector<T>& a, const U& b){a.push_back(b); return a;}
template <typename T>               void         operator--(vector<T>& a, int){if(!a.empty())a.pop_back();}
template <typename T>               vector<T>&   sumvec(vector<T>& a){ll b = a.size(); for(ll i = 1; i < b; i++)a[i] += a[i-1]; return a;}
template <typename T>               vector<T>&   vecin(vector<T>& a){ll b = a.size(); rep(i,b)cin >> a[i]; return a;}
template <typename T>               vector<T>&   SORT(vector<T>& a){sort(a.begin(), a.end()); return a;}
template <typename T>               T&           REVERSE(T& a){reverse(a.begin(), a.end()); return a;}
template <typename T>               vector<T>&   RSORT(vector<T>& a){SORT(a); REVERSE(a); return a;}
template <typename T>               istream&     operator>>(istream& is, vector<T>& a){T x; is >> x; a += x; return is;}
template <typename T>               ostream&     operator<<(ostream& os, const vector<T>& a){bool first = true; os << "{"; for(const T& x:a){if(!first)os << ","; first = false; os << x;} os << "}"; return os;}
template <typename T, typename U>   set<T>&      operator+=(set<T>& a, const U& b){a.insert(b); return a;}
template <typename T, typename U>   set<T>&      operator-=(set<T>& a, const U& b){a.erase(b); return a;}
template <typename T>               istream&     operator>>(istream& is, set<T>& s){T x; is >> x; s += x; return is;}
template <typename T>               ostream&     operator<<(ostream& os, const set<T>& a){bool first = true; os << "{"; for(const T& x:a){if(!first)os << ","; first = false; os << x;} os << "}"; return os;}
template <typename T>               T            min(set<T>& a){return *a.begin();}
template <typename T>               T            max(set<T>& a){return *a.rbegin();}
template <typename T, typename U>   multiset<T>& operator+=(multiset<T>& a, const U& b){a.insert(b); return a;}
template <typename T>               T            min(multiset<T>& a){return *a.begin();}
template <typename T>               T            max(multiset<T>& a){return *a.rbegin();}
template <typename T>               istream&     operator>>(istream& is, multiset<T>& s){T x; is >> x; s += x; return is;}
template <typename T>               ostream&     operator<<(ostream& os, const multiset<T>& a){bool first = true; os << "{"; for(const T& x:a){if(!first)os << ","; first = false; os << x;} os << "}"; return os;}
template <typename T, typename U>   queue<T>&    operator+=(queue<T>& a, const U& b){a.push(b); return a;}
template <typename T>               void         operator--(queue<T>& a, int){if(!a.empty())a.pop();}
template <typename T>               ostream&     operator<<(ostream& os, queue<T> a){bool first = true; os << "{"; while(!a.empty()){if(!first)os << ","; first = false; os << a.front(); a--;} os << "}"; return os;}
template <typename T, typename U>   PGqueue<T>&  operator+=(PGqueue<T>& a, const U& b){a.push(b); return a;}
template <typename T>               void         operator--(PGqueue<T>& a, int){if(!a.empty())a.pop();}
template <typename T>               T            min(PGqueue<T>& a){return a.top();}
template <typename T>               ostream&     operator<<(ostream& os, PGqueue<T> a){bool first = true; os << "{"; while(!a.empty()){if(!first)os << ","; first = false; os << min(a); a--;} os << "}"; return os;}
template <typename T, typename U>   PLqueue<T>&  operator+=(PLqueue<T>& a, const U& b){a.push(b); return a;}
template <typename T>               void         operator--(PLqueue<T>& a, int){if(!a.empty())a.pop();}
template <typename T>               T            max(PLqueue<T>& a){return a.top();}
template <typename T>               ostream&     operator<<(ostream& os, PLqueue<T> a){bool first = true; os << "{"; while(!a.empty()){if(!first)os << ","; first = false; os << max(a); a--;} os << "}"; return os;}
template <typename T, typename U>   stack<T>&    operator+=(stack<T>& a, const U& b){a.push(b); return a;}
template <typename T>               void         operator--(stack<T>& a, int){if(!a.empty())a.pop();}
template <typename T>               istream&     operator>>(istream& is, stack<T>& s){T x; is >> x; s += x; return is;}
template <typename T>               ostream&     operator<<(ostream& os, stack<T> a){bool first = true; os << "{"; while(!a.empty()){if(!first)os << ","; first = false; os << a.top(); a--;} os << "}"; return os;}
template <typename T, typename U>   T&           IOTA(T& a, U b){iota(vecall(a),b); return a;}

//n以下の正整数が素数であるかを配列Pに保存
void sieve(ll n, vector<bool> &P){ P[0] = false, P[1] = false; for(ll i = 2; i*i <= n; i++){ if(P[i])for(ll j = i*i; j <= n; j += i)P[j] = false; } return; }

namespace atcoder {

struct dsu {
  public:
    dsu() : _n(0) {}
    dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    std::vector<int> parent_or_size;
};



template<int m> struct static_modint {
    using mint = static_modint;
  
  public:
    static constexpr int mod() { return m; }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    static_modint() : _v(0) {}
    template <class T>
    static_modint(T v) {
        long long x = (long long)(v % (long long)(m));
        if (x < 0) x += m;
        _v = (unsigned int)(x);
    }

    unsigned int val() const { return _v; }

    mint& operator++() {
        _v++;
        if (_v == m) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = m;
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= m) _v -= m;
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v -= rhs._v;
        if (_v >= m) _v += m;
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        unsigned long long z = _v;
        z *= rhs._v;
        _v = (unsigned int)(z % m);
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        long long a = _v, b = m, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        return mint(u);
    }

    friend mint operator+(const mint& lhs, const mint& rhs) { return mint(lhs) += rhs; }
    friend mint operator-(const mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }
    friend mint operator*(const mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }
    friend mint operator/(const mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }
    friend bool operator==(const mint& lhs, const mint& rhs) { return lhs._v == rhs._v; }
    friend bool operator!=(const mint& lhs, const mint& rhs) { return lhs._v != rhs._v; }
    
    friend istream& operator>>(istream& os, mint& rhs) {
        long long v;
        os >> v;
        rhs = mint(v);
        return os;
    }
    friend ostream& operator<<(ostream& os, const mint& rhs) {
        return os << rhs._v;
    }

  private:
    unsigned int _v;
};




template <class T> struct fenwick_tree {
  public:
    fenwick_tree() : _n(0) {}
    explicit fenwick_tree(int n) : _n(n), data(n) {}

    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while (p <= _n) {
            data[p - 1] += x;
            p += p & -p;
        }
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

  private:
    int _n;
    std::vector<T> data;
    T sum(int r) {
        T s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};




int internal_ceil_pow2(int n) {
int x = 0;
while ((1U << x) < (unsigned int)(n)) x++;
return x;
}

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal_ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
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
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
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
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
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
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
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

#pragma endregion

/*



*/

using namespace atcoder;
// using mint = static_modint<998244353>;
// using mint = static_modint<1000000007>;
// using segtype = ll;
// segtype op(segtype a, segtype b){

// }
// segtype e(){return -INF;} //op(x,e) = x

void yesno(bool b){
    if(b) cout << "Yes" << el;
    if(!b) cout << "No" << el;
}


int main(){
    #ifdef pas4
        freopen("input.txt", "r", stdin);
        auto timestart = chrono::high_resolution_clock::now();
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ////////////////////////////////
    ll q; cin >> q;
    vector<bool> isprime(100010,true);
    sieve(100000,isprime);
    vector<ll> cnt(100010); //2017に似た数の累積和
    for(ll i = 1; i <= 100000; i+=2)if(isprime[i] && isprime[(i+1)/2])cnt[i]++;
    sumvec(cnt);
    rep(query,q){
        ll l,r; cin >> l >> r;
        cout << cnt[r]-cnt[l-1] << el;
    }
    ////////////////////////////////
    #ifdef pas4
        auto timeend = chrono::high_resolution_clock::now();
        auto timeduration = chrono::duration_cast<chrono::milliseconds>(timeend - timestart).count();
        cout << "Exec Time: " << timeduration << "ms" << el;
    #endif
}