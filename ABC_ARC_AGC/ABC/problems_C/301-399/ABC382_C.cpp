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
#define adrep(i,s,e,k) for(ll i = s; i <= e; i+=k)
#define rerep(i,s,e,k) for(ll i = s; i >= e; i-=k)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(ll i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> P(n); //(Aの要素,Aにおけるインデックス)
    rep(i,n){
        cin >> P[i].first;
        P[i].second = i+1;
    }
    sort(vecall(P));
    rep(i,m){
        int b,start = -1, end = n, t = -10, u;
        cin >> b;
        while(start != end){
            u = t;
            t = (start+end)/2;
            if(t == u){break;}
            if(P[t].first < b){start = t;}
            if(P[t].first > b){end = t;}
        }
        int q = n+1;
        while(P[t].first >= b){
            t--;
            if(P[t].first >= b){q = min(P[t].second,q);}
            if(P[t].first < b){
                t++;
                break;
            }
        }
        if(P[t].first >= b){cout << P[t].second << endl;}
        if(P[t].first < b){cout << -1 << endl;}
    }
}