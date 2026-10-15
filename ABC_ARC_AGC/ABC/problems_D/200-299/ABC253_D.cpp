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

ll lcm(ll a,ll b){return a*b/gcd(a,b);}

int main(){
    ll n,a,b;
    cin >> n >> a >> b;
    ll p = n/a, q = n/b, r = n/lcm(a,b);
    if(a % b != 0 && b % a != 0){cout << n*(n+1)/2 - p*(p+1)/2*a - q*(q+1)/2*b + r*(r+1)/2*lcm(a,b) << endl;}
    if(a % b == 0 && b % a != 0){cout << n*(n+1)/2 - q*(q+1)/2*b << endl;}
    if(a % b != 0 && b % a == 0){cout << n*(n+1)/2 - p*(p+1)/2*a << endl;}
    if(a % b == 0 && b % a == 0){cout << n*(n+1)/2 - p*(p+1)/2*a << endl;}
}