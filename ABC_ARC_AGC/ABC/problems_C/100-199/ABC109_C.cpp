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
#define adjrep(i,s,e) for(ll i = s; i <= e; i++)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(int i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}
#define adjvecin(vec) for(int i = 1, a = vec.size(); i < a; i++){cin >> vec.at(i);}


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    ll n,x,d;
    bool ans = true;
    cin >> n >> x;
    vector<ll> X(n);
    vecin(X);
    if(n == 1){d = abs(x-X.at(0));}
    if(n >= 2){
        for(ll k = 1; k <= abs(X.at(1)-X.at(0)); k++){
            ans = false;
            if(abs(X.at(1)-X.at(0)) % k == 0){
                ans = true;
                d = abs(X.at(1)-X.at(0))/k;
                rep(i,n){
                    if(X.at(i)%d != x%d){ans = false;}
                }
            }
            if(ans){break;}
        }
    }
    cout << d << endl;
}