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

int main(){
    ll n,m;
    cin >> n >> m;
    set<pair<int,int>> S;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        S.insert(make_pair(a,b));
        if(a+2 <= n){
            if(b+1 <= n){S.insert(make_pair(a+2,b+1));}
            if(b-1 >= 1){S.insert(make_pair(a+2,b-1));}
        }
        if(a+1 <= n){
            if(b+2 <= n){S.insert(make_pair(a+1,b+2));}
            if(b-2 >= 1){S.insert(make_pair(a+1,b-2));}
        }
        if(a-1 >= 1){
            if(b+2 <= n){S.insert(make_pair(a-1,b+2));}
            if(b-2 >= 1){S.insert(make_pair(a-1,b-2));}
        }
        if(a-2 >= 1){
            if(b+1 <= n){S.insert(make_pair(a-2,b+1));}
            if(b-1 >= 1){S.insert(make_pair(a-2,b-1));}
        }
    }
    ll k = S.size();
    cout << n*n - k << endl;
}