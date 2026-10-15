#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;

void solve(int n, int m, vector<pair<int,int>> &s, vector<pair<int,int>> &c, vector<int> &ans){
    int res = 400000000;
    for(int i = 0; i < m; i++){
        int k = abs(s.at(n).first - c.at(i).first) + abs(s.at(n).second - c.at(i).second);
        if(res > k){
            ans.at(n) = i+1;
            res = k;
        }
    }
    return;
}

int main(){
    int N, M;
    cin >> N >> M;
    vector<pair<int,int>> s(N), c(M);
    vector<int> ans(N); //人iが行くチェックポイントの番号を保存
    for(int i = 0; i < N; i++){cin >> s.at(i).first >> s.at(i).second;}
    for(int i = 0; i < M; i++){cin >> c.at(i).first >> c.at(i).second;}
    for(int i = 0; i < N; i++){
        solve(i,M,s,c,ans);
        cout << ans.at(i) << endl;
    }
}