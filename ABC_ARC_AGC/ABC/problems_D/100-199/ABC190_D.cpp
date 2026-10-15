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
#define MT make_tuple

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

bool is_prime(ll x){
    bool hantei = true;
    for(ll i = 2; i < sqrt(x)+2; i++){
        if(x % i == 0 && x != i) hantei = false;
    }
    return hantei;
}

int main(){
    ll n;
    cin >> n;
    while(n%2 == 0) n/=2;
    map<int,int> prime; //nを素因数分解したときの(x,xの指数)
    bool hantei = !is_prime(n);
    if(!hantei && n != 1)prime[n]++;
    //cout << n << endl;
    for(ll i = 3; i <= n && hantei; i++){
        //cout << "i:" << i << endl;
        if(is_prime(i)){
            bool changed = false;
            while(n % i == 0){
                changed = true;
                prime[i]++;
                n /= i;
            }
            if(changed){
                hantei = !is_prime(n);
                //cout << "hantei:" << hantei << endl;
            }
            if(!hantei && n != 1)prime[n]++;
            //cout << n << endl;
        }
    }
    ll ans = 1;
    for(auto x:prime){
        //cout << x.first << "," << x.second << endl;
        ans *= x.second+1;
    }
    cout << ans*2 << endl;
}