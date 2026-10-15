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

int f(int i, int j, int &n, int &m, vector<vector<int>> &A, vector<int> B, vector<vector<int>> &memo){

    if(i == 0){return 1000;}
    if(j == 0){return 0;}

    if(memo.at(i).at(j) == 0){
        if(B.at(j) > 0){
            memo.at(i).at(j) = min(f(i,j-1,n,m,A,B,memo),f(i-1,j,n,m,A,B,memo));
        }
        if(B.at(j) == 0 && A.at(i).at(j) == 1){
            memo.at(i).at(j) = min(f(i,j-1,n,m,A,B,memo),f(i-1,j,n,m,A,B,memo))+1;
            B.at(j)++;
        }
    }
    if(memo.at(i).at(j) == 0){memo.at(i).at(j) = -1;}
    cout << "f(" << i << "," << j << ") = " << memo.at(i).at(j) << endl;
    return memo.at(i).at(j);
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> A(m+1,vector<int>(n+1)), memo(m+1,vector<int>(n+1));
    vector<int> B(n+1);
    adrep(i,1,m,1){
        adrep(j,1,n,1){cin >> A.at(i).at(j);}
    }
    cout << f(4,2,n,m,A,B,memo) << endl;
}