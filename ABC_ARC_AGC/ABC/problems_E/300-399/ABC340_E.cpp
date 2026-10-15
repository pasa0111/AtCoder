#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 1000001001; [[maybe_unused]] constexpr ll INF = 4000000000000000000; [[maybe_unused]] constexpr ll DX[8] = {-1,1,0,0,-1,-1,1,1}; [[maybe_unused]] constexpr ll DY[8] = {0,0,-1,1,-1,1,-1,1};
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) {return square(a.first) + square(a.second); }
template <typename T> vector<T>& sumvec(vector<T>& a) {ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i-1]; return a;} template <typename T> vector<T>& vecin(vector<T>& a) { for (auto &x : a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) {SORT(a); REVERSE(a); return a; } template <ranges::range R> requires (!is_convertible_v<R, string_view>) ostream &operator<<(ostream &os, const R &a) { os << "{"; bool f = 1; for (const auto &x : a) { if (!f) os << ","; f = 0; os << x; } return os << "}"; }
void yesno(bool b){
    cout << (b ? "Yes" : "No") << el;
}

namespace atcoder {
template <class T> struct fenwick_tree {
  public:
    fenwick_tree() : _n(0) {}
    explicit fenwick_tree(int n) : _n(n), data(n) {}
    explicit fenwick_tree(const std::vector<T>& v) : _n(int(v.size())), data(v.size()) {
        for (int i = 0; i < _n; i++) add(i, v[i]);
    }
    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while (p <= _n) { data[p - 1] += x; p += p & -p; }
    }
    T at(int p) {
        assert(0 <= p && p < _n);
        return sum(p, p + 1);
    }
    void set(int p, T x) {
        assert(0 <= p && p < _n);
        add(p, x - at(p));
    }
    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }
    int lower_bound(T w) {
        if (w <= 0) return 0;
        int x = 0;
        int k = 1;
        while (k <= _n / 2) k *= 2; 
        for (; k > 0; k /= 2) {
            if (x + k <= _n && data[x + k - 1] < w) {
                w -= data[x + k - 1];
                x += k;
            }
        }
        return x;
    }
  private:
    int _n;
    std::vector<T> data;
    T sum(int r) {
        T s = 0;
        while (r > 0) { s += data[r - 1]; r -= r & -r; }
        return s;
    }
};
}
using namespace atcoder;

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////\n";
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n,m; cin >> n >> m;
    fenwick_tree<ll> T(n+1);
    rep(i,n){
        ll a; cin >> a;
        T.add(i,a);
        T.add(i+1,-a);
    }
    rep(query,m){
        ll b; cin >> b;
        ll a = T.sum(0,b+1);
        T.add(b,-a);
        T.add(b+1,a);
        T.add(0,a/n);
        ll d = a - (a/n * n);
        if(b+d < n){
            T.add(b+1,1);
            T.add(b+d+1,-1);
        }
        else {
            ll l = (b+d)%n;
            T.add(b+1,1);
            T.add(0,1);
            T.add(l+1,-1);
        }
    }
    rep(i,n) cout << T.sum(0,i+1) << (i == n-1 ? '\n' : ' ');

    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms\n//////////////////////////////////////////////////////\n";
    #endif
}