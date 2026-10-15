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
#include <cctype>


using namespace std;
#define ll long long
#define rep(i,e) for(ll i = 0; i < e; i++)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(ll i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}
#define sumvecin(vec) for(ll i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i); if(i > 0) vec[i] += vec[i-1];}
#define SORT(vec) sort(vecall(vec))
#define RSORT(vec) SORT(vec);reverse(vecall(vec));
#define MP make_pair
#define MT make_tuple

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    ll x;
    cin >> x;
    vector<ll> five(200), mfive(200);
    for(ll i = 0; i <= 200; i++){
        five[i] = i*i*i*i*i;
        mfive[i] = -i*i*i*i*i;
    }
    pair<ll,ll> ans = MP(0,0);
    for(int a = 0; a < 200; a++){
        for(int b = 0; b < 200; b++){
            if(five[a]-five[b] == x) ans = MP(a,b);
        }
        for(int b = 0; b < 200; b++){
            if(five[a]-mfive[b] == x) ans = MP(a,-b);
        }
    }
    cout << ans.first << " " << ans.second << endl;
}