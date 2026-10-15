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
    int S, A, B, X, T = 0, ans = 0;
    cin >> S >> A >> B >> X;
    while(T < X){
        if(T+A <= X){
            ans += A*S;
            T += A;
            T += B;
            continue;
        }
        if(T+A > X){
            ans += S * (X-T);
            break;
        }
    }
    cout << ans << endl;
}