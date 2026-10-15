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
    int n,m;
    cin >> n >> m;
    vector<int> V(n);
    rep(i,m){
        int l,r;
        cin >> l >> r;
        V.at(l-1)++;
        if(r < n){V.at(r)--;}
    }
    adjrep(i,1,n-1){V.at(i) += V.at(i-1);}
    int ans = m;
    rep(i,n){ans = min(ans,V.at(i));}
    cout << ans << endl;
}
