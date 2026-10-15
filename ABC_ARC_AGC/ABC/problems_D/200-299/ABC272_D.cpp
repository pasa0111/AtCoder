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
#define el '\n'
#define inf 2147483647
#define INF 9223372036854775807
#define range(a,x,b) ((a) < (x) && (x) < (b))

template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p){os << "(" << p.first << ", " << p.second << ")";return os;}
template <typename T, typename U> pair<T, U> operator+(const pair<T, U>& l, const pair<T, U>& r){return {l.first + r.first, l.second + r.second};}
template <typename T, typename U> vector<T>& operator<<(vector<T>& a, const U& b){a.push_back(b); return a;}
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
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> ans(n,vector<ll>(n,-1));
    queue<pair<ll,ll>> will;
    vector<ll> DX, DY;

    for(ll x = -sqrt(m); x < sqrt(m+1); x++){
        for(ll y = -sqrt(m); y < sqrt(m+1); y++){
            if(x*x+y*y == m){
                DX << x; DY << y;
            }
        }
    }

    ll dx,dy,k = DX.size();
    ans[0][0] = 0;
    will << MP(0,0);
    while(will.size() > 0){
        auto [x,y] = will.front();
        will.pop();
        rep(i,k){
            dx = DX[i], dy = DY[i];
            if(range(-1,x+dx,n) && range(-1,y+dy,n) && ans[x+dx][y+dy] == -1){
                ans[x+dx][y+dy] = ans[x][y]+1;
                will << MP(x+dx,y+dy);
            }
        }
    }
    rep(i,n){
        rep(j,n){
            cout << ans[i][j] << " ";
        }
        cout << el;
    }
}