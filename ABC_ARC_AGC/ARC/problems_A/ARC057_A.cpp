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
    ll A,K,w,ans=0;
    cin >> A >> K;
    w = 2*1000000000000;
    if(K == 0){ans = w-A;}
    if(K > 0){
        w = K*2*1000000000000;
        A = A*K+1;
        while(A < w){
            A *= K+1;
            ans++;
        }
    if(A-1 < w){ans++;}
    }
    cout << ans << endl;
}