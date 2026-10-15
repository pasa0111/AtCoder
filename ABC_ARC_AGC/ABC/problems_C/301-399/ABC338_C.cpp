#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>


using namespace std;
#define ll long long
#define rep(i,e) for(int i = 0; i < e; i++)
#define adjrep(i,s,e) for(ll i = s; i <= e; i++)
#define vall(vec) vec.begin(),vec.end()
#define vin(vec) for(int i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}
#define adjvin(vec) for(int i = 1, a = vec.size(); i < a; i++){cin >> vec.at(i);}


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int N, ans = 0, k, a = 10000000, b = 10000000; //a:料理Aを作れる最大数, b:料理Bを作れる最大数
    map<int,int> Q,A,B;
    cin >> N;
    rep(i,N){cin >> Q[i];}
    rep(i,N){
        cin >> A[i];
        if(A.at(i) != 0){a = min(a,Q.at(i)/A.at(i));}
    }
    rep(i,N){
        cin >> B[i];
        if(B.at(i) != 0){b = min(b,Q.at(i)/B.at(i));}
    }
    rep(i,a+1){
        k = b;
        rep(j,N){if(B.at(j) != 0){k = min(k, (Q.at(j)-A.at(j)*i)/B.at(j));}}
        ans = max(ans,k+i);
    }
    cout << ans << endl;
}