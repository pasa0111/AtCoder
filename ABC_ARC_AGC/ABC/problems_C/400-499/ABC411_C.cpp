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
//#include <atcoder/all>

//using namespace atcoder;
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
g++ ABC/problems_C/401-500/ABC411_C.cpp -o a.out && ./a.out < ./input.txt
*/


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int n,Q;
    cin >> n >> Q;
    vector<bool> isblack(n+2,false);
    ll ans = 0;
    ll a;
    rep(query,Q){
        cin >> a;
        if(isblack[a]){
            isblack[a] = false;
            if(isblack[a+1] && isblack[a-1]) ans++;
            if(!isblack[a+1] && !isblack[a-1]) ans--;
            cout << ans << el;
            continue;
        }
        if(!isblack[a]){
            isblack[a] = true;
            if(isblack[a+1] && isblack[a-1]) ans--;
            if(!isblack[a+1] && !isblack[a-1]) ans++;
            cout << ans << el;
        }
    }
}