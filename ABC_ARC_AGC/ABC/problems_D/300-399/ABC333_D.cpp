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
#define SORT(vec) sort(vecall(vec));
#define RSORT(vec) SORT(vec);reverse(vecall(vec));
#define MP make_pair

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

vector<bool> sorted(300001,false);
vector<vector<int>> graph(300001);
vector<int> num(300001,0); //その頂点を消す前に消さなければならない頂点数
int ans = 5e5, res = 0;

void dfs(int now, int back){
    //cout << "now:" << now << "   res:" << res << endl;
    if(graph[now].size() == 1) return;
    if(!sorted[now]){
        RSORT(graph[now]);
        sorted[now] = true;
    }
    for(int i = 0; i < graph[now].size(); i++){
        int next = graph[now][i];
        if(next == 1){
            num[now] = res;
            res = 0;
            break;
        }
        if(next == back){
            continue;
        }
        res++;
        dfs(next,now);
    }
    return;
}


int main(){
    int n;
    cin >> n;
    rep(i,n-1){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int sum = 0, M = 0;
    //for(int i:graph[3]) cout << i << " ";
    //cout << endl;
    dfs(3,-1);
    for(int x:graph[1]){
        res = 0;
        dfs(x,-1);
        sum += num[x]+1;
        M = max(M,num[x]+1);
    }
    //cout << "num[3] = " << num[3] << endl;
    //cout << "num[2] = " << num[2] << endl;
    cout << sum-M+1 << endl;
}