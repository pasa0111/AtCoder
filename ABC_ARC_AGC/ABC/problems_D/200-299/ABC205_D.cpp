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
    ll n,q;
    cin >> n >> q;
    vector<ll> num(n); //num[i] = 条件を満たす1以上Ai以下の整数の個数
    vector<ll> A(n);
    ll a = 0,b;
    rep(i,n){
        b = a;
        cin >> a;
        A[i] = a;
        if(i > 0) num[i] = num[i-1];
        num[i] += a-b-1;
    }
    rep(query,q){
        ll k;
        cin >> k;
        ll start = -1, end = n, t;
        while(end-start > 1){
            t = (start+end)/2;
            if(num[t] < k) start = t;
            if(num[t] >= k) end = t;
        }
        if(k <= num[0]){
            cout << k << endl;
            continue;
        }
        //cout << "num[" << start << "] = " << num[start] << endl;
        cout << A[start] + k-num[start] << endl;
    }
}