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


using namespace std;
#define ll long long
#define rep(i,e) for(ll i = 0; i < e; i++)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(unsigned ll i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}
#define SORT(vec) sort(vecall(vec))
#define RSORT(vec) SORT(vec);reverse(vecall(vec));
#define MP make_pair

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

vector<bool> visited(11,false);
bitset<62> ans = 1LL << 60;
vector<vector<pair<int,bitset<62>>>> adj(11);
int n;

void solve(int now, bitset<62> cost){
    visited[now] = true;
    if(now == n) ans = min(ans.to_ullong(),cost.to_ullong());
    for(auto go:adj[now]){
        if(!visited[go.first]){
            solve(go.first,cost^go.second);
        }
    }
    visited[now] = false;
    return;
}

int main(){
    int m;
    cin >> n >> m;
    rep(i,m){
        ll u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back(MP(v,bitset<62>(w)));
        adj[v].push_back(MP(u,bitset<62>(w)));
    }
    solve(1,bitset<62>(0));
    cout << ans.to_ullong() << endl;
}