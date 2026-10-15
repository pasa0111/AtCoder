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
#include <cctype>


using namespace std;
#define ll long long
#define rep(i,e) for(ll i = 0; i < e; i++)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(ll i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}
#define sumvecin(vec) for(ll i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i); if(i > 0) vec[i] += vec[i-1];}
#define SORT(vec) sort(vecall(vec))
#define RSORT(vec) SORT(vec);reverse(vecall(vec));
#define MP make_pair
#define MT make_tuple

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int n,r,c;
    string S;
    cin >> n >> r >> c >> S;
    string ans = "";
    set<pair<int,int>> smoke;
    pair<int,int> O = MP(0,0);
    smoke.insert(MP(0,0));
    rep(i,n){
        if(S[i] == 'N'){
            O.first++;
        }
        if(S[i] == 'W'){
            O.second++;
        }
        if(S[i] == 'S'){
            O.first--;
        }
        if(S[i] == 'E'){
            O.second--;
        }
        smoke.insert(O);
        if(smoke.count(MP(O.first+r,O.second+c))) ans += '1';
        if(!smoke.count(MP(O.first+r,O.second+c))) ans += '0';
    }
    cout << ans << endl;
}