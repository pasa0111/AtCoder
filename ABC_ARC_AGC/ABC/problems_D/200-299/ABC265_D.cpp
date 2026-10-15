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
    ll n,p,q,r,x = 0,y = 1,z = 2,w = 3;
    cin >> n >> p >> q >> r;
    vector<ll> A(n);
    sumvecin(A);
    bool ans = false;
    while(w <= n){
        //cout << "(x,y,z,w) = (" << x << "," << y << "," << z << "," << w << ")" << endl;
        while(y < n && ((x > 0 && A[y-1]-A[x-1] < p) || (x == 0 && A[y-1] < p))) y++;
        if(y > n-2) break;
        if((x > 0 && A[y-1]-A[x-1] > p) || (x == 0 && A[y-1] > p)){
            x++;
            continue;
        }
        if((x > 0 && A[y-1]-A[x-1] == p) || (x == 0 && A[y-1] == p)){
            while(z < n && A[z-1]-A[y-1] < q) z++;
            if(A[z-1]-A[y-1] > q){
                x++;
                continue;
            }
            if(A[z-1]-A[y-1] == q){
                while(w < n && A[w-1]-A[z-1] < r) w++;
                if(A[w-1]-A[z-1] > r){
                    x++;
                    continue;
                }
                if(A[w-1]-A[z-1] == r){
                    //cout << "(x,y,z,w) = (" << x << "," << y << "," << z << "," << w << ")" << endl;
                    ans = true;
                    break;
                }
            }
        }
    }
    yesno(ans);
}