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
#include <random>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define rep(i,j) for(ll i = 0, jjjjjjjjjj = (j); i < jjjjjjjjjj; i++)
#define vecall(vec) vec.begin(),vec.end()
constexpr char el = '\n';
[[maybe_unused]] constexpr ll inf = 2000000000;
[[maybe_unused]] constexpr ll INF = 9000000000000000000;

template <typename T> using PLqueue = priority_queue<T>;
template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>;
template <typename T>               T            square(T a){return a*a;}
template <typename T, typename U, typename V> bool range(T a,U x,V b){return ((a) < (x) && (x) < (b));}
template <typename T, typename U>   ostream&     operator<<(ostream& os, const pair<T, U>& p){os << "(" << p.first << ", " << p.second << ")";return os;}
template <typename T, typename U>   pair<T, U>   operator+(const pair<T, U>& a, const pair<T, U>& b){return {a.first + b.first, a.second + b.second};}
template <typename T, typename U>   pair<T, U>   operator-(const pair<T, U>& a, const pair<T, U>& b){return {a.first - b.first, a.second - b.second};}
template <typename T, typename U>   ll           abs(const pair<T, U>& a){return square(a.first)+square(a.second);}
template <typename T, typename U>   vector<T>&   operator+=(vector<T>& a, const U& b){a.push_back(b); return a;}
template <typename T>               void         operator--(vector<T>& a, int){if(!a.empty())a.pop_back();}
template <typename T>               vector<T>&   sumvec(vector<T>& a){ll b = a.size(); for(ll i = 1; i < b; i++)a[i] += a[i-1]; return a;}
template <typename T>               vector<T>&   vecin(vector<T>& a){ll b = a.size(); rep(i,b)cin >> a[i]; return a;}
template <typename T>               vector<T>&   SORT(vector<T>& a){sort(a.begin(), a.end()); return a;}
template <typename T>               T&           REVERSE(T& a){reverse(a.begin(), a.end()); return a;}
template <typename T>               vector<T>&   RSORT(vector<T>& a){SORT(a); REVERSE(a); return a;}
template <typename T>               ostream&     operator<<(ostream& os, const vector<T>& a){bool first = true; os << "{"; for(const T& x:a){if(!first)os << ","; first = false; os << x;} os << "}"; return os;}
template <typename T, typename U>   set<T>&      operator+=(set<T>& a, const U& b){a.insert(b); return a;}
template <typename T, typename U>   set<T>&      operator-=(set<T>& a, const U& b){a.erase(b); return a;}
template <typename T>               ostream&     operator<<(ostream& os, const set<T>& a){bool first = true; os << "{"; for(const T& x:a){if(!first)os << ","; first = false; os << x;} os << "}"; return os;}
template <typename T>               T            min(set<T>& a){return *a.begin();}
template <typename T>               T            max(set<T>& a){return *a.rbegin();}
template <typename T, typename U>   multiset<T>& operator+=(multiset<T>& a, const U& b){a.insert(b); return a;}
template <typename T>               T            min(multiset<T>& a){return *a.begin();}
template <typename T>               T            max(multiset<T>& a){return *a.rbegin();}
template <typename T>               ostream&     operator<<(ostream& os, const multiset<T>& a){bool first = true; os << "{"; for(const T& x:a){if(!first)os << ","; first = false; os << x;} os << "}"; return os;}
template <typename T, typename U>   queue<T>&    operator+=(queue<T>& a, const U& b){a.push(b); return a;}
template <typename T>               void         operator--(queue<T>& a, int){if(!a.empty())a.pop();}
template <typename T>               ostream&     operator<<(ostream& os, queue<T> a){bool first = true; os << "{"; while(!a.empty()){if(!first)os << ","; first = false; os << a.front(); a--;} os << "}"; return os;}
template <typename T, typename U>   PGqueue<T>&  operator+=(PGqueue<T>& a, const U& b){a.push(b); return a;}
template <typename T>               void         operator--(PGqueue<T>& a, int){if(!a.empty())a.pop();}
template <typename T>               ostream&     operator<<(ostream& os, PGqueue<T> a){bool first = true; os << "{"; while(!a.empty()){if(!first)os << ","; first = false; os << min(a); a--;} os << "}"; return os;}
template <typename T, typename U>   PLqueue<T>&  operator+=(PLqueue<T>& a, const U& b){a.push(b); return a;}
template <typename T>               void         operator--(PLqueue<T>& a, int){if(!a.empty())a.pop();}
template <typename T>               ostream&     operator<<(ostream& os, PLqueue<T> a){bool first = true; os << "{"; while(!a.empty()){if(!first)os << ","; first = false; os << max(a); a--;} os << "}"; return os;}
template <typename T, typename U>   stack<T>&    operator+=(stack<T>& a, const U& b){a.push(b); return a;}
template <typename T>               void         operator--(stack<T>& a, int){if(!a.empty())a.pop();}
template <typename T>               ostream&     operator<<(ostream& os, stack<T> a){bool first = true; os << "{"; while(!a.empty()){if(!first)os << ","; first = false; os << a.top(); a--;} os << "}"; return os;}
template <typename T, typename U>   T&           IOTA(T& a, U b){iota(a.begin(),a.end(),b); return a;}
template <typename T, typename U>   auto         Lbound(const vector<T>& a, const U& b){return lower_bound(a.begin(),a.end(),b);}
template <typename T, typename U>   auto         Ubound(const vector<T>& a, const U& b){return upper_bound(a.begin(),a.end(),b);}
template <typename T, typename U>   auto         Lbound(const set<T>& a, const U& b){return a.lower_bound(b);}
template <typename T, typename U>   auto         Ubound(const set<T>& a, const U& b){return a.upper_bound(b);}
template <typename T, typename U>   auto         Lbound(const multiset<T>& a, const U& b){return a.lower_bound(b);}
template <typename T, typename U>   auto         Ubound(const multiset<T>& a, const U& b){return a.upper_bound(b);}


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


/*
行列(数列)　入れ替え　転倒数
*/


void yesno(bool b){
    if(b) cout << "Yes" << el;
    if(!b) cout << "No" << el;
}

int main(){
    #ifdef pas4
        freopen("/Users/Shared/input.txt", "r", stdin);
        auto timestart = chrono::high_resolution_clock::now();
        cout << "//////////////////////////////////////////////////////" << el;
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //////////////////////////////////////////
    ll n; cin >> n;
    vector<ll> R(n), C(n);
    rep(i,n)rep(j,n){
        ll p; cin >> p;
        if(p != 0){
            R[i] = p;
            C[j] = p;
        }
    }
    fenwick_tree<ll> outen(n+2);
    ll ans = 0;
    rep(i,n){
        ans += outen.sum(R[i],n+2);
        outen.set(R[i],1);
    }
    outen = fenwick_tree<ll>(n+2);
    rep(i,n){
        ans += outen.sum(C[i],n+2);
        outen.set(C[i],1);
    }
    cout << ans << el;
    //////////////////////////////////////////
    #ifdef pas4
        auto timeend = chrono::high_resolution_clock::now();
        auto timeduration = chrono::duration_cast<chrono::milliseconds>(timeend - timestart).count();
        cout << "Exec Time: " << timeduration << "ms" << el;
        cout << "//////////////////////////////////////////////////////" << el;
    #endif
}