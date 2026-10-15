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
    int n,q;
    cin >> n >> q;
    vector<ll> A(n),B(n);
    vecin(A);
    vecin(B);
    ll sum = 0;
    rep(i,n){sum += min(A.at(i),B.at(i));}
    rep(Q,q){
        char c;
        ll x,v;
        cin >> c >> x >> v;
        if(A.at(x-1) <= B.at(x-1)){sum -= A.at(x-1);}
        if(A.at(x-1) > B.at(x-1)){sum -= B.at(x-1);}
        if(c == 'A'){
            sum += min(v,B.at(x-1));
            A.at(x-1) = v;
        }
        if(c == 'B'){
            sum += min(A.at(x-1),v);
            B.at(x-1) = v;
        }
        cout << sum << endl;
    }
}