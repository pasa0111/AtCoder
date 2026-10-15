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
#define adrep(i,s,e,k) for(int i = s; i <= e; i+=k)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(int i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

void f(int i, int j, int &s, int &n, vector<vector<bool>> &memo, vector<int> &A){
    if(j < n){
        if(i + A.at(j) <= s){
            memo.at(i+A.at(j)).at(j+1) = true;
            f(i+A.at(j),j+1,s,n,memo,A);
        }
        memo.at(i).at(j+1) = true;
        f(i,j+1,s,n,memo,A);
    }
    return;
}


int main(){
    int n, s;
    cin >> n >> s;
    vector<int> A(n);
    vecin(A);
    vector<vector<bool>> memo(s+1,vector<bool>(n+1,false));
    memo.at(0).at(0) = true;
    f(0,0,s,n,memo,A);
    yesno(memo.at(s).at(n));
}