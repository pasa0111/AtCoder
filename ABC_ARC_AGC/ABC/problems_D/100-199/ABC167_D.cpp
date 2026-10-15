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
#define vecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < sizesizesize; i++){cin >> vec.at(i);}
#define sumvecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < sizesizesize; i++){cin >> vec.at(i); if(i > 0) vec[i] += vec[i-1];}
#define SORT(vec) sort(vecall(vec))
#define RSORT(vec) SORT(vec);reverse(vecall(vec));
#define MP make_pair
#define MT make_tuple


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    ll n,k;
    cin >> n >> k;
    vector<ll> A(n+1);
    for(int i = 1; i <= n; i++) cin >> A[i];
    set<int> visited;
    vector<int> route;
    int now = 1;
    visited.insert(1);
    route.push_back(1);
    rep(i,k){
        if(visited.count(A[now])){
            now = A[now];
            break;
        }
        if(!visited.count(A[now])){
            route.push_back(A[now]);
            visited.insert(A[now]);
            now = A[now];
        }
    }
    vector<int> loop_route;
    ll go = 0;
    for(unsigned ll i = 0; i < route.size(); i++){
        if(route[i] == now){
            go = i;
            for(unsigned ll j = i; j < route.size(); j++){
                loop_route.push_back(route[j]);
            }
        }
    }
    ll loop = loop_route.size();
    cout << loop_route[(k-go)%loop] << endl;
}