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
#define adrep(i,s,e,k) for(ll i = s; i <= e; i+=k)
#define rerep(i,s,e,k) for(ll i = s; i >= e; i-=k)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(ll i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int f(int k, vector<int> &A, vector<int> &stair){
    //cout << "k: " << k << endl;
    if(stair[k] != -1){return stair[k];}
    for(int a:A){
        if(k-a > -1){
            if(f(k-a,A,stair) == 0){stair[k] = 0;}
            if(f(k-a,A,stair) == 1){stair[k] = 1;}
            if(stair[k] == 1){break;}
        }
    }
    if(stair[k] == -1){stair[k] = 0;}
    //cout << "f(" << k << ") = " << stair[k] << endl;
    return stair[k];
}

int main(){
    int n,m,x;
    cin >> n;
    vector<int> A(n);
    vecin(A);
    cin >> m;
    vector<int> B(m);
    vecin(B);
    cin >> x;
    vector<int> stair(x+1,-1);
    for(int b:B){stair[b] = 0;}
    stair[0] = 1;
    if(f(x,A,stair) == 0){cout << "No" << endl;}
    if(f(x,A,stair) == 1){cout << "Yes" << endl;}
    //rep(i,x+1){cout << stair[i] << " ";}
    //cout << endl;
}