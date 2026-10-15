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
    if(n == 1){
        if(s == "a" && a <= 1 && b >= 1){ans++;}
    }
    if(n >= 2){
    for(ll l = 0; l < n; l++){
        ll p = -10,q = -10,start = l-2, end = n,k = a-1,o,m = b-1;
        while(k != a){
            o = p;
            p = (start+end)/2;
            if(p == o){break;}

            if(l != 0){
                k = A.at(p)-A.at(l-1);
                if(k > a){end = p;}
                if(k < a){start = p;}
            }
            if(l == 0){
                k = A.at(p);
                if(k > a){end = p;}
                if(k < a){start = p;}
            }
        }
        if(k == a){
            while(s.at(p) != 'a'){p--;}
        }
        start = l-1;
        end = n-1;
        while(m != b){
            o = q;
            q = (start+end)/2;
            if(q == o){break;}
            if(l != 0){
                m = B.at(q)-B.at(l-1);
                if(m > b){end = q;}
                if(m < b){start = q;}
            }
            if(l == 0){
                m = B.at(q);
                if(m > b){end = q;}
                if(m < b){start = q;}
            }
        }
        if(m == b){
            while(s.at(q) != 'b'){q--;}
        }
        if(k == a && m == b && q >= p){ans += q-p;}
    }
    }
    cout << ans << endl;
}