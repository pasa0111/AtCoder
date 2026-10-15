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
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(int i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}
#define adjvecin(vec) for(int i = 1, a = vec.size(); i < a; i++){cin >> vec.at(i);}


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    ll n,a,b, ans = 0;
    string s;
    cin >> n >> a >> b >> s;
    vector<ll> A(n),B(n);
    rep(i,n){
        if(s.at(i) == 'a'){A.at(i)++;}
        if(s.at(i) == 'b'){B.at(i)++;}
        if(i >= 1){
            A.at(i) += A.at(i-1);
            B.at(i) += B.at(i-1);
        }
    }
    int p = 0, q = 0;
    while(A.at(p) != a){
        p++;
        if(p == n){
            p = -1;
            break;
        }
    }
    while(B.at(q) != b){
        q++;
        if(q == n){break;}
    }
    if(q > p && p != -1){ans += q-p;}
    if(p != -1){
    for(int l = 1; l < n; l++){
        if(s.at(l-1) == 'a' && p < n){
            while(A.at(p)-A.at(l-1) != a){
                p++;
                if(p == n){break;}
            }
        }
        if(s.at(l-1) == 'b' && q < n){
            while(B.at(q)-B.at(l-1) != b){
                q++;
                if(q == n){break;}
            }
        }
        if(p == n){break;}
        if(q < n){
            if(q > p && A.at(p)-A.at(l-1) == a && B.at(q)-B.at(l-1) == b){ans += q-p;}
        }
        if(q == n){
            if(q > p && A.at(p)-A.at(l-1) == a){ans += q-p;}
        }
    }
    }
    cout << ans << endl;
}