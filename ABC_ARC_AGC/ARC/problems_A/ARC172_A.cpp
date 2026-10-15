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
#define adrep(i,s,e,k) for(int i = s; i <= e; i+=k)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(int i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}


void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

//2^y <= x を満たす最大のyを返す
ll two(ll x){
    ll z=1,y=0;
    while(z <= x){
        z *= 2;
        y++;
    }
    return y-1;
}

void solve(ll h, ll w, vector<int> &c){
    //cout << "(" << h << "," << w << ")" << endl;
    if(h == 0 || w == 0){return;}
    ll x = min(two(h),two(w));
    ll y = 1;
    for(int i = x; i >= 0; i--){
        if(i <= 25 && c.at(i) > 0){
            c.at(i)--;
            rep(j,i){y *= 2;}
            solve(h-y,w,c);
            solve(y,w-y,c);
            break;
        }
    }
    return;
}


int main(){
    ll h,w,n;
    cin >> h >> w >> n;
    vector<int> c(26);
    rep(i,n){
        int a;
        cin >> a;
        c.at(a)++;
    }
    solve(h,w,c);
    bool ans = true;
    //rep(i,26){cout << c.at(i) << " ";}
    //cout << endl;
    rep(i,26){if(c.at(i) > 0){ans = false;}}
    yesno(ans);
}