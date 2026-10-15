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

string solve(ll x){
    if(x == 1){return "a";}
    if(x == 2){return "b";}
    if(x == 3){return "c";}
    if(x == 4){return "d";}
    if(x == 5){return "e";}
    if(x == 6){return "f";}
    if(x == 7){return "g";}
    if(x == 8){return "h";}
    if(x == 9){return "i";}
    if(x == 10){return "j";}
    if(x == 11){return "k";}
    if(x == 12){return "l";}
    if(x == 13){return "m";}
    if(x == 14){return "n";}
    if(x == 15){return "o";}
    if(x == 16){return "p";}
    if(x == 17){return "q";}
    if(x == 18){return "r";}
    if(x == 19){return "s";}
    if(x == 20){return "t";}
    if(x == 21){return "u";}
    if(x == 22){return "v";}
    if(x == 23){return "w";}
    if(x == 24){return "x";}
    if(x == 25){return "y";}
    if(x == 0){return "z";}
    else return "";
}

int main(){
    ll n;
    cin >> n;
    bool b = true;
    string ans = "";
    while(n > 0){
        ans += solve(n%26);
        if(n % 26 == 0){n -= 26;}
        n /= 26;
    }
    reverse(vecall(ans));
    cout << ans << endl;
}