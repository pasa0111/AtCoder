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
#include <chrono>
#include <cassert>
#include <numeric>
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using namespace std;
using ll = long long;
#define rep(i,e) for(ll i = 0, eeeeeee = (e); i < eeeeeee; i++)
#define vecall(vec) vec.begin(),vec.end()
#define MP make_pair
#define MT make_tuple
#define el '\n'
[[maybe_unused]] const ll inf = 2000000000;
[[maybe_unused]] const ll INF = 9000000000000000000;

template <typename T> using PLqueue = priority_queue<T>;
template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>;
template <typename T>               T            square(T a){return a*a;}
template <typename T>               bool         range(T a,T x,T b){return ((a) < (x) && (x) < (b));}
template <typename T, typename U>   ostream&     operator<<(ostream& os, const pair<T, U>& p){os << "(" << p.first << ", " << p.second << ")";return os;}
template <typename T, typename U>   pair<T, U>   operator+(const pair<T, U>& a, const pair<T, U>& b){return {a.first + b.first, a.second + b.second};}
template <typename T, typename U>   pair<T, U>   operator-(const pair<T, U>& a, const pair<T, U>& b){return {a.first - b.first, a.second - b.second};}
template <typename T, typename U>   pair<U,T>    pairswap(const pair<T,U>& a){return MP(a.second,a.first);}
template <typename T, typename U>   ll           abs(const pair<T, U>& a){return square(a.first)+square(a.second);}
template <typename T, typename U>   vector<T>&   operator+=(vector<T>& a, const U& b){a.push_back(b); return a;}
template <typename T>               void         operator--(vector<T>& a, int){if(!a.empty())a.pop_back();}
template <typename T>               vector<T>&   sumvec(vector<T>& a){ll b = a.size(); for(ll i = 1; i < b; i++)a[i] += a[i-1]; return a;}
template <typename T>               vector<T>&   vecin(vector<T>& a){ll b = a.size(); rep(i,b)cin >> a[i]; return a;}
template <typename T>               vector<T>&   SORT(vector<T>& a){sort(vecall(a)); return a;}
template <typename T>               T&           REVERSE(T& a){reverse(vecall(a)); return a;}
template <typename T>               vector<T>&   RSORT(vector<T>& a){SORT(a); REVERSE(a); return a;}
template <typename T>               istream&     operator>>(istream& is, vector<T>& a){T x; is >> x; a += x; return is;}
template <typename T>               ostream&     operator<<(ostream& os, const vector<T>& a){bool first = true; os << "{"; for(const T& x:a){if(!first)os << ","; first = false; os << x;} os << "}"; return os;}
template <typename T, typename U>   set<T>&      operator+=(set<T>& a, const U& b){a.insert(b); return a;}
template <typename T, typename U>   set<T>&      operator-=(set<T>& a, const U& b){a.erase(b); return a;}
template <typename T>               istream&     operator>>(istream& is, set<T>& s){T x; is >> x; s += x; return is;}
template <typename T>               ostream&     operator<<(ostream& os, const set<T>& a){bool first = true; for(const T& x:a){if(!first)os << "," << x; if(first)os << "{" << x; first = false;} os << "}"; return os;}
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

void yesno(bool b){
    if(b) cout << "Yes" << el;
    if(!b) cout << "No" << el;
}

bool isprime(ll x){
    bool res = true;
    for(ll i = 2; i <= sqrt(x); i++){
        if(x%i == 0 && x != i) res = false;
    }
    return res;
}

//x!にyが何個含まれるか
ll f(ll x,ll y){
    ll z = y, res = 0;
    while(x/z > 0){
        res += x/z;
        z *= y;
    }
    return res;
}

int main(){
    #ifdef pas4
        auto timestart = chrono::high_resolution_clock::now();
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ////////////////////////////////
    ll k; cin >> k;
    vector<pair<ll,ll>> P; //(素数,指数)
    if(isprime(k)){
        cout << k << el;
        return 0;
    }
    ll copy = k;
    for(ll i = 2; i <= copy+1; i++){
        ll q = 0;
        while(copy % i == 0){
            q++;
            copy /= i;
        }
        if(q != 0){
            P += MP(i,q);
            if(copy > 1 && isprime(copy)){
                P += MP(copy,1);
                break;
            }
        }
    }
    ll start = 0, end = k+1, t = (k+1)/2, ans = 2;
    for(auto p:P){
        auto [a,b] = p;
        start = ans-1;
        end = k+1;
        t = (start+end)/2;
        while(end-start > 1){
            ll F = f(t,a);
            if(F >= b) end = t;
            if(F < b) start = t;
            t = (start+end)/2;
        }
        ans = max(ans,end);
    }
    cout << ans << el;
    ////////////////////////////////
    #ifdef pas4
        auto timeend = chrono::high_resolution_clock::now();
        auto timeduration = chrono::duration_cast<chrono::milliseconds>(timeend - timestart).count();
        cout << "Exec Time: " << timeduration << "ms" << el;
    #endif
}