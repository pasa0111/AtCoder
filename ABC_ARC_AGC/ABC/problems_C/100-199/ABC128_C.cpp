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
#define rep(i,t) for(int i = 0; i < t; i++)
#define adrep(i,s,e,k) for(int i = s; i <= e; i+=k)
#define rerep(i,s,e,k) for(int i = s; i >= e; i-=k)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(int i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> K(m);
    vector<vector<int>> S(m);
    vector<int> P(m);
    //i:電球の番号
    rep(i,m){
        cin >> K.at(i);
        //j:電球iに関係するスイッチ
        rep(j,K.at(i)){
            int s;
            cin >> s;
            S.at(i).push_back(s-1);
        }
    }
    vecin(P);
    int ans = 0;

    //i:onにするスイッチのパターンを二進法で表記
    for(int i = 0; i < (1 << n); i++){
        bitset<10> sw(i);
        //cout << sw << endl;
        bool b = true;
        //j:電球の番号
        rep(j,m){
            int q = 0;
            //a:電球jに関係するスイッチの番号
            rep(a,K.at(j)){
                if(sw.test(S.at(j).at(a))){q++;}
            }
            if(q % 2 != P.at(j)){b = false;}
        }
        if(b){
            //cout << "ok: i = " << i << endl;
            ans++;
        }
    }
    cout << ans << endl;
}