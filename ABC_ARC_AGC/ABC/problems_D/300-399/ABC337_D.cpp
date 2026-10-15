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

int main(){
    int H,W,K;
    cin >> H >> W >> K;
    vector<string> G(H);
    vecin(G);
    int ans = H*W+1, memo = 0, o = 0;
    rep(i,H){
        memo = 0, o = 0;
        rep(j,W){
            if(memo+o == K){
                if(G[i][j-K] == '.') memo--;
                if(G[i][j-K] == 'o') o--;
            }
            if(G[i][j] == '.') memo++;
            if(G[i][j] == 'x'){
                memo = 0;
                o = 0;
            }
            if(G[i][j] == 'o') o++;
            if(memo+o == K) ans = min(ans,memo);
        }
    }

    rep(j,W){
        memo = 0, o = 0;
        rep(i,H){
            if(memo+o == K){
                if(G[i-K][j] == '.') memo--;
                if(G[i-K][j] == 'o') o--;
            }
            if(G[i][j] == '.') memo++;
            if(G[i][j] == 'x'){
                memo = 0;
                o = 0;
            }
            if(G[i][j] == 'o') o++;
            if(memo+o == K) ans = min(ans,memo);
        }
    }
    if(ans == H*W+1) ans = -1;
    cout << ans << endl;
}