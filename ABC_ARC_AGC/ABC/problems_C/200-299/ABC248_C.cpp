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
#define vecin(vec) for(ll i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

ll f(ll p, ll q, ll &m, vector<vector<ll>> &memo){
    if(p > q*m){return 0;}
    if(memo[p][q] != -1){return memo[p][q];}
    memo[p][q] = 0;
    for(ll i = 1; i <= m; i++){
        if(p-i >= 0){
            memo[p][q] = (memo[p][q] + f(p-i,q-1,m,memo)) % 998244353;
        }
    }
    //cout << "f(" << p << "," << q << ") = " << memo[p][q] << endl;
    return memo[p][q];
}


int main(){
    ll n,m,k;
    cin >> n >> m >> k;
    vector<vector<ll>> memo(k+1,vector<ll>(n+1,-1)); //memo[p][q] = A1 ~ Aq までの和がpである数列の個数
    memo[0][0] = 1;
    ll ans = 0;
    for(ll i = n; i <= k; i++){ans = (ans+ f(i,n,m,memo)) % 998244353;}
    cout << ans % 998244353 << endl;
    //cout << "f(" << 1 << "," << 1 << ") = " << memo[1][1] << endl;
}