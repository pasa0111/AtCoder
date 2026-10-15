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


bool prime(ll x){
    bool b = true;
    if(x % 2 == 0 && x != 2){b = false;}
    if(x % 3 == 0 && x != 3){b = false;}
    for(ll i = 1; 6*i <= sqrt(x)+1; i++){
        ll k = 6*i-1, l = 6*i+1;
        if(x % k == 0 && x != k){b = false;}
        if(x % l == 0 && x != l){b = false;}
    }
    return b;
}

//nの三乗根の整数部分を返す
ll cuberoot(ll n){
    ll start = 0, end = 1000009, t = -1, u;
    while(start != end){
        u = t;
        t = (start+end)/2;
        //cout << "t: " << t << "   t^3×2: " << t*t*t*2 << endl;
        if(u == t){break;}
        if(t*t*t < n){start = t;}
        if(t*t*t > n){end = t;}
    }
    return t;
}

int main(){
    ll n,m = 0,Q;
    cin >> n;
    Q = cuberoot(n/2);
    vector<ll> pnum;
    //cout << "Q: " << Q << endl;
    for(ll q = 2; q <= Q; q++){
        if(prime(q)){pnum.push_back(q);}
    }
    /*rep(i,pnum.size()){cout << pnum[i] << " ";}
    cout << endl;*/
    ll size = pnum.size();
    for(ll p = 0; p < size-1; p++){
        ll start = p, end = size, q = -10, u, lim = cuberoot(n/pnum[p]);
        while(start != end){
            u = q;
            q = (start+end)/2;
            if(u == q){break;}
            if(pnum[q] < lim){start = q;}
            if(pnum[q] > lim){end = q;}
        }
        while(q > p && pnum[q] > lim){q--;}
        while(q < size && pnum[q] <= lim){q++;}
        q--;
        if(p >= q){continue;}
        //cout << "p: " << p  << "   q: " << q << endl;
        //cout << "p: " << pnum[p] << "   q: " << pnum[q] << "  x: " << q-p << "   p*q^3: " << pnum[p] * pnum[q] * pnum[q] * pnum[q] << endl;
        m += q-p;
    }
    cout << m << endl;
}