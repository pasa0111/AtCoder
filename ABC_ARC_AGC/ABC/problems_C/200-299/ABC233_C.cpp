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

void total(ll k, ll &n, ll &x, ll pro, ll &ans, vector<ll> &L, vector<vector<ll>> &a){
    //cout << "k: " << k << endl;
    if(pro > x) return;
    if(k == n){
        if(pro == x) ans++;
        return;
    }

    for(ll A:a[k]){
        total(k+1,n,x,pro*A,ans,L,a);
    }
    return;
}

int main(){
    ll n,x;
    cin >> n >> x;
    vector<ll> L(n);
    vector<vector<ll>> a(n);
    rep(i,n){
        cin >> L[i];
        ll A;
        for(ll j = 0; j < L[i]; j++){
            cin >> A;
            a[i].push_back(A);
        }
    }
    ll ans = 0;
    total(0,n,x,1,ans,L,a);
    cout << ans << endl;
}