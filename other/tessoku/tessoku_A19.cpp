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
#define adrep(i,s,e,k) for(int i = s; i <= e; i+=k)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(int i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

ll f(int i, int j, int &w, int &n, vector<ll> &W, vector<ll> &V, vector<vector<ll>> &memo, ll &ans){
    if(i == 0){memo.at(i).at(j) = 0;}
    if(i > 0){
        if(j == 0){memo.at(i).at(j) = -1;}
        if(j > 0){
            if(i-W.at(j-1) >= 0){
                if(memo.at(i-W.at(j-1)).at(j-1) == -2){memo.at(i-W.at(j-1)).at(j-1) = f(i-W.at(j-1),j-1,w,n,W,V,memo,ans);}
                if(memo.at(i-W.at(j-1)).at(j-1) != -1){memo.at(i).at(j) = memo.at(i-W.at(j-1)).at(j-1) + V.at(j-1);}
            }
            if(memo.at(i).at(j-1) == -2){memo.at(i).at(j-1) = f(i,j-1,w,n,W,V,memo,ans);}
            if(memo.at(i).at(j-1) != -1){memo.at(i).at(j) = max(memo.at(i).at(j),memo.at(i).at(j-1));}
        }
    }
    if(memo.at(i).at(j) == -2){memo.at(i).at(j) = -1;}
    //cout << "f(" << i << "," << j << ") = " << memo.at(i).at(j) << endl;
    if(j == n){ans = max(ans,memo.at(i).at(j));}
    return memo.at(i).at(j);
}

int main(){
    int n,w;
    cin >> n >> w;
    vector<ll> W(n),V(n);
    rep(i,n){cin >> W.at(i) >> V.at(i);}
    vector<vector<ll>> memo(w+1,vector<ll>(n+1,-2));
    ll ans = 0;
    rep(i,w+1){f(i,n,w,n,W,V,memo,ans);}
    cout << ans << endl;
}