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

int main(){
    ll n,x,y;
    cin >> n >> x >> y;
    vector<ll> A(n);
    ll M = 0, m = 0;
    vecin(A);
    sort(vecall(A));
    ll ans = A[0];
    for(ll i = 1; i <= n-1; i++){
        if((A[i]-A[0])*x % (y-x) != 0){
            ans = 0;
            break;
        }
        if(((A[i]-A[0])*x)/(y-x) > A[0]){
            ans = 0;
            break;
        }
        ans += A[0] - ((A[i]-A[0])*x)/(y-x);
    }
    if(ans == 0){cout << -1 << endl;}
    else{cout << ans << endl;}
}