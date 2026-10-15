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
    ll n,Q;
    cin >> n >> Q;
    vector<ll> A(n);
    vecin(A);
    SORT(A);
    vector<ll> sum(n);
    sum[0] = A[0];
    for(int i = 1; i < n; i++){
        sum[i] += sum[i-1] + A[i];
    }
    rep(q,Q){
        ll start = -1, end = n, t = -10, u, x;
        cin >> x;
        if(A[0] > x){cout << sum[n-1] - x*n << endl; continue;}
        while(start != end){
            u = t;
            t = (start+end)/2;
            if(u == t){break;}
            if(A[t] <= x){start = t;}
            if(A[t] > x){end = t;}
        }
        //cout << "t: " << t << endl;
        cout << x*(t+1) - sum[t] + sum[n-1] - sum[t] - x*(n-1-t) << endl;
    }
}