#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <iomanip>
#include <bitset>


using namespace std;
#define ll long long
#define rep(i,e) for(ll i = 0; i < e; i++)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(unsigned ll i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}
#define SORT(vec) sort(vecall(vec))
#define RSORT(vec) SORT(vec);reverse(vecall(vec));


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int f(int cost, int num, vector<int> &A, vector<int> &B, vector<vector<int>> &table){
    if(cost < 0){return 0;}
    if(table[cost][num] == -1){
        table[cost][num] = 0;
        rep(i,B[num-1]+1){
            if(f(cost-A[num-1]*i,num-1,A,B,table) == 1){
                table[cost][num] = 1;
                break;
            }
        }
    }
    return table[cost][num];
}

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> A(n),B(n);
    rep(i,n){cin >> A[i] >> B[i];}
    vector<vector<int>> table(x+1,vector<int>(n+1,-1));
    rep(i,x+1){table[i][0] = 0;}
    rep(i,n+1){table[0][i] = 1;}
    yesno(f(x,n,A,B,table) == 1);
}