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
    int T;
    cin >> T;
    rep(t,T){
        ll n,k,p,sum = 0;
        cin >> n >> k;
        p = n;
        while(p > 0){
            sum += p % 3;
            p /= 3;
        }
        if(k >= sum && (k-sum) % 2 == 0){yesno(true);}
        else{yesno(false);}
    }
}