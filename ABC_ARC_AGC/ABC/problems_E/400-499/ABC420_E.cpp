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


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

//Union-Find
struct UnionFind {
    vector<int> par; //par[i] = iの親の番号, iが親なら -(その集合の頂点数)
    vector<int> black_num; //親がiである集合に含まれる黒い頂点の数

    UnionFind(int n) : par(n+1, -1), black_num(n+1,0) {}

    //xの親の番号を返す
    int root(int x) {
        if (par[x] < 0) return x;
        return par[x] = root(par[x]);
    }

    //頂点xと頂点yが含まれる集合を合体させる
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y){return;}

        if (par[x] > par[y]){swap(x, y);}
        
        par[x] += par[y];
        black_num[x] += black_num[y];
        par[y] = x;
        return;
    }

    //頂点xと頂点yが同じグループか判定
    bool same(int x, int y) {
        return root(x) == root(y);
    }

    //頂点xが含まれる集合の頂点数を返す
    int size(int x) {
        return -par[root(x)];
    }
};

int main(){
    int n,Q;
    cin >> n >> Q;
    UnionFind V(n);
    vector<int> color(n+1);
    rep(q,Q){
        int x,u,v;
        cin >> x;
        if(x == 1){
            cin >> u >> v;
            V.unite(u,v);
        }
        if(x == 2){
            cin >> v;
            if(color[v] == 0){
                V.black_num[V.root(v)]++;
                color[v]++;
                continue;
            }
            if(color[v] == 1){
                V.black_num[V.root(v)]--;
                color[v]--;
            }
        }
        if(x == 3){
            cin >> v;
            yesno(V.black_num[V.root(v)] > 0);
        }
    }
}