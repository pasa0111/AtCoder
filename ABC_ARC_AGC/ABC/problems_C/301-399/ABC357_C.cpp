#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
using namespace std;

void solve(int k, pair<int,int> t, vector<vector<char>> &ans){

    if(k == 0){
        ans.at(t.first).at(t.second) = '#';
    }

    if(k >= 1){
        int n = 1;
        for(int i = 0; i < k-1; i++){n *= 3;} //n = 3^(k-1)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans.at(t.first+n+i).at(t.second+n+j) = '.';
            }
        }
        for(int i = 0; i <= 2; i++){
            for(int j = 0; j <= 2; j++){
                if(i != 1 || j != 1){
                    solve(k-1, make_pair(t.first+n*i,t.second+n*j), ans);
                }
            }
        }
    }
    return;
}


int main(){
    int N, n=1;
    cin >> N;
    for(int i=0; i<N; i++){n *= 3;} //n = 3^N
    vector<vector<char>> ans(n, vector<char>(n));
    solve(N,make_pair(0,0), ans);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << ans.at(i).at(j);
        }
        cout << endl;
    }
}