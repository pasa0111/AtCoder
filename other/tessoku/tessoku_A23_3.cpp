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
    int n,m;
    cin >> n >> m;
    vector<int> A(m+1);
    rep(i,m){
        int c = 0;
        rep(j,n){
            int a;
            cin >> a;
            if(a == 1){
                c = c | (1<<j);
            }
        }
        A.at(i) = c;
    }
    vector<vector<int>> dp(m+1,vector<int>((1 << n),m+1));
    dp.at(0).at(0) = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < (1 << n); j++){
            if(dp.at(i).at(j) == m+1){continue;}

            dp.at(i+1).at(j) = min(dp.at(i).at(j), dp.at(i+1).at(j));

            int J = j | A.at(i);
            dp.at(i+1).at(J) = min(dp.at(i+1).at(J), dp.at(i).at(j)+1);
        }
    }
    if(dp.at(m).at((1 << n)-1) == m+1){dp.at(m).at((1 << n)-1) = -1;}
    cout << dp.at(m).at((1 << n)-1) << endl;
}