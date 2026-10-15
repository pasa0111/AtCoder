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
    ll n,ans = 0;
    cin >> n;
    vector<ll> A(n), sum(n);
    rep(i,n){
        cin >>A[i];
    }
    SORT(A);
    sum[0] = A[0];
    for(int i = 1; i < n; i++){sum[i] += sum[i-1] + A[i];}
    for(ll x = 0; x < n-1; x++){
        ll start = x, end = n, t = -10, u;
        while(start != end){
            u = t;
            t = (start+end)/2;
            if(u == t){break;}
            if(A[t] < 100000000-A[x]){start = t;}
            if(A[t] > 100000000-A[x]){end = t;}
        }
        while(t > x && A[t]+A[x] >= 100000000){t--;}
        while(t < n && A[t]+A[x] < 100000000){t++;}
        t--;
        //cout << "x: " << x << "   t: " << t << endl;
        ans += A[x]*(n-x-1) + (sum[n-1]-sum[x]) - 100000000*(n-1-max(x,t));
        //cout << ans << endl;
    }
    cout << ans << endl;
}