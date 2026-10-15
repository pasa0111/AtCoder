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

int main(){
    int n,Q;
    cin >> n >> Q;
    vector<int> front(n+1), back(n+1);
    rep(q,Q){
        //rep(i,n+1){cout << train.par[i] << " ";}
        //cout << endl;
        int t,x,y;
        cin >> t >> x;
        if(t == 1){
            cin >> y;
            front[y] = x;
            back[x] = y;
        }
        if(t == 2){
            cin >> y;
            back[x] = 0;
            front[y] = 0;
        }
        if(t == 3){
            vector<int> res;
            while(front[x] != 0){x = front[x];}
            res.push_back(x);
            while(back[x] != 0){
                res.push_back(back[x]);
                x = back[x];
            }
            cout << res.size() << " ";
            for(int i:res){cout << i << " ";}
            cout << endl;
        }
    }
}