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


//t:Tの何文字目に注目しているか
//n:N
//i:何回目の操作か(0~n-1)
void solve(int t, int &n, int i, int res, int &ans, string &T, vector<vector<string>> &S, string M){
    if(i == n){
        if(T == M){ans = min(ans,res);}
        return;
    }
    int u = S.at(i).size();
    int q = T.size();
    if(t == q){
        solve(t,n,n,res,ans,T,S,M);
        return;
    }
    rep(j,u){
        int p = S.at(i).at(j).size();
        if(t+p <= q && T.substr(t,p) == S.at(i).at(j)){
            M += S.at(i).at(j);
            solve(t+p,n,i+1,res+1,ans,T,S,M);
            M.erase(t,p);
        }
    }
    solve(t,n,i+1,res,ans,T,S,M);
    return;
}

int main(){
    string T;
    int n;
    cin >> T >> n;
    vector<vector<string>> S(n);
    rep(i,n){
        int a;
        string s;
        cin >> a;
        rep(j,a){
            cin >> s;
            S.at(i).push_back(s);
        }
    }
    int ans = 1000;
    solve(0,n,0,0,ans,T,S,"");
    if(ans == 1000){cout << -1 << endl;}
    if(ans < 1000){cout << ans << endl;}
}