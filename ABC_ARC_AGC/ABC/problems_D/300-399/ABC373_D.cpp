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

int main(){
    ll n,m;
    cin >> n >> m;
    vector<pair<ll,bool>> graph(n+1,make_pair(0,true));
    vector<vector<pair<ll,ll>>> back(n+1), next(n+1);
    rep(i,m){
        ll u,v,w;
        cin >> u >> v >> w;
        back[v].push_back(MP(u,w));
        next[u].push_back(MP(v,w));
    }

    for(int i = 1; i <= n; i++){
        if(graph[i].second){
            graph[i].first = 0;
            graph[i].second = false;
            queue<ll> will;
            will.push(i);
            while(will.size() > 0){
                ll now = will.front();
                for(pair<ll,ll> n:next[now]){
                    if(!graph[n.first].second) continue;
                    graph[n.first].first = graph[now].first + n.second;
                    graph[n.first].second = false;
                    will.push(n.first);
                }
                for(pair<ll,ll> b:back[now]){
                    if(!graph[b.first].second) continue;
                    graph[b.first].first = graph[now].first - b.second;
                    graph[b.first].second = false;
                    will.push(b.first);
                }
                will.pop();
            }
        }
    }
    for(int i = 1; i <= n; i++) cout << graph[i].first << " ";
    cout << endl;
}