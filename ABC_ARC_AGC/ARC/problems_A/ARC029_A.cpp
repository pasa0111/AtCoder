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
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(int i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

void solve(int i, int n, int &ans, int &res, int &sum, vector<int> &t){
    if(i == n){
        if(2*res-sum >= 0){ans = min(ans,res);}
    }
    if(i < n){
        solve(i+1,n,ans,res,sum,t);
        res += t.at(i);
        solve(i+1,n,ans,res,sum,t);
        res -= t.at(i);
    }
    return;
}

int main(){
    int n, sum = 0, ans = 100000, res = 0;
    cin >> n;
    vector<int> t(n);
    rep(i,n){
        cin >> t.at(i);
        sum += t.at(i);
    }
    solve(0,n,ans,res,sum,t);
    cout << ans << endl;
}