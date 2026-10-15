#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>


using namespace std;
#define ll long long
#define rep(i,e) for(int i = 0; i < e; i++)
#define adjrep(i,s,e) for(ll i = s; i <= e; i++)
#define vall(vec) vec.begin(),vec.end()
#define vin(vec) for(int i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}
#define adjvin(vec) for(int i = 1, a = vec.size(); i < a; i++){cin >> vec.at(i);}


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}


//操作を繰り返してxを1まで変える時にかかるお金を計算
ll solve(ll x, map<ll,ll> &m){
    ll y = x/2, z = (x+1)/2;
    if(!m.count(y)){m[y] = solve(y,m);}
    if(!m.count(z)){m[z] = solve(z,m);}
    m[x] = x + m.at(y) + m.at(z);
    return m.at(x);
}

int main(){
    ll N;
    cin >> N;
    map<ll,ll> m; //m[i] = solve(i)
    m[1] = 0;
    m[2] = 2;
    cout << solve(N,m) << endl;
}