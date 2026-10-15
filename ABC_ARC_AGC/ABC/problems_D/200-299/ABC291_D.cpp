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
vector<vector<ll>> dp(200001,vector<ll>(2,-1));
vector<vector<ll>> card(200001,vector<ll>(2)); //0:オモテ, 1:ウラ

ll f(int i, int x){
    if(dp[i][x] == -1){
        dp[i][x]++;
        if(card[i-1][0] != card[i][x]) dp[i][x] += f(i-1,0);
        if(card[i-1][1] != card[i][x]) dp[i][x] += f(i-1,1);
    }
    //cout << "f(" << i << "," << x << ") = " << dp[i][x] << endl;
    dp[i][x] %= 998244353;
    return dp[i][x];
}


int main(){
    int n;
    cin >> n;
    rep(i,n) cin >> card[i][0] >> card[i][1];
    dp[0][0] = 1;
    dp[0][1] = 1;
    cout << (f(n-1,0) + f(n-1,1)) % 998244353 << endl;
}