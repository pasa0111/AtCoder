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
    vector<int> A(n),ans(n);
    vecin(A);
    int k,m = 0,s;
    if(n % 2 == 0){k = n-1; s = n-2;}
    if(n % 2 == 1){k = n-2; s = n-1;}
    for(int i = k; i >= 1; i-=2,m++){ans.at(m) = A.at(i);}
    for(int i = 0; i <= s; i+=2,m++){ans.at(m) = A.at(i);}
    if(n % 2 == 1){reverse(vecall(ans));}
    rep(i,n){cout << ans.at(i) << " ";}
    cout << endl;
}