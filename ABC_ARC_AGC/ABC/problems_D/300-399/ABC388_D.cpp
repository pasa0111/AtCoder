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

/*
g++ ABC/problems_D/301-400/ABC388_D.cpp -o a.out && ./a.out < ./input.txt
*/

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    ll n;
    cin >> n;
    vector<ll> A(n);
    vector<ll> B(n);
    vecin(A);
    rep(i,n){
        if(i > 0) B[i] += B[i-1];
        int a = A[i]+B[i];
        if(i+1 < n) B[i+1]++;
        if(i+a+1 < n) B[i+a+1]--;
        if(i+a >= n-1) cout << a-(n-1-i) << " ";
        if(i+a < n-1) cout << 0 << " ";
    }
    cout << endl;
}