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
#define rep(i,e) for(int i = 0; i < e; i++)
#define adrep(i,s,e,k) for(int i = s; i <= e; i+=k)
#define rerep(i,s,e,k) for(int i = s; i >= e; i-=k)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(int i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}


void yesno(bool b){
    if(b) cout << "First" << endl;
    if(!b) cout << "Second" << endl;
}

bool f(int k, int &a, int &b, vector<pair<bool,bool>> &dp){
    if(dp[k].second == true){return dp[k].first;}
    if(k >= b && f(k-b,a,b,dp)){
        if(f(k-a,a,b,dp)){dp[k] = make_pair(false,true);}
        if(!f(k-a,a,b,dp) && dp[k-a].second){dp[k] = make_pair(true,true);}
    }
    if(k >= b && !f(k-b,a,b,dp) && dp[k-b].second){dp[k] = make_pair(true,true);}

    if(a < k && k < b){
        if(f(k-a,a,b,dp)){dp[k] = make_pair(false,true);}
        if(!f(k-a,a,b,dp) && dp[k-a].second){dp[k] = make_pair(true,true);}
    }
    return dp[k].first;
}

int main(){
    int n,a,b;
    cin >> n >> a >> b;
    vector<pair<bool,bool>> dp(n+1,make_pair(false,false));
    adrep(i,0,a-1,1){dp[i] = make_pair(false,true);}
    adrep(i,a,min(n,a+a-1),1){dp[i] = make_pair(true,true);}
    adrep(i,b,min(n,b+a-1),1){dp[i] = make_pair(true,true);}
    rep(i,n+1){f(i,a,b,dp);}
    /*rep(i,n+1){cout << f(i,a,b,dp) << " ";}
    cout << endl;
    rep(i,n+1){cout << dp[i].second << " ";}
    cout << endl;*/
    yesno(dp[n].first);
}