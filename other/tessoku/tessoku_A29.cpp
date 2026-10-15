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
#define rep(i,e) for(int i = 0; i < e; i++)
#define adrep(i,s,e,k) for(int i = s; i <= e; i+=k)
#define rerep(i,s,e,k) for(int i = s; i >= e; i-=k)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(int i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}


//a^bを1000000007で割った余りを計算
ll f(ll &a, ll b){
    ll c = a;
    //cout << a << "    " << b << endl;
    if(b == 0){return 1;}
    if(b == 1){return a;}
    ll p = 0, q = 1;
    while(q <= b){
        p++;
        q *= 2;
    }
    p--;
    q /= 2;
    rep(i,p){
        c *= c;
        c %= 1000000007;
    }
    c *= f(a,b-q);
    c %= 1000000007;
    //cout << "f(" << a << "," << b << ") = " << c << endl;
    return c;
}

int main(){
    ll a,b,c,k = 1000000007;
    cin >> a >> b; 
    c = a;
    cout << f(a,b) << endl;
}