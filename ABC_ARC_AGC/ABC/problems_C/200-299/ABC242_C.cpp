#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
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


ll solve(int k, int n, vector<vector<ll>> &f){
    //cout << "(k,n) = (" << k << ", " << n << ")" << endl;
    if(k == 0 || k == 10 || k == 11 || n == 0){return 0;}
    if(f.at(k+2).at(n-2) == -1){f.at(k+2).at(n-2) = solve(k+2,n-2,f);}
    if(f.at(k+1).at(n-2) == -1){f.at(k+1).at(n-2) = solve(k+1,n-2,f);}
    if(f.at(k).at(n-2) == -1){f.at(k).at(n-2) = solve(k,n-2,f);}
    if(k >= 1){
        if(f.at(k-1).at(n-2) == -1){f.at(k-1).at(n-2) = solve(k-1,n-2,f);}
    }
    if(k >= 2){
        if(f.at(k-2).at(n-2) == -1){f.at(k-2).at(n-2) = solve(k-2,n-2,f);}
    }
    if(k == 9 && n >= 3){f.at(9).at(n) = (2*f.at(9).at(n-2) + 2*f.at(8).at(n-2) + f.at(7).at(n-2)) % 998244353;}
    if(2 <= k && k <= 8 && n >= 3){f.at(k).at(n) = (f.at(k+2).at(n-2) + 2*f.at(k+1).at(n-2) + 3*f.at(k).at(n-2) + 2*f.at(k-1).at(n-2) + f.at(k-2).at(n-2)) % 998244353;}
    if(k == 1 && n >= 3){f.at(1).at(n) = (2*f.at(1).at(n-2) + 2*f.at(2).at(n-2) + f.at(3).at(n-2)) % 998244353;}
    //cout << "f(" << k << "," << n << ") = " << f.at(k).at(n) << endl;
    return f.at(k).at(n);
}

int main(){
    int N;
    ll ans = 0;
    cin >> N;
    vector<vector<ll>> f(12,vector<ll>(N+1,-1));
    for(int i = 1; i <= 9; i++){
        f.at(i).at(1) = 1;
        if(i == 1 || i == 9){f.at(i).at(2) = 2;}
        else{f.at(i).at(2) = 3;}
    }
    for(int i = 1; i <= 9; i++){
        for(int j = 3; j <= N; j++)
        solve(i,j,f);
    }
    for(int i = 1; i <= 9; i++){ans += solve(i,N,f);}
    cout << ans % 998244353 << endl;
}