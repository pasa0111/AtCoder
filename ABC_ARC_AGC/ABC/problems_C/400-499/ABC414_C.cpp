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

bool odd = false;
ll a,n,ans = 0;
vector<int> ad;

void solve(ll k, vector<ll> &ten){
    //cout << k << endl;
    if(k == ten.size()){
        ll x = 0;
        for(int i = k-1; i >= 0; i--){
            x *= 10;
            x += ten[i];
        }
        for(int i = 0; i < k; i++){
            x *= 10;
            x += ten[i];
        }
        while(x%10 == 0 && x > 0) x/= 10;
        //cout << x << endl;
        vector<int> changed;
        ll y = x;
        while(y > 0){
            changed.push_back(y%a);
            y /= a;
        }
        bool hantei = true;
        ll p = changed.size();
        for(int i = 0; i < p; i++){
            if(changed[i] != changed[p-1-i]) hantei = false;
        }
        if(hantei && x <= n) ans += x;


        x = 0;
        for(int i = k-1; i >= 0; i--){
            x *= 10;
            x += ten[i];
        }
        for(int i = 1; i < k; i++){
            x *= 10;
            x += ten[i];
        }
        while(x%10 == 0 && x > 0) x/= 10;
        //cout << x << endl;
        changed = {};
        y = x;
        while(y > 0){
            changed.push_back(y%a);
            y /= a;
        }
        hantei = true;
        p = changed.size();
        for(int i = 0; i < p; i++){
            if(changed[i] != changed[p-1-i]) hantei = false;
        }
        if(hantei && x <= n) ans += x;
        return;
    }

    for(int i = 0; i <= 9; i++){
        ten[k] = i;
        solve(k+1,ten);
    }
    return;
}


int main(){
    cin >> a >> n;
    ll d = 0, e = n;
    while(e > 0){
        d++;
        e/=10;
    }
    if(d%2 == 1) d++;
    vector<ll> ten(d/2);
    solve(0,ten);
    cout << ans << endl;
}