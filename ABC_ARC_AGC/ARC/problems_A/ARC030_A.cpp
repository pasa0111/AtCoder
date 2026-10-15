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
    if(b) cout << "YES" << endl;
    if(!b) cout << "NO" << endl;
}

int main(){
    int n,k,m;
    bool ans;
    cin >> n >> k;
    if(n % 2 == 0){
        m = n/2; //n = 2m
        if(k <= m){ans = true;}
        else{ans = false;}
    }
    if(n % 2 == 1){
        m = n/2; //n = 2m+1
        if(k <= m){ans = true;}
        else{ans = false;}
    }
    yesno(ans);
}