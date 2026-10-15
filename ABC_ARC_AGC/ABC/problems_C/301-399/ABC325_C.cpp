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


//Union-Find
struct UnionFind {
    vector<int> par; //par[i] = iの親の番号, iが親なら -(その集合の頂点数)

    UnionFind(int n) : par(n, -1) {}

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

    //xとyが同じグループか判定
    bool same(int x, int y){
        return root(x) == root(y);
    }

    //xが含まれる集合の頂点数を返す
    int size(int x){
        return -par[root(x)];
    }
};

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int H,W;
    cin >> H >> W;
    vector<string> S(H);
    UnionFind sensor(H*W+1);
    vecin(S);
    rep(i,H){
        rep(j,W){
            if(S[i][j] == '#'){
                for(int p = -1; p <= 1; p++){
                    for(int q = -1; q <= 1; q++){
                        if((p != 0 || q != 0) && 0 <= i+p && i+p < H && 0 <= j+q && j+q < W && S[i+p][j+q] == '#'){
                            sensor.unite(W*i+j,W*(i+p)+j+q);
                        }
                    }
                }
            }
            if(S[i][j] == '.') sensor.par[W*i+j] = H*W;
        }
    }
    int ans = 0;
    for(int i = 0; i < H*W; i++){
        if(sensor.par[i] < 0) ans++;
    }
    cout << ans << endl;
}