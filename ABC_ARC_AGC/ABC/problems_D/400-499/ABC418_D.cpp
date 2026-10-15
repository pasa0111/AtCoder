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

using namespace std;
using ll = long long;
#define rep(i,e) for(ll i = 0; i < e; i++)
#define vecall(vec) vec.begin(),vec.end()
//#define vecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < sizesizesize; i++){cin >> vec[i];}
//#define sumvecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < sizesizesize; i++){cin >> vec[i]; if(i > 0) vec[i] += vec[i-1];}
//#define REVERSE(vec) reverse(vecall(vec))
//#define SORT(vec) sort(vecall(vec))
//#define RSORT(vec) SORT(vec); REVERSE(vec)
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
template <typename T>               vector<T>&  SORT(vector<T>& a){ll b = a.size(); sort(vecall(a)); return a;}
template <typename T>               vector<T>&  REVERSE(vector<T>& a){ll b = a.size(); reverse(vecall(a)); return a;}
template <typename T>               vector<T>&  RSORT(vector<T>& a){SORT(a); REVERSE(a); return a;}
template <typename T>               ostream&    operator<<(ostream& os, const vector<T>& a){ll sizesizesize = a.size(); os << "{"; os << a[0]; for(ll i = 1; i < sizesizesize; i++) os << "," << a[i]; os << "}"; return os;}
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
template <typename T, typename U>   PLqueue<T>& operator<<(PLqueue<T>& a, const U& b){a.push(b); return a;}
template <typename T>               void        operator--(PLqueue<T>& a, int){if(!a.empty())a.pop();}
template <typename T, typename U>   stack<T>&   operator<<(stack<T>& a, const U& b){a.push(b); return a;}
template <typename T>               void        operator--(stack<T>& a, int){if(!a.empty())a.pop();}
template <typename T>               istream&    operator>>(istream& is, vector<T>& a){T x; is >> x; a << x; return is;}
template <typename T>               istream&    operator>>(istream& is, set<T>& s){T x;is >> x; s.insert(x); return is;}


void yesno(bool b){
    if(b) cout << "Yes" << el;
    if(!b) cout << "No" << el;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    string T;
    cin >> n >> T;
    vector<ll> zero(n), even(n), odd(n);
    rep(i,n){
        if(T[i] == '0') zero[i]++;
        if(i > 0) zero[i] += zero[i-1];
    }
    //cout << zero << el;
    for(ll i = n-1; i >= 0; i--){
        if(zero[i]%2 == 0) even[i]++;
        if(zero[i]%2 == 1) odd[i]++;
        if(i < n-1){
            even[i] += even[i+1];
            odd[i] += odd[i+1];
        }
    }
    //cout << even << el;
    //cout << odd << el;
    ll ans = 0;
    rep(i,n){
        if(zero[i]%2 == 0){
            if(T[i] == '0') ans += odd[i];
            if(T[i] == '1') ans += even[i];
        }
        if(zero[i]%2 == 1){
            if(T[i] == '0') ans += even[i];
            if(T[i] == '1') ans += odd[i];
        }
    }
    cout << ans << el;
}