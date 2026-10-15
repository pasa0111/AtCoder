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

ll f(ll k, map<ll,ll> &memo){
    if(!memo.count(k)){
        memo[k] = f(k/2,memo) + f(k/3,memo);
    }
    return memo[k];
}

int main(){
    ll N;
    cin >> N;
    map<ll,ll> memo;
    memo[0] = 1;
    cout << f(N,memo) << endl;
}