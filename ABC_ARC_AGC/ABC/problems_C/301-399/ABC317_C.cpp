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

int ans = 0;

void go(int now, int cost, vector<vector<pair<int,int>>> &town, vector<bool> &visited){
    //cout << "now:" << now << "   cost:" << cost << endl;
    ans = max(cost,ans);
    for(pair<int,int> i:town[now]){
        if(!visited[i.first]){
            visited[i.first] = true;
            go(i.first,cost+i.second,town,visited);
            visited[i.first] = false;
        }
    }
    return;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> town(n+1); //(街iと繋がっている街の番号,時間)
    vector<int> time(n+1,-1); //ある街から出発して街iに来るまでにかかる時間の最大値
    int a,b,c;
    rep(i,m){
        cin >> a >> b >> c;
        town[a].push_back(MP(b,c));
        town[b].push_back(MP(a,c));
    }
    vector<bool> visited(n+1,false);
    for(int i = 1; i <= n; i++){
        visited[i] = true;
        go(i,0,town,visited);
        visited[i] = false;
    }
    cout << ans << endl;
}