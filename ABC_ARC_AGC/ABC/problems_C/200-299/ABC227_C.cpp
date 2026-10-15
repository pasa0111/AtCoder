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
#define vecin(vec) for(ll i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}
#define sumvecin(vec) for(ll i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i); if(i > 0) vec[i] += vec[i-1];}
#define SORT(vec) sort(vecall(vec))
#define RSORT(vec) SORT(vec);reverse(vecall(vec));
#define MP make_pair
#define MT make_tuple

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

ll cuberoot(ll n){
    ll x = 0, start = -1, end = 10000;
    while(end-start > 1){
        x = (start+end)/2;
        if(x*x*x <= n) start = x;
        if(x*x*x > n) end = x;
    }
    return x;
}

int main(){
    ll n;
    cin >> n;
    ll m = sqrt(n), k = cuberoot(n);
    ll ans = 0, z = 0;
    for(ll a = 1; a <= k; a++){
        for(ll b = a; a*b*b <= n; b++){
            ans += max(z,n/a/b - b + 1);
        }
    }
    cout << ans << endl;
}