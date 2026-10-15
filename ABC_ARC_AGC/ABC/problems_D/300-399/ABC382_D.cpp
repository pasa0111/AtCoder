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
#define rep(i,e) for(int i = 0; i < e; i++)
#define adrep(i,s,e,k) for(int i = s; i <= e; i+=k)
#define rerep(i,s,e,k) for(int i = s; i >= e; i-=k)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(int i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

void solve(int k, int a, int &n, int &m, int &x, vector<int> A, vector<vector<int>> &ans){
    if(k == n){
        ans.push_back(A);
        x++;
        return;
    }

    if(k < n){
        adrep(i,a+10,m-10*(n-1-k),1){
            A.push_back(i);
            solve(k+1,i,n,m,x,A,ans);
            A.pop_back();
        }
    }
    return;
}

int main(){
    int n,m, x = 0;
    cin >> n >> m;
    vector<int> A;
    vector<vector<int>> ans;
    solve(0,-9,n,m,x,A,ans);
    cout << x << endl;
    for(vector<int> i:ans){
        for(int j:i){
            cout << j << " ";
        }
        cout << endl;
    }
}