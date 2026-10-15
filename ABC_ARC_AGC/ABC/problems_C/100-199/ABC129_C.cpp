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

ll f(ll k, vector<ll> &stair){
    if(stair[k] == -1){
        stair[k] = f(k-1,stair) + f(k-2,stair);
    }
    stair[k] %= 1000000007;
    return stair[k];
}

int main(){
    ll n,m;
    cin >> n >> m;
    vector<ll> stair(n+1,-1);
    stair[0] = 1;
    stair[1] = 1;
    rep(i,m){
        ll a;
        cin >> a;
        stair[a] = 0;
    }
    cout << f(n,stair) << endl;
}