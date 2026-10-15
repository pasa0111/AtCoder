#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <cctype>
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
using namespace std;
using ll = long long;
#define rep(i,e) for(ll i = 0; i < e; i++)
#define vecall(vec) vec.begin(),vec.end()
#define MP make_pair
#define MT make_tuple
#define el '\n'
#define inf 2147483647
#define INF 9223372036854775807
#define range(a,x,b) ((a) < (x) && (x) < (b))

template <typename T> using PLqueue = priority_queue<T>;
template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>;
template <typename T, typename U>   ostream&    operator<<(ostream& os, const pair<T, U>& p){os << "(" << p.first << ", " << p.second << ")";return os;}
template <typename T, typename U>   pair<T, U>  operator+(const pair<T, U>& l, const pair<T, U>& r){return {l.first + r.first, l.second + r.second};}
template <typename T, typename U>   pair<T, U>  operator-(const pair<T, U>& l, const pair<T, U>& r){return {l.first - r.first, l.second - r.second};}
template <typename T, typename U>   vector<T>&  operator<<(vector<T>& a, const U& b){a.push_back(b); return a;}
template <typename T>               void        operator--(vector<T>& a, int){if(!a.empty())a.pop_back();}
template <typename T>               vector<T>&  sumvec(vector<T>& a){ll b = a.size(); for(ll i = 1; i < b; i++)a[i] += a[i-1]; return a;}
template <typename T>               vector<T>&  vecin(vector<T>& a){ll b = a.size(); rep(i,b)cin >> a[i]; return a;}
template <typename T>               T&          SORT(T& a){ll b = a.size(); sort(vecall(a)); return a;}
template <typename T>               T&          REVERSE(T& a){ll b = a.size(); reverse(vecall(a)); return a;}
template <typename T>               vector<T>&  RSORT(vector<T>& a){SORT(a); REVERSE(a); return a;}
template <typename T>               ostream&    operator<<(ostream& os, const vector<T>& a){ll sizesizesize = a.size(); os << "{"; os << a[0]; for(ll i = 1; i < sizesizesize; i++) os << ", " << a[i]; os << "}"; return os;}
template <typename T, typename U>   set<T>&     operator<<(set<T>& a, const U& b){a.insert(b); return a;}
template <typename T, typename U>   set<T>&     operator-=(set<T>& a, const U& b){a.erase(b); return a;}
template <typename T>               ostream&    operator<<(ostream& os, const set<T>& a){bool first = true; for(const T& x:a){if(!first)os << "," << x; if(first)os << "{" << x; first = false;} os << "}"; return os;}
template <typename T>               T           min(set<T>& a){return *a.begin();}
template <typename T>               T           max(set<T>& a){return *a.rbegin();}
template <typename T, typename U>   queue<T>&   operator<<(queue<T>& a, const U& b){a.push(b); return a;}
template <typename T>               void        operator--(queue<T>& a, int){if(!a.empty())a.pop();}
template <typename T>               ostream&    operator<<(ostream& os, const queue<T>& a){bool first = true; for(const T& x:a){if(!first)os << "," << x; if(first)os << "{" << x; first = false;} os << "}"; return os;}
template <typename T, typename U>   PGqueue<T>& operator<<(PGqueue<T>& a, const U& b){a.push(b); return a;}
template <typename T>               void        operator--(PGqueue<T>& a, int){if(!a.empty())a.pop();}
template <typename T>               T           min(PGqueue<T>& a){return a.top();}
template <typename T, typename U>   PLqueue<T>& operator<<(PLqueue<T>& a, const U& b){a.push(b); return a;}
template <typename T>               void        operator--(PLqueue<T>& a, int){if(!a.empty())a.pop();}
template <typename T>               T           max(PLqueue<T>& a){return a.top();}
template <typename T, typename U>   stack<T>&   operator<<(stack<T>& a, const U& b){a.push(b); return a;}
template <typename T>               void        operator--(stack<T>& a, int){if(!a.empty())a.pop();}
template <typename T>               istream&    operator>>(istream& is, vector<T>& a){T x; is >> x; a.push_back(x); return is;}
template <typename T>               istream&    operator>>(istream& is, set<T>& s){T x; is >> x; s.insert(x); return is;}
template <typename T>               istream&    operator>>(istream& is, stack<T>& s){T x; is >> x; s.push(x); return is;}
template <typename T>               istream&    operator>>(istream& is, multiset<T>& s){T x; is >> x; s.insert(x); return is;}
template <typename T>               T           sq(T& a){return a*a;}
template <typename T>               ostream&    operator<<(ostream& os, const multiset<T>& a){bool first = true; for(const T& x:a){if(!first)os << "," << x; if(first)os << "{" << x; first = false;} os << "}"; return os;}

void yesno(bool b){
    if(b) cout << "Yes" << el;
    if(!b) cout << "No" << el;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll h,w; cin >> h >> w;
    vector<string> S(h);
    vecin(S);
    mint ans = 1;
    ll r = 0, b = 0, c = 0;
    rep(k,h+w-1){
        r = 0, b = 0, c = 0;
        rep(i,min(k+1,h)){
            if(!range(-1,k-i,w)) continue;
            if(S[i][k-i] == 'R') r++;
            if(S[i][k-i] == 'B') b++;
            if(S[i][k-i] == '.') c++;
        }
        if(r > 0 && b > 0) ans = 0;
        if(r == 0 && b == 0) ans *= 2;
    }
    cout << ans.val() << el;
 }