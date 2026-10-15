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
    ll n;
    cin >> n;
    vector<ll> A(n);
    rep(i,n){
        cin >> A[i];
        if(i > 0) A[i] += A[i-1];
    }
    ll x = 0, maximum = 0, ans = 0;
    rep(i,n){
        maximum = max(maximum, A[i]);
        ans = max(ans, x+maximum);
        x += A[i];
    }
    cout << ans << endl;
}