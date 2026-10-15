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
    int n, a, m = 0, M = 0;
    cin >> n;
    vector<int> V(9);
    rep(i,n){
        cin >> a;
        a /= 400;
        if(a >= 8){a = 8;}
        V.at(a)++;
    }
    rep(i,8){if(V.at(i) > 0){m++;}}
    M = m + V.at(8);
    cout << max(m,1) << " " << M << endl;
}