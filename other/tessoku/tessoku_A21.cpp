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

void f(int i, int j, int &n, vector<int> &P, vector<int> &A, vector<vector<int>> &memo, int &ans){
    //cout << "i: " << i << "   j:" << j << endl;
    if(i == 0 || j == n+1){
        memo.at(i).at(j) = 0;
        return;
    }

    if(i <= j){
        if(memo.at(i-1).at(j) == -1){f(i-1,j,n,P,A,memo,ans);}
        if(memo.at(i).at(j+1) == -1){f(i,j+1,n,P,A,memo,ans);}

        if(i-1 < P.at(i-1) && P.at(i-1) <= j){
            if(i <= P.at(j+1) && P.at(j+1) < j+1){
                memo.at(i).at(j) = max(memo.at(i-1).at(j)+A.at(i-1),memo.at(i).at(j+1)+A.at(j+1));
            }
            if(P.at(j+1) < i || j+1 <= P.at(j+1)){
                memo.at(i).at(j) = max(memo.at(i-1).at(j)+A.at(i-1), memo.at(i).at(j+1));
            }
        }
        if(P.at(i-1) <= i-1 || j < P.at(i-1)){
            if(i <= P.at(j+1) && P.at(j+1) < j+1){
                memo.at(i).at(j) = max(memo.at(i-1).at(j),memo.at(i).at(j+1)+A.at(j+1));
            }
            if(P.at(j+1) < i || j+1 <= P.at(j+1)){
                memo.at(i).at(j) = max(memo.at(i-1).at(j), memo.at(i).at(j+1));
            }
        }
    }
    if(i == j){
        ans = max(ans,memo.at(i).at(j));
        //cout << "f(" << i << ") = " << memo.at(i).at(j) << endl; 
    }
    return;
}

int main(){
    int n;
    cin >> n;
    vector<int> P(n+2),A(n+2);
    rep(i,n){cin >> P.at(i+1) >> A.at(i+1);}
    vector<vector<int>> memo(n+2,vector<int>(n+2,-1));
    memo.at(0).at(0) = 0;
    memo.at(n+1).at(n+1) = 0;
    int ans = 0;
    adrep(i,1,n,1){f(i,i,n,P,A,memo,ans);}
    cout << ans << endl;
}