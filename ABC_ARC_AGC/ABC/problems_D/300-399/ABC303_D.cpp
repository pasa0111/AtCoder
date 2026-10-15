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
#define rep(i,e) for(ll i = 0; i < e; i++)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(unsigned ll i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}
#define SORT(vec) sort(vecall(vec))
#define RSORT(vec) SORT(vec);reverse(vecall(vec));


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    ll x,y,z,n;
    string S;
    cin >> x >> y >> z >> S;
    n = S.size();
    vector<vector<ll>> table(2,vector<ll>(n+1));
    table[0][0] = 0;
    table[1][0] = z;
    for(ll i = 0; i < n; i++){
        if(S[i] == 'a'){
            table[0][i+1] = min({table[0][i]+x, table[1][i]+z+x, table[1][i]+y+z});
            table[1][i+1] = min({table[0][i]+x+z, table[0][i]+z+y, table[1][i]+y});
        }
        if(S[i] == 'A'){
            table[0][i+1] = min({table[0][i]+y, table[1][i]+z+y, table[1][i]+x+z});
            table[1][i+1] = min({table[0][i]+y+z, table[0][i]+z+x, table[1][i]+x});
        }
    }
    cout << min(table[0][n],table[1][n]) << endl;
}