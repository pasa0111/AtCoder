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
    cin >> n;
    vector<int> A(n);
    vector<int> B(n);
    rep(i,n){
        cin >> A[i];
        B[i] = A[i];
        if(i > 0) B[i] += B[i-1];
    }
    int ans = 0;
    for(int l = 0; l < n; l++){
        for(int r = l; r < n; r++){
            bool hantei = true;
            for(int i = l; i <= r; i++){
                if(l > 0 && (B[r]-B[l-1]) % A[i] == 0) hantei = false;
                if(l == 0 && B[r]%A[i] == 0) hantei = false;
            }
            if(hantei) ans++;
        }
    }
    cout << ans << endl;
}