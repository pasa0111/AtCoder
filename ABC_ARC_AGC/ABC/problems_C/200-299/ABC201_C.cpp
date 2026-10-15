#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    string S;
    cin >> S;
    int o = 0, n = 0, ans=0;
    for(int i = 0; i < 10; i++){
        if(S.at(i) == 'o'){o++;}
        if(S.at(i) == '?'){n++;}
    }

    if(o == 0){
        ans = n*n*n*n;
    }

    if(o == 1){
        ans = 4*n*n*n + 6*n*n + 4*n +1;
    }

    if(o == 2){
        ans = 12*n*n + 24*n + 14;
    }

    if(o == 3){
        ans = 24*n+36;
    }

    if(o == 4){
        ans = 24;
    }

    cout << ans << endl;
}