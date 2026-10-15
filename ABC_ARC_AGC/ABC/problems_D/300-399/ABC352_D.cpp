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


using namespace std;
#define ll long long
#define rep(i,e) for(ll i = 0; i < e; i++)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(unsigned ll i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}
#define SORT(vec) sort(vecall(vec))
#define RSORT(vec) SORT(vec);reverse(vecall(vec));
#define MP make_pair

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> P(n), Q(n+1);
    rep(i,n){
        cin >> P[i];
        Q[P[i]] = i;
    }
    set<int> find;
    for(int i = 1; i <= k; i++) find.insert(Q[i]);
    int ans = *rbegin(find)-*begin(find);
    for(int i = 1; i <= n-k; i++){
        find.erase(Q[i]);
        find.insert(Q[i+k]);
        ans = min(ans,*rbegin(find)-*begin(find));
    }
    cout << ans << endl;
}