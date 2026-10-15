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

int main(){
    int h,w,n;
    cin >> h >> w >> n;
    queue<int> color;
    vector<vector<int>> ans(h,vector<int>(w));
    rep(i,n){
        int a;
        cin >> a;
        rep(j,a){color.push(i+1);}
    }
    rep(i,h){
        if(i % 2 == 0){
            rep(j,w){
                ans.at(i).at(j) = color.front();
                color.pop();
            }
        }
        if(i % 2 == 1){
            for(int j = w-1; j >= 0; j--){
                ans.at(i).at(j) = color.front();
                color.pop();
            }
        }
        rep(j,w){cout << ans.at(i).at(j) << " ";}
        cout << endl;
    }

}