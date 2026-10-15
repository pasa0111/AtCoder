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
#define adjrep(i,s,e) for(ll i = s; i <= e; i++)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(int i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}
#define adjvecin(vec) for(int i = 1, a = vec.size(); i < a; i++){cin >> vec.at(i);}


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int m,n;
    cin >> n >> m;
    bool ans1 = false, ans2 = false;
    vector<int> A(n),B(m),C(m);
    vecin(A);
    vecin(B);
    int b = 0;
    rep(i,n){
        if(A.at(i) == B.at(b)){
            C.at(b) = i;
            b++;
        }
        if(b == m){
            ans1 = true;
            break;
        }
    }
    for(int j = C.at(m-1)+1; j <= n-1; j++){
        if(A.at(j) == B.at(m-1)){
            ans2 = true;
            break;
        }
    }
    for(int i = m-2; i >= 0; i--){
        for(int j = C.at(i)+1; j < C.at(i+1); j++){
            if(A.at(j) == B.at(i)){
                ans2 = true;
                break;
            }
        }
    }
    yesno(ans1 && ans2);
}
