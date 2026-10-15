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
#define adrep(i,s,e,k) for(int i = s; i <= e; i+=k)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(int i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    ll n,a,b;
    cin >> n >> a >> b;
    double ave = 0;
    double m=1000000001,M=-1;
    rep(i,n){
        double s;
        cin >> s;
        ave += s;
        m = min(s,m);
        M = max(s,M);
    }
    double N = n;
    ave /= N;
    if(m == M){cout << -1 << endl;}
    cout << fixed << setprecision(10);
    if(m < M){
        cout << b/(M-m) << " " << a - (b*ave)/(M-m) << endl;
    }
}