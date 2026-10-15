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
    int n;
    cin >> n;
    set<int> is_X;
    vector<int> X; //点が1個以上存在するx座標を保存
    map<int,set<int>> Y; //x座標がiである点のy座標を保存
    //vector<vector<int>> Grid(2001,vector<int>(2001));
    rep(i,n){
        int x,y;
        cin >> x >> y;
        if(!is_X.count(x)){
            X.push_back(x);
            is_X.insert(x);
        }
        Y[x].insert(y);
    }
    SORT(X);
    int ans = 0;
    for(int x = 0; x < X.size(); x++){
        for(int y:Y.at(X[x])){
            for(int z:Y.at(X[x])){
                if(y >= z) continue;
                for(int w = x+1; w < X.size(); w++){
                    if(Y.at(X[w]).count(y) && Y.at(X[w]).count(z)){
                        //cout << "x:(" << X[x] << "," << X[w] << ")    y:(" << y << "," << z << ")" << endl;
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}