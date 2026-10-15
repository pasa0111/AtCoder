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
/*
#include <atcoder/all>
using namespace atcoder;
*/
using namespace std;
#define ll long long
#define rep(i,e) for(ll i = 0; i < e; i++)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < sizesizesize; i++){cin >> vec.at(i);}
#define sumvecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < sizesizesize; i++){cin >> vec.at(i); if(i > 0) vec[i] += vec[i-1];}
#define REVERSE(vec) reverse(vecall(vec))
#define SORT(vec) sort(vecall(vec))
#define RSORT(vec) SORT(vec); REVERSE(vec)
#define MP make_pair
#define MT make_tuple
#define range(a,x,b) ((a) < (x) && (x) < (b))
#define inf 2147483647;
#define INF 9223372036854775807;
#define el '\n';

template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p){os << "(" << p.first << ", " << p.second << ")";return os;}
template <typename T, typename U> pair<T, U> operator+(const pair<T, U>& l, const pair<T, U>& r){return {l.first + r.first, l.second + r.second};}
template <typename T, typename U> vector<T>& operator<<(vector<T>& a, const T& b){a.push_back(b); return a;}
template <typename T, typename U> set<T>& operator<<(set<T>& a, const U& b){a.insert(b); return a;}
template <typename T, typename U> queue<T>& operator<<(queue<T>& a, const U& b){a.push(b); return a;}
template <typename T, typename U> priority_queue<T, vector<T>, greater<T>>& operator<<(priority_queue<T, vector<T>, greater<T>>& a, const U& b){a.push(b); return a;}
template <typename T, typename U> stack<T>& operator<<(stack<T>& a, const U& b){a.push(b); return a;}



/*
g++acl path -o a.out && ./a.out < ./input.txt
g++ path -o a.out && ./a.out < ./input.txt
*/


void yesno(bool b){
    if(b) cout << "Yes" << el;
    if(!b) cout << "No" << el;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll h,w;
    cin >> h >> w;
    vector<string> maze(h), S(h);
    map<char,set<pair<ll,ll>>> tp;
    map<char,bool> ok;
    vecin(maze);
    S = maze;
    rep(i, h){
        rep(j, w){
            if (maze[i][j] != '.' && maze[i][j] != '#'){
                tp[maze[i][j]] << MP(i,j);
                ok[maze[i][j]] = true;
            }
        }
    }
    queue<tuple<ll,ll,ll>> will;
    will << MT(0,0,0);
    ll ans = -1;
    maze[0][0] = '#';
    vector<ll> DX = {-1,1,0,0}, DY = {0,0,-1,1};
    while(will.size() > 0){
        auto [cnt,x,y] = will.front();
        if(x == h-1 && y == w-1){
            ans = cnt;
            break;
        }
        will.pop();
        rep(i,4){
            ll dx = DX[i], dy = DY[i];
            if(range(-1,x+dx,h) && range(-1,y+dy,w) && maze[x+dx][y+dy] != '#'){
                maze[x+dx][y+dy] = '#';
                will << MT(cnt+1,x+dx,y+dy);
            }
        }
        if(S[x][y] != '.' && S[x][y] != '#'){
            if(ok[S[x][y]]){
                ok[S[x][y]] = false;
                for(auto next : tp[S[x][y]]){
                    if(maze[next.first][next.second] != '#'){
                        maze[next.first][next.second] = '#';
                        will << MT(cnt + 1, next.first, next.second);
                    }
                }
            }
        }
    }
    cout << ans << el;
}