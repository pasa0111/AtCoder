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

int main(){
    int n,k;
    cin >> n >> k;
    bool ans = true;
    vector<int> V(n);
    map<int,vector<int>> M;
    vector<int> S;
    rep(i,n){
        int x;
        cin >> x;
        if(!M.count(i%k)){M[i%k] = S;}
        M.at(i%k).push_back(x);
    }
    rep(i,k){sort(vecall(M.at(i)));}
    rep(i,k){
        int y = 0;
        for(int x:M.at(i)){
            V.at(y*k+i) = x;
            y++;
        }
    }
    //rep(i,n){cout << V.at(i) << " ";}
    //cout << endl;
    for(int i = 1; i < n; i++){
        if(V.at(i-1) > V.at(i)){
            ans = false;
            break;
        }
    }
    yesno(ans);
}
