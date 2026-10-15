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
#define vecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < wtbk; i++){cin >> vec.at(i);}
#define sumvecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < wtbk; i++){cin >> vec.at(i); if(i > 0) vec[i] += vec[i-1];}
#define SORT(vec) sort(vecall(vec))
#define RSORT(vec) SORT(vec);reverse(vecall(vec));
#define MP make_pair
#define MT make_tuple


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    ll n,x;
    string S;
    cin >> n >> x >> S;
    bool ok = true;
    int u = 0;
    rep(i,n){
        if(x <= 1000000000000000000){
            u = 0;
            ok = true;
        }
        if(x > 1000000000000000000) ok = false;
        if(S[i] == 'U'){
            if(!ok){
                u++;
                if(u > 0) ok = true;
            }
            if(ok){
                if(x%2 == 1)x--;
                x /= 2;
            }
        }
        if(S[i] == 'L'){
            if(ok){
                x *= 2;
                //if(x > 1000000000000000000) ok = false;
            }
            if(!ok) u--;
        }
        if(S[i] == 'R'){
            if(ok){
                x = x*2 + 1;
                //if(x > 1000000000000000000) ok = false;
            }
            if(!ok) u--;
        }
    }
    cout << x << endl;
}