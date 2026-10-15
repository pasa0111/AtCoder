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
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    ll n;
    cin >> n;
    vector<string> S(n);
    vector<vector<ll>> G(n,vector<ll>(n)), H(n,vector<ll>(n));
    vector<vector<ll>> A(n);
    rep(i,n){
        cin >> S.at(i);
        rerep(j,n-1,0,1){
            if(S.at(i).at(j) == 'o'){
                H.at(i).at(j)++;
                G.at(i).at(j)++;
                A.at(j).push_back(i);
            }
            if(j >= 1){G.at(i).at(j-1) += G.at(i).at(j);}
        }
    }
    rep(i,n){
        adrep(j,1,n-1,1){H.at(i).at(j) += H.at(i).at(j-1);}
    }
    /*rep(i,n){
        rep(j,n){cout << G.at(i).at(j) << " ";}
        cout << endl;
    }*/
    ll ans = 0;
    rep(i,n){
        //cout << "i = " << i << endl;
        if(A.at(i).size() <= 1){continue;}
        for(ll j = 0; j < A.at(i).size(); j++){
            ans += (G.at(A.at(i).at(j)).at(i)-1 + H.at(A.at(i).at(j)).at(i)-1)*(A.at(i).size()-1);
        }
    }
    cout << ans << endl;
}