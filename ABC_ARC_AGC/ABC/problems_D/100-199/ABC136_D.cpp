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
    string S;
    cin >> S;
    int n = S.size();
    vector<int> ans(n);
    int start = 0, k = 0;
    while(k < n){
        int x = 0, y = 0;
        while(S[k] == 'R'){
            if((k-start)%2 == 0){x++;}
            else{y++;}
            k++;
        }
        if((k-start)%2 == 0){
            ans[k] += x;
            ans[k-1] += y;
        }
        if((k-start)%2 == 1){
            ans[k-1] += x;
            ans[k] += y;
        }
        start = k;
        while(k < n && S[k] == 'L'){
            ans[start-((k-start)%2)]++;
            k++;
        }
        start = k;
    }
    rep(i,n){cout << ans[i] << " ";}
    cout << endl;
}