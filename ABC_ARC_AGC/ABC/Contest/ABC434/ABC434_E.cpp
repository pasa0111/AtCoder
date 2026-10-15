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
    map<ll,ll> rabbit; //(座標,個体数)
    int n, ans = 0;
    cin >> n;
    rep(i,n){
        int x,r;
        cin >> x >> r;
        if(rabbit.count(x+r)){
            if(rabbit.count(x-r)) rabbit.at(x+r)++;
            if(!rabbit.count(x-r)){
                rabbit[x-r] = 1;
                ans++;
            }
        }
        if(!rabbit.count(x+r)){
            rabbit[x+r] = 1;
            ans++;
        }
    }
    cout << ans << endl;
}