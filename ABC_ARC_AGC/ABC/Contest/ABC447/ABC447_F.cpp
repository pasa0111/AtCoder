#pragma region my_template
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
using namespace std; using ll = long long; using ull = unsigned long long; using ld = long double; constexpr char el = '\n'; [[maybe_unused]] constexpr ll inf = 2000000000; [[maybe_unused]]constexpr ll INF = 9000000000000000000;
#define rep(i,j) for(ll i = 0, jjjjj = (j); i < jjjjj; i++)
#define vecall(vec) vec.begin(),vec.end()
template <typename T> using PLqueue = priority_queue<T>; template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>; template <typename T> T square(T a){return a*a;} template <typename T, typename U, typename V> bool range(T a,U x,V b){return ((a) < (x) && (x) < (b));} template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p){os << "(" << p.first << ", " << p.second << ")";return os;} template <typename T, typename U> pair<T, U> operator+(const pair<T, U>& a, const pair<T, U>& b){return {a.first + b.first, a.second + b.second};} template <typename T, typename U> pair<T, U> operator-(const pair<T, U>& a, const pair<T, U>& b){return {a.first - b.first, a.second - b.second};} template <typename T, typename U> ll sqabs(const pair<T, U>& a){return square(a.first)+square(a.second);} template <typename T> vector<T>& sumvec(vector<T>& a){ll b = a.size(); for(ll i = 1; i < b; i++)a[i] += a[i-1]; return a;}template <typename T> vector<T>& vecin(vector<T>& a){ll b = a.size(); rep(i,b)cin >> a[i]; return a;} template <typename T> vector<T>& SORT(vector<T>& a){sort(a.begin(), a.end()); return a;} template <typename T> T& REVERSE(T& a){reverse(a.begin(), a.end()); return a;} template <typename T> vector<T>& RSORT(vector<T>& a){SORT(a); REVERSE(a); return a;} template <typename T> ostream& operator<<(ostream& os, const vector<T>& a){bool first = true; os << "{"; for(const T& x:a){if(!first)os << ","; first = false; os << x;} os << "}"; return os;} template <typename T> ostream& operator<<(ostream& os, const set<T>& a){bool first = true; os << "{"; for(const T& x:a){if(!first)os << ","; first = false; os << x;} os << "}"; return os;} template <typename T> ostream& operator<<(ostream& os, const multiset<T>& a){bool first = true; os << "{"; for(const T& x:a){if(!first)os << ","; first = false; os << x;} os << "}"; return os;} template <typename T, typename U> T& IOTA(T& a, U b){iota(a.begin(),a.end(),b); return a;}
#pragma endregion

void yesno(bool b){
    if(b) cout << "Yes" << el;
    if(!b) cout << "No" << el;
}

vector<bool> visited;
vector<vector<ll>> G;
vector<ll> I;
vector<ll> D;
ll ans = 1;
void dfs(ll now, ll cnt){
    if(I[now] >= 3) ans = max(ans,cnt);
    if(I[now] <= 3) return;
    for(ll to:G[now]){
        if(D[to] > D[now]){
            visited[to] = true;
            dfs(to,cnt+1);
        }
    }
}

int main(){
    #ifdef pas4 
        freopen("/Users/Shared/input.txt", "r", stdin); auto aaaa = chrono::high_resolution_clock::now(); cout << "//////////////////////////////////////////////////////" << el;
    #endif
    ios::sync_with_stdio(false); cin.tie(nullptr);
    //////////////////////////////////////////
    ll q; cin >> q;
    rep(query,q){
        ll n; cin >> n;
        ans = 1;
        G = vector<vector<ll>>(n), I = vector<ll>(n), visited = vector<bool>(n,false), D = vector<ll>(n,-1);
        rep(i,n-1){
            ll a,b; cin >> a >> b; a--,b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        ll oya = -1;
        rep(i,n){
            I[i] = G[i].size();
            if(oya == -1 && I[i] < 3) oya = i;
        }
        queue<ll> bfs;
        D[oya] = 0;
        bfs.push(oya);
        while(!bfs.empty()){
            ll now = bfs.front();
            bfs.pop();
            for(ll to:G[now]){
                if(D[to] == -1){
                    D[to] = D[now]+1;
                    bfs.push(to);
                }
            }
        }
        bfs.push(oya);
        visited[oya] = true;
        while(!bfs.empty()){
            ll now = bfs.front();
            bfs.pop();
            for(ll to:G[now]){
                if(D[to] <= D[now]) continue;
                if(I[now] >= 3 && !visited[to]){
                    visited[to] = true;
                    dfs(to,2);
                }
                bfs.push(to);
            }
        }
        cout << ans << el;
    }
    //////////////////////////////////////////
    #ifdef pas4
        auto bbbb = chrono::high_resolution_clock::now(); auto cccc = chrono::duration_cast<chrono::milliseconds>(bbbb - aaaa).count(); cout << "Exec Time: " << cccc << "ms" << el; cout << "//////////////////////////////////////////////////////" << el;
    #endif
}