#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <iomanip>


using namespace std;
#define ll long long
#define rep(i,e) for(int i = 0; i < e; i++)
#define adjrep(i,s,e) for(ll i = s; i <= e; i++)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(int i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}
#define adjvecin(vec) for(int i = 1, a = vec.size(); i < a; i++){cin >> vec.at(i);}


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

//
ll time(ll k, vector<vector<ll>> &A, vector<ll> &F, vector<ll> &T, set<ll> &S){
    ll res = 0;
    if(F.at(k) == -1){
        for(ll &a:A.at(k)){
            if(!S.count(a)){res += time(a,A,F,T,S);}
        }
        F.at(k) = res + T.at(k);
        S.insert(k);
    }
    return F.at(k);
}


int main(){
    ll n;
    cin >> n;
    vector<ll> T(n+1,0);
    vector<vector<ll>> A(n+1,vector<ll>(0,0));
    set<ll> S;
    rep(i,n){
        ll t,k;
        cin >> t >> k;
        T.at(i+1) = t;
        vector<ll> B(k);
        vecin(B);
        A.at(i+1) = B;
    }
    vector<ll> F(n+1,-1);
    cout << time(n,A,F,T,S) << endl;
}