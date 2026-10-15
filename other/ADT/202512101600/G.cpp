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
#define vecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < sizesizesize; i++){cin >> vec.at(i);}
#define sumvecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < sizesizesize; i++){cin >> vec.at(i); if(i > 0) vec[i] += vec[i-1];}
#define SORT(vec) sort(vecall(vec))
#define RSORT(vec) SORT(vec);reverse(vecall(vec));
#define MP make_pair
#define MT make_tuple

template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p){os << "(" << p.first << ", " << p.second << ")";return os;}
template <typename T, typename U> pair<T, U> operator+(const pair<T, U> & l, const pair<T, U> & r){return {l.first + r.first, l.second + r.second};}


/*
g++ path -o a.out && ./a.out < ./input.txt
*/

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

struct UnionFind {
    vector<int> par; //par[i] = iの親の番号, iが親なら -(その集合の頂点数)
    vector<pair<int,int>> num;
    UnionFind(int n) : par(n+1, -1), num(n+1, MP(0,0)) {}

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

int main(){
    int n,m;
    cin >> n >> m;
    UnionFind uf(n);
    vector<vector<int>> graph(n+1);
    vector<bool> ok(n+1,true);
    vector<int> color(n+1,-1);
    int u,v;
    rep(i,m){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        uf.unite(u,v);
    }
    queue<pair<int,bool>> will;
    set<int> oya;
    int sum = 0;
    for(int i = 1; i < n+1; i++){
        if(uf.par[i] < 0){
            will.push(MP(i,0));
            color[i] = 0;
            uf.num[i].first++;
            while(will.size() > 0){
                int now = will.front().first;
                int c = will.front().second;
                will.pop();
                for(int next:graph[now]){
                    if(color[next] == c){
                        ok[i] = false;
                        will = {};
                        break;
                    }
                    if(color[next] == -1){
                        if(c == 0){
                            will.push(MP(next,1));
                            color[next] = 1;
                            uf.num[i].second++;
                        }
                        if(c == 1){
                            will.push(MP(next,0));
                            color[next] = 0;
                            uf.num[i].first++;
                        }
                    }
                }
            }
            if(ok[i]){
                oya.insert(i);
                sum += uf.size(i);
            }
        }
    }
    ll ans = 0;
    cout << sum << endl;
    //for(int i:oya)ans += uf.size(i)*(sum-uf.size(i)) + uf.num.first*uf.num.second;
    cout << ans << endl;
}