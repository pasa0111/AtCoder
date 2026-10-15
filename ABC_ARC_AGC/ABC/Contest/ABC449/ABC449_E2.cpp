#include <bits/stdc++.h>
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 2000000000; [[maybe_unused]]constexpr ll INF = 9000000000000000000;
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a) { return a * a; } template <typename T, typename U, typename V> bool range(T a, U x, V b) { return ((a) < (x) && (x) < (b)); } template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; } template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) { return {a.first + b.first, a.second + b.second}; } template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) { return {a.first - b.first, a.second - b.second}; } template <typename T, typename U> ll sqabs(const pair<T, U> &a) { return square(a.first) + square(a.second); } template <typename T> vector<T> &sumvec(vector<T> &a) { ll b = a.size(); for (ll i = 1; i < b; i++) a[i] += a[i - 1]; return a; } template <typename T> vector<T> &vecin(vector<T> &a) { for(auto& x:a) cin >> x; return a; } template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; } template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; } template <typename T> T &RSORT(T &a) { SORT(a); REVERSE(a); return a; } template <typename T> ostream &operator<<(ostream &os, const vector<T> &a) { bool first = true; os << "{"; for (const T &x : a) { if (!first) os << ","; first = false; os << x; } os << "}"; return os; } template <typename T> ostream &operator<<(ostream &os, const set<T> &a) { bool first = true; os << "{"; for (const T &x : a) { if (!first) os << ","; first = false; os << x; } os << "}"; return os; } template <typename T> ostream &operator<<(ostream &os, const multiset<T> &a) { bool first = true; os << "{"; for (const T &x : a) { if (!first) os << ","; first = false; os << x; } os << "}"; return os; } template <typename T, typename U> T &IOTA(T &a, U b) { iota(a.begin(), a.end(), b); return a; }

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

void yesno(bool b){
    if(b) cout << "Yes" << el;
    if(!b) cout << "No" << el;
}

//i番目に小さい要素 fenwick tree で二分探索
//集合に入っている要素を1,そうでない要素を0で設定
//F.sum(0,i+1)がx <==> 0からiまでの要素のうち、集合に入っているものがx個ある

int main(){
    #ifdef pas4 
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////" << el;
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n,m; cin >> n >> m;
    vector<ll> A(n); vecin(A);
    vector<ll> C(m+1);
    rep(i,n) C[A[i]]++;
    fenwick_tree<ll> F(m+10);
    vector<vector<ll>> D(n+1);
    for(ll i = 1; i <= m; i++){
        if(C[i] == 0) F.set(i,1);
        else D[C[i]].push_back(i);
    }
    ll q; cin >> q;
    vector<pair<ll,ll>> X; //(x,idx)
    X.reserve(q);
    vector<ll> ans(q);
    rep(i,q){
        ll x;cin >> x;
        if(x <= n) ans[i] = A[x-1];
        else X.push_back(pair(x,i));
    }
    SORT(X);
    ll cnt = 0, len = n, plus = F.sum(0,m+1);
    ll l,r,mid,sum,k;
    for(auto [x,idx]:X){
        while(plus < m && len+plus < x){
            len += plus;
            cnt++;
            for(ll v:D[cnt]) F.set(v,1);
            plus = F.sum(0,m+1);
        }
        if(plus == m){
            k = (x-len+plus-1)/plus;
            len += (k-1)*plus;
            assert(range(len,x,len+plus+1));
            ans[idx] = x-len;
        }
        else{
            l = 0, r = m+1, mid = (m+1)/2;
            while(r-l > 1){
                sum = F.sum(0,mid+1);
                if(len+sum < x) l = mid;
                else if(x <= len+sum) r = mid;
                mid = (l+r)/2;
            }
            ans[idx] = r;
        }
    }
    rep(i,q) cout << ans[i] << el;
    
    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms" << el; cout << "//////////////////////////////////////////////////////" << el;
    #endif
}