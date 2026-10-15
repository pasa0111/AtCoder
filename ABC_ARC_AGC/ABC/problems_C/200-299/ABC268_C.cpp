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
#define MT make_tuple

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int> rotate(n); //i回回した時に喜ぶ人の数を保存
    int ans = 0;
    rep(i,n){
        int p;
        cin >> p;
        rotate[(n+p-1-i)%n]++;
        rotate[(n+p-i)%n]++;
        rotate[(n+p+1-i)%n]++;
        ans = max({ans,rotate[(n+p-1-i)%n],rotate[(n+p-i)%n],rotate[(n+p+1-i)%n]});
    }
    cout << ans << endl;
}