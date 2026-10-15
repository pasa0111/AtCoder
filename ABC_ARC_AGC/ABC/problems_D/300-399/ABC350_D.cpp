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
    ll n,m;
    cin >> n >> m;
    UnionFind Friends(n);
    rep(i,m){
        ll a,b;
        cin >> a >> b;
        Friends.unite(a,b);
    }

    ll ans = -m;
    for(ll i = 1; i <= n; i++){
        if(Friends.par[i] < 0){
            ans += (ll)(-Friends.par[i])*(-Friends.par[i]-1)/2;
        }
    }
    cout << ans << endl;
}