#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;

int main(){
    long long N, a = 0, b = 0, t = 0;
    string S;
    cin >> N >> S;
    for(int i = 0; i < N * 2; i++){
        if(S.at(i) == 'A'){
            a += llabs(i - (2 * t));
            t++;
        }
    }
    t = 0;
    for(int i = 0; i < N * 2; i++){
        if(S.at(i) == 'A'){
            b += llabs(i - (2 * t + 1));
            t++;
        }
    }
    cout << min(a,b) << endl;
}