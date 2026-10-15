#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <iomanip>


using namespace std;
#define ll long long
#define rep(i,e) for(int i = 0; i < e; i++)
#define adrep(i,s,e,k) for(int i = s; i <= e; i+=k)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(int i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

ll f(ll k, ll &n, vector<pair<set<ll>,set<ll>>> &R, vector<ll> &V){
    //cout << "k: " << k << endl;
    if(k == 1){return V.at(1);}

    if(V.at(k) == 0){
        ll res = 0;
        bool hantei = true;
        for(ll r:R.at(k).first){
            if(f(r,n,R,V) != -1){
                res = max(res,f(r,n,R,V)+100);
                hantei = false;
            }
        }
        for(ll r:R.at(k).second){
            if(f(r,n,R,V) != -1){
                res = max(res,f(r,n,R,V)+150);
                hantei = false;
            }
        }
        if(hantei){res = -1;}
        V.at(k) = res;
    }

    return V.at(k);
}

int main(){
    ll n;
    cin >> n;
    vector<ll> V(n+1);
    vector<pair<set<ll>,set<ll>>> R(n+1);
    rep(i,n-1){
        ll a;
        cin >> a;
        R.at(a).first.insert(i+1);
    }
    rep(i,n-1){
        ll b;
        cin >> b;
        R.at(b).second.insert(i+1);
    }
    V.at(1) = 0;
    cout << f(n,n,R,V) << endl;
}