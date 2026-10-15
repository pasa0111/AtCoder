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
    int n;
    cin >> n;
    vector<int> A(n);
    set<int> B; //Aに登場する整数を保存
    vector<ll> D(n+1); //Aに[整数i]が何個含まれているか保存
    rep(i,n){
        int x;
        cin >> x;
        A.at(i) = x;
        if(i == 0){
            B.insert(x);
            D.at(x) = -1;
        }
        if(!B.count(x)){
            B.insert(x);
            D.at(x) = 0;
        }
        D.at(x)++;
    }
    //rep(i,n){D.at(i+1) += D.at(i);}
    ll ans = 1;
    for(int L = 0; L < n-1; L++){
        int a = A.at(L), b = A.at(L+1);
        ll d = D.at(a);
        /*cout << "now: L = " << L << "  A: " <<  A.at(L) << endl;
        cout << "   D: " << D.at(A.at(L)) << endl;*/
        if(a != b){ans += n-L-1-d;}
        D.at(b)--;
        //cout << ans << endl;
    }
    cout << ans << endl;
}