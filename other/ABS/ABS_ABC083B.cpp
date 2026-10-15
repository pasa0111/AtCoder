#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;

int main(){
    long long N, A, B, t, ans = 0, k;
    cin >> N >> A >> B;
    for(int i = 1; i <= N; i++){
        t = 0;
        k = i;

            while(k > 0){
                t += k % 10;
                k /= 10;
            }

        if(t >= A && t <= B){ans += i;}
    }
    cout << ans << endl;
}