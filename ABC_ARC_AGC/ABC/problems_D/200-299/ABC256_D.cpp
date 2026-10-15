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
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(int i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int> S(200002); //整数iがいずれかの区間に含まれる <-> S.at(i) > 0
    rep(i,n){
        int l,r;
        cin >> l >> r;
        S.at(l)++;
        S.at(r)--;
    }
    rep(i,200001){S.at(i+1) += S.at(i);}
    //cout << endl;
    int x=0,y=0;
    for(int i = 1; i <= 200000; i++){
        if(x == 0 && S.at(i) > 0){x = i;}
        if(x > 0 && S.at(i) == 0){
            y = i;
            cout << x << " " << y << endl;
            x = 0;
        }
    }
}