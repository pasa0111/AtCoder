#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
using namespace std;

void solve(int n, int now, vector<set<int>> &s, set<int> &p, bool &ans){
    if(p.size() == n && s.at(now).count(1)){ans = true;}

    if(p.size() < n){
        for(int i:s.at(now)){
            if(p.count(i) == false){
                p.insert(i);
                solve(n,i,s,p,ans);
                p.erase(i);
            }
            if(ans == true){return;}
        }
    }
    return;
}

int main(){
    int N, M, A, B;
    bool ans = false;
    cin >> N >> M;
    vector<set<int>> S(N+1);
    set<int> P;
    for(int i = 0; i < M; i++){
        cin >> A >> B;
        S.at(A).insert(B);
        S.at(B).insert(A);
    }
    if(N == M){
        P.insert(1);
        solve(N,1,S,P,ans);
    }
    if(ans == false){cout << "No" << endl;}
    if(ans == true){cout << "Yes" << endl;}
}