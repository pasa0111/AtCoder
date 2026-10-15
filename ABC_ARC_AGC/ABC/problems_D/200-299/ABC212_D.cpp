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
    ll Q,p,x,latest = 0, add = 0;
    cin >> Q;
    priority_queue<ll, vector<ll>, greater<ll>> Ball;
    rep(q,Q){
        cin >> p;
        if(p == 1){
            cin >> x;
            Ball.push(x-add);
        }
        if(p == 2){
            cin >> x;
            latest = q;
            add += x;
        }
        if(p == 3){
            cout << Ball.top() + add << endl;
            Ball.pop();
        }
    }
}