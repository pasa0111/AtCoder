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
#include <cctype>


using namespace std;
#define ll long long
#define rep(i,e) for(ll i = 0; i < e; i++)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(ll i = 0, wtbk = vec.size(); i < wtbk; i++){cin >> vec.at(i);}
#define sumvecin(vec) for(ll i = 0, wtbk = vec.size(); i < wtbk; i++){cin >> vec.at(i); if(i > 0) vec[i] += vec[i-1];}
#define SORT(vec) sort(vecall(vec))
#define RSORT(vec) SORT(vec);reverse(vecall(vec));
#define MP make_pair
#define MT make_tuple

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int n,k;
    cin >> n;
    vector<bitset<32>> a(n);
    vector<bitset<32>> snuke(n);
    rep(i,n){
        cin >> k;
        a[i] = bitset<32>(k);
        snuke[i] = a[i];
    }
    bitset<32> S = a[0];
    for(int i = 1; i < n; i++){
        for(int j = 0; j < 32; j++){
            S[j] = S[j]^a[i][j];
        }
    }
    rep(i,n){
        rep(j,32){
            snuke[i][j] = a[i][j]^S[j];
        }
    }
    rep(i,n) cout << snuke[i].to_ullong() << " ";
    cout << endl;
}