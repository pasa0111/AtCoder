#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

void solve (int n, int k, int t, vector<string> s, vector<string> &ans, string res){
    if(t > k){
        ans.push_back(res);
    }

    if(t <= k){
        for(int i = 0; i < n; i++){
            solve(n,k,t+1,s,ans,res+s.at(i));
        }
    }
    return;
}

int main(){
    int N, K, X;
    cin >> N >> K >>X;
    vector<string> S(N), ans;
    for(int i = 0; i < N; i++){
        cin >> S.at(i);
    }
    solve(N,K,1,S,ans,"");
    sort(ans.begin(),ans.end());
    cout << ans.at(X-1) << endl;
}