#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <deque>
using namespace std;

void solve(int n, int m, vector<int> &a){
    if(a.size() == n){
        for(int i = 0; i < a.size(); i++){
            cout << a.at(i) << " ";
        }
        cout << endl;
        return;
    }
    if(a.size() == 0){
        for(int i = 1; i <= m; i++){
            a.push_back(i);
            solve(n,m,a);
            a.pop_back();
        }
        return;
    }
    for(int i = a.at(a.size()-1)+1; i <= m; i++){
        a.push_back(i);
        solve(n,m,a);
        a.pop_back();
    }
}

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A;
    solve(N,M,A);
}