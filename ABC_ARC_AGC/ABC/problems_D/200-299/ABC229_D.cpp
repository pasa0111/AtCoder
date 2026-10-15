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
#include <cctype>


using namespace std;
#define ll long long
#define rep(i,e) for(ll i = 0; i < e; i++)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(ll i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}
#define sumvecin(vec) for(ll i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i); if(i > 0) vec[i] += vec[i-1];}
#define SORT(vec) sort(vecall(vec))
#define RSORT(vec) SORT(vec);reverse(vecall(vec));
#define MP make_pair
#define MT make_tuple



void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}


int main(){
    string S;
    cin >> S;
    int n = S.size(),k;
    cin >> k;
    int x = 0, dot = 0, ans = 0, j = 0;
    for(int i = 0; i < n; i++){
        if(S[i] == '.') dot++;
        if(S[i] == 'X') x++;
        if(dot <= k) ans = max(ans,dot+x);
        if(dot == k+1){
            while(j <= i && dot == k+1){
                if(S[j] == 'X') x--;
                if(S[j] == '.') dot--;
                j++;
            }
            if(dot <= k && j <= i) ans = max(ans,dot+x);
        }
    }
    cout << ans << endl;
}