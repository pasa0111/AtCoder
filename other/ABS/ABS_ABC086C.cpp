#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <set>
using namespace std;

int main(){
    int N, x = 0, y = 0, X, Y, t = 0, T; //(x, y) -> (X, Y)
    bool ans = true;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> T >> X >> Y;
        if((T - t - abs(X-x) - abs(Y-y) ) % 2 != 0 || T - t - abs(X-x) - abs(Y-y) < 0){
            ans = false;
            break;
        }
        x = X;
        y = Y;
        t = T;
    }
    if(ans == true){cout << "Yes" << endl;}
    if(ans == false){cout << "No" << endl;}
}