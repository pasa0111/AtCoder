#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <iomanip>


using namespace std;
#define ll long long
#define rep(i,e) for(int i = 0; i < e; i++)
#define adrep(i,s,e,k) for(int i = s; i <= e; i+=k)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(int i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}

/*
g++ ABC/problems_D/301-400/ABC323_D.cpp -o a.out && ./a.out < ./input.txt
*/


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int n;
    cin >> n;
    map<ll,ll> num; //num.at(i) = サイズiのスライムの数
    rep(i,n){
        int s,c;
        cin >> s >> c;
        num[s] = c;
    }
    for(auto &i:num){
        if(i.second >= 2){
            if(!num.count(i.first*2)){num[i.first*2] = 0;}
            num.at(i.first*2) += i.second/2;
            i.second -= i.second/2*2;
        }
    }
    ll ans = 0;
    for(auto &i:num){ans += i.second;}
    cout << ans << endl;
}