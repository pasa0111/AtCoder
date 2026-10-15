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
#define vecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < sizesizesize; i++){cin >> vec.at(i);}
#define sumvecin(vec) for(ll i = 0, sizesizesize = vec.size(); i < sizesizesize; i++){cin >> vec.at(i); if(i > 0) vec[i] += vec[i-1];}
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
    vector<ll> sumR(n), sumG(n), sumB(n), idR, idG, idB;
    rep(i,n){
        if(S[i] == 'R'){
            idR.push_back(i);
            sumR[i]++;
        }
        if(S[i] == 'G'){
            idG.push_back(i);
            sumG[i]++;
        }
        if(S[i] == 'B'){
            idB.push_back(i);
            sumB[i]++;
        }
        if(i > 0){
            sumR[i] += sumR[i-1];
            sumG[i] += sumG[i-1];
            sumB[i] += sumB[i-1];
        }
    }
    ll ans = 0;
    for(int i = 0; i < n-2; i++){
        if(S[i] == 'R'){
            for(int j:idG){
                if(j <= i) continue;
                if(2*j-i < n && S[2*j-i] == 'B') ans--;
                ans += sumB[n-1]-sumB[j];
            }
            for(int j:idB){
                if(j <= i) continue;
                if(2*j-i < n && S[2*j-i] == 'G') ans--;
                ans += sumG[n-1]-sumG[j];
            }
        }
        if(S[i] == 'G'){
            for(int j:idB){
                if(j <= i) continue;
                if(2*j-i < n && S[2*j-i] == 'R') ans--;
                ans += sumR[n-1]-sumR[j];
            }
            for(int j:idR){
                if(j <= i) continue;
                if(2*j-i < n && S[2*j-i] == 'B') ans--;
                ans += sumB[n-1]-sumB[j];
            }
        }
        if(S[i] == 'B'){
            for(int j:idR){
                if(j <= i) continue;
                if(2*j-i < n && S[2*j-i] == 'G') ans--;
                ans += sumG[n-1]-sumG[j];
            }
            for(int j:idG){
                if(j <= i) continue;
                if(2*j-i < n && S[2*j-i] == 'R') ans--;
                ans += sumR[n-1]-sumR[j];
            }
        }
    }
    cout << ans << endl;
}