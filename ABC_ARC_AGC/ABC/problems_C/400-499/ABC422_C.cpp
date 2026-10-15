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
    int T;
    cin >> T;
    rep(t,T){
        ll a,b,c;
        cin >> a >> b >> c;
        ll start = -1, end = a+b+c+1, m = min(a,c), M = a+b+c, o = -10, k = -10, l = -10;
        while(true){
            o = k;
            k = (start+end)/2;
            if(o == k){break;}
            if(k <= m){start = k;}
            if(k > m){end = k;}
        }
        start = -1;
        end = a+b+c+1;
        while(true){
            o = l;
            l = (start+end)/2;
            if(o == l){break;}
            if(3*l <= M){start = l;}
            if(3*l > M){end = l;}
        }
        if(k <= m && 3*l <= M){cout << min(k,l) << endl;}
        else{cout << 0 << endl;}
    }
}