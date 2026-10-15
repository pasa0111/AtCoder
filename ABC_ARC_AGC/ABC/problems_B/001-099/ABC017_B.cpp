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
    if(b) cout << "YES" << endl;
    if(!b) cout << "NO" << endl;
}

int main(){
    string x;
    cin >> x;
    int n = x.size();
    bool ans = true;
    rep(i,n){
        ans = false;
        if(x.at(i) == 'c' && i <= n-2){
            i++;
            if(x.at(i) == 'h'){ans = true;}
        }
        if(x.at(i) == 'o' || x.at(i) == 'k' || x.at(i) == 'u'){ans = true;}
        if(!ans){break;}
    }
    yesno(ans);
}
