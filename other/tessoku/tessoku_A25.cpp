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

ll f(int i, int j, vector<string> &G, vector<vector<ll>> &memo){
    if(G.at(i).at(j) == '#'){return 0;}

    if(memo[i][j] == -2){
        memo[i][j] = 0;
        if(i > 0){memo[i][j] += f(i-1,j,G,memo);}
        if(j > 0){memo[i][j] += f(i,j-1,G,memo);}
    }
    //cout << "f(" << i << "," << j << ") = " << memo[i][j] << endl;
    return memo[i][j];
}


int main(){
    int h,w;
    cin >> h >> w;
    vector<string> G(h);
    vecin(G);
    vector<vector<ll>> memo(h,vector<ll>(w,-2));
    memo[0][0] = 1;
    cout << f(h-1,w-1,G,memo) << endl;
}