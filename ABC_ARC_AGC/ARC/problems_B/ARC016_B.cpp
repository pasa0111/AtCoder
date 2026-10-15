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
    int n, ans = 0;
    cin >> n;
    vector<string> X(n);
    rep(i,n){
        cin >> X.at(i);
        rep(j,9){
            if(X.at(i).at(j) == 'x'){ans++;}
            if(i == 0 && X.at(i).at(j) == 'o'){ans++;}
            if(i >= 1){
                if(X.at(i-1).at(j) != 'o' && X.at(i).at(j) == 'o'){ans++;}
            }
        }
    }
    cout << ans << endl;
}