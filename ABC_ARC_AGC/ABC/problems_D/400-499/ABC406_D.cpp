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
#define rep(i,n) for(ll i = 0; i < n; i++)
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
    map<int,set<int>> X; //x行目にあるゴミのy座標を保存
    map<int,set<int>> Y; //y列目にあるゴミのx座標を保存
    int h,w,n;
    cin >> h >> w >> n;
    rep(i,n){
        int x,y;
        cin >> x >> y;
        X[x].insert(y);
        Y[y].insert(x);
    }
    int Q;
    cin >> Q;
    rep(query,Q){
        int p,x,y;
        cin >> p;
        if(p == 1){
            cin >> x;
            cout << X[x].size() << endl;
            if(X[x].size() == 0) continue;
            for(int z:X[x]) Y[z].erase(x);
            X[x].clear();
            continue;
        }
        if(p == 2){
            cin >> y;
            cout << Y[y].size() << endl;
            if(Y[y].size() == 0) continue;
            for(int z:Y[y]) X[z].erase(y);
            Y[y].clear();
        }
    }
}