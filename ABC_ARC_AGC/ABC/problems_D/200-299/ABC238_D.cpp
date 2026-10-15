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
#include <atcoder/all>
using namespace atcoder;

using namespace std;
#define ll long long
#define rep(i,e) for(ll i = 0; i < e; i++)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < sizesizesize; i++){cin >> vec.at(i);}
#define sumvecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < sizesizesize; i++){cin >> vec.at(i); if(i > 0) vec[i] += vec[i-1];}
#define REVERSE(vec) reverse(vecall(vec))
#define SORT(vec) sort(vecall(vec))
#define RSORT(vec) SORT(vec); REVERSE(vec)
#define MP make_pair
#define MT make_tuple

template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p){os << "(" << p.first << ", " << p.second << ")";return os;}
template <typename T, typename U> pair<T, U> operator+(const pair<T, U> & l, const pair<T, U> & r){return {l.first + r.first, l.second + r.second};}

constexpr char el = '\n';

/*
g++acl ABC/problems_D/201-300/ABC238_D.cpp -o a.out && ./a.out < ./input.txt
*/


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int T; cin >> T;
    bitset<64> a,s;
    ll A,S;
    rep(test,T){
        cin >> A >> S;
        a = A;
        s = S;
        bool up = false, ans = true;
        for(int i = 0; i < 61; i++){
            if(a[i] == 0){
                if(s[i] == 0){

                }
                if(s[i] == 1){
                    up = false;
                }
            }
            if(a[i] == 1){
                if(s[i] == 0 && up) ans = false;
                if(s[i] == 1 && !up) ans = false;
                up = true;
            }
        }
        if(up) ans = false;
        yesno(ans);
    }
}