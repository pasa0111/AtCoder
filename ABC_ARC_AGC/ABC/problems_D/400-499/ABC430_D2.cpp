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
#define SORT(vec) sort(vecall(vec))
#define RSORT(vec) SORT(vec);reverse(vecall(vec));
#define MP make_pair
#define MT make_tuple

template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p){os << "(" << p.first << ", " << p.second << ")";return os;}
template <typename T, typename U> pair<T, U> operator+(const pair<T, U> & l, const pair<T, U> & r){return {l.first + r.first, l.second + r.second};}


/*
g++ ABC/problems_D/401-500/ABC430_D2.cpp -o a.out && ./a.out < ./input.txt
*/

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    const ll inf = 10000000000;
    ll n;
    cin >> n;
    multiset<pair<ll,ll>> M; //(座標,最短距離)
    M.insert(MP(0,inf));
    ll x, sum = inf;
    rep(i,n){
        cin >> x;
        // s < q < x < p < r
        auto p = M.upper_bound(MP(x,0));
        auto q = p;
        q--;

        pair<ll,ll> s = *q,r = *p;
        //cout << MP(*q,*p) << endl;
        if(p != M.end()){
            //cout << "end" << endl;
            if((*p).second > (*p).first-x){
                //cout << "a" << endl;
                sum = sum - (*p).second + (*p).first - x;
                M.insert(MP((*p).first, (*p).first-x));
                M.erase(*p);
                //cout << sum << endl;
            }
        }

        if((*q).second > x-(*q).first){
            //cout << "b" << endl;
            sum = sum - (*q).second + x-(*q).first;
            M.insert(MP((*q).first, x-(*q).first));
            M.erase(*q);
            //cout << sum << endl;
        }


        if(p != M.end()){
            //cout << "c" << endl;
            sum += min(r.first-x, x-s.first);
            //cout << r.first-x << "   " << x-s.first << endl;
            M.insert(MP(x,min(r.first-x, x-s.first)));
            //cout << sum << endl;
        }

        if(p == M.end()){
            //cout << "d" << endl;
            sum += x-s.first;
            M.insert(MP(x,x-s.first));
            //cout << sum << endl;
        }
        cout << sum << endl;
    }
}