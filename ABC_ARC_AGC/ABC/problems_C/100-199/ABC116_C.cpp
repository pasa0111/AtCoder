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
    int n;
    cin >> n;
    vector<int> F(n);
    int zero = 0, ans = 0;
    rep(i,n){
        cin >> F.at(i);
        if(F.at(i) == 0){zero++;}
    }
    while(zero != n){
        int k = -1;
        rep(i,n){
            if(F.at(i) == 0){
                if(i >= k+2){ans++;}
                k = i;
            }
            if(F.at(i) > 0){
                F.at(i)--;
                if(F.at(i) == 0){zero++;}
            }
            if(i == n-1 && k < n-1){ans++;}
        }
    }
    cout << ans << endl;
}