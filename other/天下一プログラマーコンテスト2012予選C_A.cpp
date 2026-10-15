#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
using namespace std;

//2以上のnが素数ならtrue,合成数ならfalseを返す
bool solve(int n){
    int m = sqrt(n);
    for(int i = 2; i <= m; i++){
        if(n % i == 0){return false;}
    }
    return true;
}


int main(){
    int n, ans=0;
    cin >> n;
    for(int i = 2; i < n; i++){
        if(solve(i)){ans++;}
    }
    cout << ans << endl;
}