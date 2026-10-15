#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
    int N, A, ans = 0, t;
    cin >> N;
    for(int i = 0; i < N; i++){
        t = 0;
        cin >> A;
        while(true){
            if(A % 2 != 0){
                break;
            }
            A /= 2;
            t++;
        }
        if(i == 0){ans = t;}
        else if(ans > t){ans = t;}
    }
    cout << ans << endl;
}