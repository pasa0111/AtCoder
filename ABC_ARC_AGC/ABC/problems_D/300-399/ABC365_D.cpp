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
#include <cctype>


using namespace std;
#define ll long long
#define rep(i,e) for(ll i = 0; i < e; i++)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < sizesizesize; i++){cin >> vec.at(i);}
#define sumvecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < sizesizesize; i++){cin >> vec.at(i); if(i > 0) vec[i] += vec[i-1];}
#define SORT(vec) sort(vecall(vec))
#define RSORT(vec) SORT(vec);reverse(vecall(vec));
#define MP make_pair
#define MT make_tuple

/*
g++ ABC/problems_D/301-400/ABC365_D.cpp -o a.out && ./a.out < ./input.txt
*/

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int n;
    string S;
    char pre = '0';
    cin >> n >> S;
    vector<vector<int>> dp(3,vector<int>(n));
    if(S[0] == 'R'){
        dp[2][0] = 1;
    }
    if(S[0] == 'S'){
        dp[0][0] = 1;
    }
    if(S[0] == 'P'){
        dp[1][0] = 1;
    }
    for(int i = 1; i < n; i++){
        if(S[i] == 'R'){
            dp[0][i] = max(dp[1][i-1],dp[2][i-1]);
            dp[2][i] = max(dp[0][i-1],dp[1][i-1]) + 1;
        }
        if(S[i] == 'S'){
            dp[1][i] = max(dp[0][i-1],dp[2][i-1]);
            dp[0][i] = max(dp[1][i-1],dp[2][i-1]) + 1;
        }
        if(S[i] == 'P'){
            dp[2][i] = max(dp[1][i-1],dp[0][i-1]);
            dp[1][i] = max(dp[0][i-1],dp[2][i-1]) + 1;
        }
    }
    cout << max({dp[0][n-1],dp[1][n-1],dp[2][n-1]}) << endl;
}