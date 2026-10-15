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


using namespace std;
#define ll long long
#define rep(i,e) for(ll i = 0; i < e; i++)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(ll i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}
#define sumvecin(vec) for(ll i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i); if(i > 0) vec[i] += vec[i-1];}
#define SORT(vec) sort(vecall(vec))
#define RSORT(vec) SORT(vec);reverse(vecall(vec));
#define MP make_pair
#define MT make_tuple

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}


struct UnionFind {
    vector<int> par; //par[i] = iの親の番号, iが親なら -(その集合の頂点数)

    UnionFind(int n) : par(n+1, -1) {}

    //xの親の番号を返す
    int root(int x){
        if (par[x] < 0) return x;
        return par[x] = root(par[x]);
    }

    //頂点xと頂点yが含まれる集合を合体させる
    void unite(int x, int y){
        x = root(x);
        y = root(y);
        if (x == y) return;

        if (par[x] > par[y]){swap(x, y);}
        
        par[x] += par[y];
        par[y] = x;
        return;
    }

    //xとyが同じグループか判定する
    bool same(int x, int y){
        return root(x) == root(y);
    }

    //xが含まれる集合の頂点数を返す
    int size(int x){
        return -par[root(x)];
    }
};

int main(){
    int n,m;
    cin >> n >> m;
    bool ans = true;
    vector<vector<int>> person(n+1);
    UnionFind graph(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        person[a].push_back(b);
        person[b].push_back(a);
        if(graph.same(a,b) || person[a].size() > 2 || person[b].size() > 2) ans = false;
        graph.unite(a,b);
    }
    yesno(ans);
}