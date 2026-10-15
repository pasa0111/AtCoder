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


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    string S,T;
    cin >> S >> T;
    int t = T.size(), s = S.size();
    bool left = true;
    int right = -1;
    for(int i = s-1; i >= s-t; i--){
        if(T[t-s+i] != S[i] && T[t-s+i] != '?' && S[i] !='?'){
            right = i;
            break;
        }
    }
    yesno(right == -1);
    for(int x = 1; x <= t; x++){
        if(T[x-1] != S[x-1] && T[x-1] != '?' && S[x-1] != '?'){left = false;}
        yesno(right < s-t+x && left);
    }
}