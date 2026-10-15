#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
using namespace std;

void solve (int n, int m, int k, set<int> &w, set<int> &b, vector<int> u, vector<int> v, int &ans){
    int res = 0;
    if(k > n){
        for(int i = 0; i < m; i++){
            if(w.count(u.at(i))){
                if(w.count(v.at(i))){
                    res++;
                }
            }
            if(b.count(u.at(i))){
                if(b.count(v.at(i))){
                    res++;
                }
            }
        }
        ans = min(ans, res);
    }

    if(k <= n){
        w.insert(k);
        solve(n,m,k+1,w,b,u,v,ans);
        w.erase(k);
        b.insert(k);
        solve(n,m,k+1,w,b,u,v,ans);
        b.erase(k);
    }
    return;
}

int main(){
    int N, M, ans = 500;
    cin >> N >> M;
    set<int> white, black;
    vector<int> U(M), V(M);
    for(int i = 0; i < M; i++){
        cin >> U.at(i) >> V.at(i);
    }
    solve(N,M,1,white,black,U,V,ans);
    cout << ans << endl;
}