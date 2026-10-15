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

ll f(int i, int j, ll &w, ll &v, ll score, ll &ans, vector<vector<ll>> &memo, vector<ll> &W, vector<ll> &H, vector<ll> &B, vector<ll> &V){
    //cout << i << "   " << j << endl;
    if(i > w){return -1;}
    if(i <= w){
        if(j <= v){
            if(i == 0){memo.at(i).at(j) = score;}
            if(j == 0 && i > 0){memo.at(i).at(j) = -1;}
            if(j >= 1 && i >= W.at(V.at(j-1)) && memo.at(i-W.at(V.at(j-1))).at(j-1) == 0){memo.at(i-W.at(V.at(j-1))).at(j-1) = f(i-W.at(V.at(j-1)),j-1,w,v,score-H.at(V.at(j-1))+B.at(V.at(j-1)),ans,memo,W,H,B,V);}
            if(j >= 1 && memo.at(i).at(j-1) == 0){memo.at(i).at(j-1) = f(i,j-1,w,v,score,ans,memo,W,H,B,V);}
            if(j >= 1 && i >= W.at(V.at(j-1)) && memo.at(i).at(j) == 0){memo.at(i).at(j) = max(memo.at(i-W.at(V.at(j-1))).at(j-1)+H.at(V.at(j-1))-B.at(V.at(j-1)),memo.at(i).at(j-1));}
        }
    }
    if(j >= 1){memo.at(i).at(j) = max(memo.at(i).at(j),memo.at(i).at(j-1));}
    //cout << "f(" << i << "," << j << ") = " << memo.at(i).at(j) << endl;
    return memo.at(i).at(j);
}

int main(){
    int n;
    cin >> n;
    vector<ll> W(n),H(n),B(n),V;
    ll weight = 0, ans = 0;
    rep(i,n){
        cin >> W.at(i) >> H.at(i) >> B.at(i);
        weight += W.at(i);
        ans += B.at(i);
        if(H.at(i) > B.at(i)){V.push_back(i);}
    }
    ll w = weight/2, v = V.size();
    vector<vector<ll>> memo(w+1,vector<ll>(v+1));
    rep(i,w+1){f(i,v,w,v,ans,ans,memo,W,H,B,V);}
    rep(i,w+1){
        ans = max(ans,memo.at(i).at(v));
    }
    cout << ans << endl;
}