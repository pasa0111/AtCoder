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
g++ ABC/problems_D/401-500/ABC430_D.cpp -o a.out && ./a.out < ./input.txt
*/

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    ll n;
    cin >> n;
    multiset<ll> M;
    M.insert(0);
    ll x, sum = 0;
    rep(i,n){
        cin >> x;
        // s < q < x < p < r
        auto p = M.upper_bound(x);
        auto q = p;
        if(q != M.begin())q--;
        auto r = p, s = q;
        if(p != M.end()) r++;
        if(q != M.begin())s--;

        //qの調整 s < q < x < p
        //cout << "q:" << *q << endl;
        if(s != q && q != p && p != M.end()){
            if(*p-*q >= *q-*s){
                //cout << "a" << endl;
                sum -= min(*q-*s,*p-*q);
                sum += min(*q-*s,x-*q);
            }
            if(*p-*q < *q-*s){
                //cout << "b" << endl;
                sum -= *p-*q;
                sum += x-*q;
            }
        }
        // 0 < x < p
        if(q == M.begin()){
            if(p != M.end()){
                //cout << "d" << endl;
                sum -= *p;
                sum += x;
            }
        }
        //xが最大値
        if(p == M.end()){
            //s < q < x
            if(s != q){
                //cout << "e" << endl;
                sum -= *q-*s;
                sum += min(*q-*s,x-*q);
            }

            //0 < x
            if(q == M.begin()){
                //cout << "f" << endl;
                sum += x;
            }
        }

        //pの調整
        if(q != p && p != r && r != M.end()){
            sum -= min(*r-*p, *p-*q);
            sum += min(*r-*p, *p-x);
            /*if(*p-*q <= *r-*p){
                cout << "g" << endl;
                sum -= *p-*q;
                sum += *p-x;
            }
            if(*p-*q > *r-*p){
                cout << "h" << endl;
                sum -= max(*p-x,*r-*p);
                sum += min(*p-x,*r-*p);
            }*/
        }
        //pが最大値 q < x < p
        if(r == M.end() && p != M.end()){
            //cout << "i" << endl;
            sum -= *p-*q;
            sum += *p-x;
        }
        if(p == M.end()) sum += x-*q;
        if(p != M.end()) sum += min(*p-x, x-*q);
        M.insert(x);
        cout << sum << endl;
        //cout << endl;
    }
}