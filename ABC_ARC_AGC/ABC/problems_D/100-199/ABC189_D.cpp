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
    int n;
    cin >> n;
    vector<bool> S(n,false);
    vector<vector<ll>> ans(2,vector<ll>(n+1,0));
    rep(i,n){
        string s;
        cin >> s;
        if(s == "AND"){S[i] = true;}
    }
    ans[0][0]++;
    ans[1][0]++;
    rep(i,n){
        if(S[i] == true){
            ans[0][i+1] = ans[0][i]*2 + ans[1][i];
            ans[1][i+1] = ans[1][i];
        }
        if(S[i] == false){
            ans[0][i+1] = ans[0][i];
            ans[1][i+1] = ans[0][i] + ans[1][i]*2;
        }
    }
    cout << ans[1][n] << endl;
}