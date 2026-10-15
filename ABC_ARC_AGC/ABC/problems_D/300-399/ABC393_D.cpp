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
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(int i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    ll n;
    string s;
    cin >> n >> s;
    ll lone = -1, rone = -1;
    rep(i,n){
        if(s.at(i) == '1' && lone == -1){lone = i;}
        if(s.at(i) == '1' && lone != -1){rone = i;}
    }
    ll ans = 0, p = lone+1, q = rone-1, l = 0, r = 0, left, right;
    while(p <= q){
        if(p < n && s.at(p) == '1'){
            p++;
            continue;
        }
        if(0 <= q && s.at(q) == '1'){
            q--;
            continue;
        }
        left = p-lone-l;
        right = rone-q-r;
        if(left == right){
            ans += left;
            p++;
            l++;
            continue;
        }
        if(left < right){
            //cout << "L:" << left << endl;
            ans += left;
            l++;
            p++;
            continue;
        }
        if(left > right){
            //cout << "R:" << right << endl;
            ans += right;
            r++;
            q--;
            continue;
        }
    }
    cout << ans << endl;
}
