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
#define vecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < sizesizesize; i++){cin >> vec.at(i);}
#define sumvecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < sizesizesize; i++){cin >> vec.at(i); if(i > 0) vec[i] += vec[i-1];}
#define SORT(vec) sort(vecall(vec))
#define RSORT(vec) SORT(vec);reverse(vecall(vec));
#define MP make_pair
#define MT make_tuple


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int n;
    string S;
    cin >> n >> S;
    ll R = 0,G = 0,B = 0;
    rep(i,n){
        if(S[i] == 'R') R++;
        if(S[i] == 'G') G++;
        if(S[i] == 'B') B++;
    }
    ll ans = R*G*B;
    for(int i = 0; i < n-2; i++){
        for(int j = i+1; 2*j-i < n; j++){
            if(S[i] != S[j] && S[i] != S[2*j-i] && S[j] != S[2*j-i]) ans--;
        }
    }
    cout << ans << endl;
}