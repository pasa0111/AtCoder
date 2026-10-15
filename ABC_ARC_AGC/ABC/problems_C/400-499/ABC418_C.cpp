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
    ll n,q, sum = 0;
    cin >> n >> q;
    vector<ll> A(n);
    vecin(A);
    SORT(A);
    for(int i = 1; i < n; i++) A[i] += A[i-1];
    rep(Q,q){
        ll b;
        cin >> b;
        if(n > 1 && b > A[n-1]-A[n-2]){
            cout << -1 << endl;
            continue;
        }
        ll start = -1, end = n, t = -10, u;
        while(start != end){
            u = t;
            t = (start+end)/2;
            if(u == t) break;
            if(t > 0 && A[t]-A[t-1] < b) start = t;
            if(t > 0 && A[t]-A[t-1] >= b) end = t;
            if(t == 0 && A[t] < b) start = t;
            if(t == 0 && A[t] >= b) end = t;
            //cout << "start: " << start << "  t: " << t << "  end: " << end <<  endl;
        }
        //cout << "t: " << t << endl;
        if(start != -1) cout << A[t] + (b-1)*(n-1-t) + 1 << endl;
        if(start == -1) cout << (b-1)*n+1 << endl;
    }
}