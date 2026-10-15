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
#define vecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < sizesizesize; i++){cin >> vec.at(i);}
#define sumvecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < sizesizesize; i++){cin >> vec.at(i); if(i > 0) vec[i] += vec[i-1];}
#define REVERSE(vec) reverse(vecall(vec))
#define SORT(vec) sort(vecall(vec))
#define RSORT(vec) SORT(vec); REVERSE(vec)
#define MP make_pair
#define MT make_tuple

template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p){os << "(" << p.first << ", " << p.second << ")";return os;}
template <typename T, typename U> pair<T, U> operator+(const pair<T, U> & l, const pair<T, U> & r){return {l.first + r.first, l.second + r.second};}


/*
g++ path -o a.out && ./a.out < ./input.txt
*/

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int n;
    cin >> n;
    map<int,pair<ll,ll>> M;
    ll ans = 0;
    ll f,s;
    pair<ll,ll> p = MP(0,0),q = MP(0,0);
    set<int> P,Q;
    rep(i,n){
        cin >> f >> s;
        if(p.second == s){
            P.insert(f);
        }
        if(q.second < s && s < p.second && p.first != f){
            Q.clear();
            Q.insert(f);
            q.second = s;
            q.first = f;
        }
        if(p.second < s && p.first != f){
            Q = P;
            P.clear();
            P.insert(f);
            q = p;
            p.first = f;
            p.second = s;
        }
        if(M[f].first < s){
            M[f].second = M[f].first;
            M[f].first = s;
        }
        if(M[f].second < s && s < M[f].first) M[f].second = s;
        if(M[f].second != 0) ans = max(ans,M[f].first + M[f].second/2);
    }
    //cout << MP(p,q) << endl;
    if(P.size() > 1) ans = max(ans,p.second*2);
    for(int i:P){
        for(int j:Q){
            if(i != j){
                ans = max(ans,p.second + q.second);
                break;
            }
        }
    }
    if(q.second != 0) ans = max(ans,p.second + q.second);
    cout << ans << endl;
}