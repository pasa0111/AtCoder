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

ll dp(int i, int j, int n, vector<vector<ll>> &f, string &s){
    string t = "chokudai";
    if(j == -1){return 1;}
    if(i == -1 && 0 <= j && j <= 7){return 0;}
    if(0 <= i && i <= n-1){
        if(s.at(i) == t.at(j)){
            if(f.at(i).at(j) == -1){
                f.at(i).at(j) = dp(i-1,j-1,n,f,s) + dp(i-1,j,n,f,s);
            }
            return f.at(i).at(j) % 1000000007;
        }
        if(s.at(i) != t.at(j)){
            if(f.at(i).at(j) == -1){
                f.at(i).at(j) = dp(i-1,j,n,f,s);
            }
            return f.at(i).at(j) % 1000000007;
        }
    }
    return 0;
}

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<ll>> f(n,vector<ll>(8,-1));
    cout << dp(n-1,7,n,f,s) % 1000000007 << endl;
}