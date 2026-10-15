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


int main(){
    string S;
    ll K,ans = 0, res = 1;
    cin >> S >> K;
    ll n = S.size();
    if(n == 1){ans = K/2;}
    if(n == 2){
        if(S.at(0) == S.at(1)){ans = K;}
        if(S.at(0) != S.at(1)){ans = 0;}
    }
    if(n >= 3){
        ll a=0,b=n-1;
        if(S.at(0) == S.at(n-1)){a = -1;}
        for(ll i = 0; i < n-1; i++){
            if(S.at(i) != S.at(i+1)){
                a = i+1;
                break;
            }
        }
        for(ll i = n-1; i >= 1; i--){
            if(S.at(i) != S.at(i-1)){
                b = i-1;
                break;
            }
        }
        if(a == -1){
            b = a;
            ans += n*K/2;
        }
        if(S.at(0) != S.at(n-1) && a != -1){ans += a/2*K + (n-1-b)/2*K;}
        if(S.at(0) == S.at(n-1) && a != -1){ans += a/2 + (n-1-b+a)/2*(K-1) + (n-1-b)/2;}
        for(ll i = b; i >= a+1; i--){
            if(S.at(i) == S.at(i-1)){res++;}
            if(S.at(i) != S.at(i-1)){
                ans += res/2*K;
                res = 1;
            }
        }
        ans += res/2*K;
    }
    cout << ans << endl;
}