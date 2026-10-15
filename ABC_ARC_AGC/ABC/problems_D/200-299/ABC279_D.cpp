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


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}


long double time(ll k, ll &A, ll &B){
    //cout << "k: " << k << endl;
    if(k <= -1){return 1e18;}
    return (long double)B*k+(long double)A*sqrt(1+k)/(1+k);
}

int main(){
    cout << fixed << setprecision(10);
    ll A,B;
    cin >> A >> B;
    long double point = pow(A/(2.0 * B), 2.0/3.0)-1;
    ll k_floor = (ll)floor(point);
    ll k_ceil = (ll)ceil(point);
    if(k_floor < 0){k_floor = 0;}
    if(k_ceil < 0){k_ceil = 0;}
    long double t = min(time(k_floor,A,B),time(k_ceil,A,B));
    cout << t << endl;
}