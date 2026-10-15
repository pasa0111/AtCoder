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

//aとbの最大公約数を返す
ll gcd(ll a, ll b){
    ll r,A=max(a,b),B=min(a,b);
    r = A%B;
    while(r != 0){
        A = B;
        B = r;
        r = A%B;
    }
    return B;
}

int main(){
    ll n;
    cin >> n;
    set<pair<ll,ll>> spell;
    vector<pair<ll,ll>> town(n);
    rep(i,n)cin >> town[i].first >> town[i].second;
    
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            ll x = town[j].first-town[i].first, y = town[j].second-town[i].second;
            if(x == 0){
                spell.insert(MP(0,1));
                spell.insert(MP(0,-1));
                continue;
            }
            if(y == 0){
                spell.insert(MP(1,0));
                spell.insert(MP(-1,0));
                continue;
            }
            ll g = gcd(abs(x),abs(y));
            x /= g;
            y /= g;
            spell.insert(MP(x,y));
            spell.insert(MP(-x,-y));
        }
    }
    cout << spell.size() << endl;
}