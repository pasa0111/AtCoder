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
    int h,w; cin >> h >> w;
    vector<string> S(h);
    vecin(S);
    vector<vector<vector<int>>> dp(h,vector<vector<int>>(w,vector<int>(2,inf)));
    //queue<tuple<int,int,int,bool>> will; //(歩数,x,y,直前の行動(0:縦, 1:横))
    queue<tuple<int,int,bool>> will;
    vector<ll> D = {-1,0,1,0}, E = {0,-1,0,1}, F = {-1,1};
    int dx,dy;
    rep(i,h)rep(j,w){
        if(S[i][j] == 'S'){
            rep(k,4){
                dx = D[k], dy = E[k];
                if(range(-1,i+dx,h) && range(-1,j+dy,w) && S[i+dx][j+dy] != '#'){
                    dp[i+dx][j+dy][k%2] = 1;
                    will << MT(i+dx,j+dy,k%2);
                }
            }
        }
    }
    ll ans = -1,cnt;
    while(will.size() > 0){
        auto [i,j,b] = will.front();
        will--;
        cnt = dp[i][j][b];
        if(S[i][j] == 'G'){
            ans = cnt;
            break;
        }
        if(b){
            rep(k,2){
                dx = F[k], dy = 0;
                if(range(-1,i+dx,h) && range(-1,j+dy,w) && S[i+dx][j+dy] != '#' && dp[i+dx][j+dy][0] > cnt+1){
                    dp[i+dx][j+dy][0] = cnt+1;
                    will << MT(i+dx,j+dy,0);
                }
            }
        }
        if(!b){
            rep(k,2){
                dx = 0, dy = F[k];
                if(range(-1,i+dx,h) && range(-1,j+dy,w) && S[i+dx][j+dy] != '#' && dp[i+dx][j+dy][1] > cnt+1){
                    dp[i+dx][j+dy][1] = cnt+1;
                    will << MT(i+dx,j+dy,1);
                }
            }
        }
    }
    cout << ans << el;
}