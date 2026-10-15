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

//2^a * b^2 <= n　を満たす最大のaを返す
ll power(ll b, ll n){
    ll a = 0, c = 1, B = b*b; //c = 2^a
    while(c*B <= n){
        a++;
        c*=2;
    }
    a--;
    return a;
}

int main(){
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll a = 1; a < 61; a++){
        ll A = 1;
        rep(i,a) A*=2; //A=2^a
        ll start = 0, end = 1000000010, t = 500000005;
        while(end-start > 1){
            if((2*t-1)*(2*t-1) > n/A) end = t;
            if((2*t-1)*(2*t-1) <= n/A) start = t;
            t = (start+end)/2;
        }
        ans += t;
    }
    cout << ans << endl;
}