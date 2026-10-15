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
#define MP make_pair

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    vector<vector<int>> sky(2010,vector<int>(2010));
    int n;
    cin >> n;
    vector<int> U(n),D(n),L(n),R(n);
    vector<vector<int>> usui(2010,vector<int>(2010,0)); //1:雲1枚しかない
    rep(i,n){
        int u,d,l,r;
        cin >> u >> d >> l >> r;
        U[i] = u;
        D[i] = d;
        L[i] = l;
        R[i] = r;
        sky[u][l]++;
        sky[u][r+1]--;
        sky[d+1][l]--;
        sky[d+1][r+1]++;
    }
    for(int i = 1; i <= 2005; i++){
        for(int j = 1; j <= 2005; j++){
            sky[i][j] += sky[i][j-1];
        }
    }
    int ans = 0;
    for(int j = 1; j <= 2000; j++){
        for(int i = 1; i <= 2000; i++){
            sky[i][j] += sky[i-1][j];
            if(sky[i][j] == 0) ans++;
            if(sky[i][j] == 1) usui[i][j] = 1;
            usui[i][j] += usui[i-1][j];
        }
    }
    for(int i = 1; i <= 2005; i++){
        for(int j = 1; j <= 2005; j++){
            usui[i][j] += usui[i][j-1];
        }
    }
    rep(k,n){
        int u = U[k], d = D[k], l = L[k], r = R[k];
        /*for(int i = 0; i <= d; i++){
            for(int j = 0; j <= r; j++){
                cout << usui[i][j] << " ";
            }
            cout << endl;
        }
        */
        //int res = 0;
        //for(int j = l; j <= r; j++){res += usui[d][j]-usui[u-1][j];}
        cout << ans + usui[d][r] + usui[u-1][l-1] - usui[u-1][r] - usui[d][l-1] << endl;
    }
}