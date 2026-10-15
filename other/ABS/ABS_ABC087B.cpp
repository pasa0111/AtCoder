#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
    int A, B, C, X, a, b, c, x, ans = 0;
    cin >> A >> B >> C >> X;
    for(int a = 0; a <= A; a++){
        for(int b = 0; b <= B; b++){
            for(int c = 0; c <= C; c++){
                if(a * 500 + b * 100 + c * 50 == X){
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}