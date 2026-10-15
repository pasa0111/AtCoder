#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <deque>
using namespace std;

int main(){
    string W, ans = "";
    cin >> W;
    for(int i = 0; i < W.size(); i++){
        if(W.substr(i,1) != "a" && W.substr(i,1) != "i" && W.substr(i,1) != "u" && W.substr(i,1) != "e" && W.substr(i,1) != "o"){
            ans += W.substr(i,1);
        }
    }

    cout << ans << endl;
}