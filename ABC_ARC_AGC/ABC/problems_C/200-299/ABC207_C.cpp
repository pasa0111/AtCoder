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
g++acl ABC/problems_C/201-300/ABC207_C.cpp -o a.out && ./a.out < ./input.txt
*/


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int n;
    cin >> n;
    map<ll,ll> M;
    int t,l,r;
    vector<ll> L;
    rep(i,n){
        cin >> t >> l >> r;
        l *= 2; r *= 2;
        if(t == 2 || t == 4)r--;
        if(t == 3 || t == 4)l++;
        M[l]++;
        M[r+1]--;
        L.push_back(l);
    }
    SORT(L);
    vector<pair<ll,ll>> V;
    int k = 0;
    for(auto m:M){
        V.push_back(m);
        if(k > 0) V[k].second += V[k-1].second;
        k++;
    }
    ll i = 0, f = 1;
    ll ans = 0, z = L.size();
    for(auto v:V){
       //cout << v << " ";
        f = 1;
        while(i < z && L[i] == v.first){
            ans += v.second-f;
            f++;
            i++;
        }
    }
    //cout << el;
    cout << ans << el;
}