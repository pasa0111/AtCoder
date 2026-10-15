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

//ステージkを遊べるようになるまでにかかる時間を返す
ll mintime(ll k, vector<ll> &A, vector<ll> &B, vector<vector<ll>> &V, vector<ll> &memo){
    if(memo[k] == -1){
        memo[k] = mintime(k-1,A,B,V,memo) + A[k-1];
        for(ll i:V[k]){memo[k] = min(memo[k], mintime(i,A,B,V,memo) + B[i]);}
    }
    //cout << "stage" << k << ": " << memo[k] << endl;
    return memo[k];
}

int main(){
    ll n;
    cin >> n;
    vector<vector<ll>> V(n+1); //V[i] = {X_j = iであるjの集合}
    vector<ll> A(n);
    vector<ll> B(n);
    vector<ll> memo(n+1,-1);
    memo[1] = 0;
    rep(i,n-1){
        cin >> A[i+1] >> B[i+1];
        ll x;
        cin >> x;
        V[x].push_back(i+1);
    }
    cout << mintime(n,A,B,V,memo) << endl;
}