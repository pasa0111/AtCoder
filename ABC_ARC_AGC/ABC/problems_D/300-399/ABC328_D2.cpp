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
    string s;
    cin >> s;
    int n = s.size(), m;
    string ans = "";
    rep(i,n){
        //cout << ans << endl;
        m = ans.size();
        if(i > 0 && m > 1 && ans.at(m-2) == 'A' && ans.at(m-1) == 'B' && s.at(i) == 'C'){ans.erase(m-2,2);}
        else{ans += s.at(i);}
    }
    cout << ans << endl;
}