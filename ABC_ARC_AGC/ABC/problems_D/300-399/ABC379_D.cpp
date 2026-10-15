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

/*
g++ ./ABC/problems_D/301-400/ABC379_D.cpp  -o a.out && ./a.out < ./input.txt
*/


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int Q;
    cin >> Q;
    map<ll,ll> plant; //(植えられた時刻,個数)を保存
    ll time = 0;
    rep(query,Q){
        int x,T,H;
        cin >> x;
        if(x == 1) plant[time]++;
        if(x == 2){
            cin >> T;
            time += T;
        }
        if(x == 3){
            cin >> H;
            ll ans = 0;
            map<ll,ll> copy = plant;
            for(auto &p:plant){
                if(time-p.first >= H){
                    ans += p.second;
                    p.second = 0;
                    copy.erase(p.first);
                }
            }
            plant = copy;
            cout << ans << endl;
        }
    }
}