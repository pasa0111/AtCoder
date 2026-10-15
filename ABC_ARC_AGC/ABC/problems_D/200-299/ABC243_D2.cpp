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
    string S, T = "";
    cin >> n >> x >> S;
    int m = 0;
    rep(i,n){
        if(m == 0){
            T += S[i];
            m++;
            continue;
        }
        if(S[i] == 'U'){
            if(T[m-1] == 'R' || T[m-1] == 'L'){
                T.pop_back();
                m--;
                continue;
            }
            T += S[i];
            m++;
        }
        if(S[i] == 'R' || S[i] == 'L'){
            if(T[m-1] == 'U'){
                T.pop_back();
                m--;
                continue;
            }
            T += S[i];
            m++;
        }
    }
    rep(i,n){
        if(S[i] == 'U') x /= 2;
        if(S[i] == 'L') x *= 2;
        if(S[i] == 'R') x = x*2 + 1;
    }
    cout << T << endl;
    cout << x << endl;
}