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

int f(int i, int j, vector<vector<int>> &A, vector<vector<int>> &memo, vector<vector<vector<int>>> &B){

    if(j == 0){return 0;}
    if(i == 0){return 5000;}

    if(memo.at(i).at(j) == 500){
        if(B.at(i-1).at(j).at(0) == 0){
            f(i-1,j,A,memo,B);
            B.at(i-1).at(j).at(0) = 1;
        }
        if(B.at(i-1).at(j).at(j) > 0){
            if(f(i-1,j,A,memo,B) != -1){memo.at(i).at(j) = f(i-1,j,A,memo,B);}
        }
        if(B.at(i-1).at(j).at(j) == 0){
            if(A.at(i).at(j) == 1){
                if(f(i-1,j,A,memo,B) != -1){
                    memo.at(i).at(j) = f(i-1,j,A,memo,B)+1;
                    int n = A.at(i).size();
                    rep(k,n){B.at(i).at(j).at(k) += A.at(i).at(k);}
                }
            }
        }

        if(B.at(i).at(j-1).at(0) == 0){
            f(i,j-1,A,memo,B);
            B.at(i).at(j-1).at(0) = 1;
        }

        if(B.at(i).at(j-1).at(j) > 0){
            if(f(i,j-1,A,memo,B) != -1){memo.at(i).at(j) = min(f(i,j-1,A,memo,B),memo.at(i).at(j));}
        }
        if(B.at(i).at(j-1).at(j) == 0){
            if(A.at(i).at(j) == 1){
                if(f(i,j-1,A,memo,B) != -1){memo.at(i).at(j) = min(memo.at(i).at(j),memo.at(i).at(j-1)+1);}
            }
        }
        if(memo.at(i).at(j) == 500){memo.at(i).at(j) = 5000;}
    }
    cout << "f(" << i << "," << j << ") = " << memo.at(i).at(j) << endl;
    return memo.at(i).at(j);
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> A(m+1,vector<int>(n+1)), memo(m+1,vector<int>(n+1,500));
    vector<vector<vector<int>>> B(m+1,vector<vector<int>>(n+1,vector<int>(n+1)));
    adrep(i,1,m,1){
        adrep(j,1,n,1){cin >> A.at(i).at(j);}
    }
    cout << f(m,n,A,memo,B) << endl;
}