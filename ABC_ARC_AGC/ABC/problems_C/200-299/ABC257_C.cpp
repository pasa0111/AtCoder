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
#define MP make_pair
#define MT make_tuple

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int n;
    string S;
    cin >> n >> S;
    vector<pair<int,int>> W(n); //(体重,大人か子供か)
    map<int,int> adult,child; //(座標,人数)
    rep(i,n){
        cin >> W[i].first;
        W[i].second = S[i]-'0';
    }
    SORT(W);
    W.push_back(MP(W[n-1].first+5, 0));
    int save = 0;
    rep(i,n){
        if(!adult.count(W[i].first)) adult[W[i].first] = 0;
        if(!child.count(W[i].first)) child[W[i].first] = 0;
        if(W[i].second == 0) save++;
        if(W[i].first != W[i+1].first){
            child[W[i+1].first] += save;
            save = 0;
        }
        if(W[i].second == 1) adult[W[i].first]++;
    }
    if(!adult.count(W[n].first)) adult[W[n].first] = 0;
    if(!child.count(W[n].first)) child[W[n].first] = 0;
    vector<pair<int,int>> Adult,Child; //(座標,人数)
    for(auto x:adult) Adult.push_back(x);
    for(auto x:child) Child.push_back(x);
    int m = Adult.size();
    for(int i = m-1; i >= 1; i--) Adult[i-1].second += Adult[i].second;
    for(int i = 1; i < m; i++) Child[i].second += Child[i-1].second;
    int ans = 0;
    for(int i = 0; i < m; i++) ans = max(ans,Adult[i].second+Child[i].second);
    /*
    for(auto x:Adult) cout << x.first << " ";
    cout << endl;
    for(auto x:Adult) cout << x.second << " ";
    cout << endl;
    for(auto x:Child) cout << x.first << " ";
    cout << endl;
    for(auto x:Child) cout << x.second << " ";
    cout << endl;
    */
    cout << ans << endl;
}