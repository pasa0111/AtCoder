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
    ll n,q,x;
    cin >> n >> q;
    vector<ll> R(n);
    vecin(R);
    SORT(R);
    for(int i = 1; i < n; i++) R[i] += R[i-1];
    rep(Q,q){
        cin >> x;
        ll start = -1, end = n, t = -10, u;
        while(start != end){
            u = t;
            t = (start+end)/2;
            if(u == t) break;
            if(R[t] < x) start = t;
            if(R[t] > x) end = t;
        }
        if(R[0] > x) t = -1;
        cout << t+1 << endl;
    }
}