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

//非負整数yをstring型にして返す
string int_str(int y){
    string res = "";
    while(y > 0){
        int x = y%10;
        y /= 10;
        if(x == 0){res += '0';}
        if(x == 1){res += '1';}
        if(x == 2){res += '2';}
        if(x == 3){res += '3';}
        if(x == 4){res += '4';}
        if(x == 5){res += '5';}
        if(x == 6){res += '6';}
        if(x == 7){res += '7';}
        if(x == 8){res += '8';}
        if(x == 9){res += '9';}
    }
    reverse(vecall(res));
    return res;
}

int main(){
    string s, ans = "";
    cin >> s;
    int n = s.size(), k = 1;
    rep(i,n-1){
        if(s.at(i) != s.at(i+1)){
            ans += s.at(i) + int_str(k);
            k = 1;
        }
        if(s.at(i) == s.at(i+1)){k++;}
    }
    ans += s.at(n-1) + int_str(k);
    cout << ans << endl;
}
