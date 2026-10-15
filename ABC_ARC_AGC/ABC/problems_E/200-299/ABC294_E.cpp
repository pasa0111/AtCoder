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
    ll L,N1,N2;
    cin >> L >> N1 >> N2;
    vector<ll> V1(N1),V2(N2),L1(N1),L2(N2);
    rep(i,N1){cin >> V1[i] >> L1[i];}
    rep(i,N2){cin >> V2[i] >> L2[i];}
    ll k1 = 0, p1 = L1[0],k2 = -1, p2 = 0, ans = 0;
    while(k1 < N1 && k2 < N2){
        while(p2 <= p1){
            k2++;
            if(k2 == N2){break;}
            p2 += L2[k2];
            if(V1[k1] == V2[k2]){
                ans += min(p1,p2)-max(p1-L1[k1]+1,p2-L2[k2]+1)+1;
            }
        }
        while(p2 > p1){
            k1++;
            if(k1 == N1){break;}
            p1 += L1[k1];
            if(V1[k1] == V2[k2]){
                ans += min(p1,p2)-max(p1-L1[k1]+1,p2-L2[k2]+1)+1;
            }
        }
    }
    cout << ans << endl;
}