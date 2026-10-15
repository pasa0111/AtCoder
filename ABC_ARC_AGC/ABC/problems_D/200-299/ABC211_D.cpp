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
g++ path -o a.out && ./a.out < ./input.txt
*/

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    const ll K = 1000000007, inf = 10000000000;
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> city(n+1);
    rep(i,m){
        ll a,b;
        cin >> a >> b;
        city[a].push_back(b);
        city[b].push_back(a);
    }
    //(時間,都市,経路数)
    priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>, greater<tuple<ll,ll,ll>>> will;
    vector<pair<ll,ll>> path(n+1,MP(0,inf)); //1 --> iの(移動経路数,時間)
    will.push(MT(0,1,1));
    while(will.size() > 0){
        ll t = get<0>(will.top()), p = get<2>(will.top()), now = get<1>(will.top());
        will.pop();
        while(will.size() > 0 && get<1>(will.top()) == now && get<0>(will.top()) == t){
            p += get<2>(will.top());
            will.pop();
        }
        //cout << "time:" << t <<  "   now:" << now << "   path:" << p << endl;
        p %= K;
        if(path[now].second >= t)path[now] = MP(p,t);
        for(ll next:city[now]){
            if(path[next].second == inf){
                will.push(MT(t+1,next,p));
                //cout << "push:(" << t+1 << "," << next << "," << p << ")" << endl; 
            }
        }
    }
    cout << path[n].first % K << endl;
}