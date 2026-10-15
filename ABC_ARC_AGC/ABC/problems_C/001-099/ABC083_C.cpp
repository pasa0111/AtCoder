#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
using namespace std;

int main(){
    long long X, Y, ans=1;
    cin >> X >> Y;
    while(X <= Y){
        X *= 2;
        if(X <= Y){ans++;}
    }
    cout << ans << endl;
}