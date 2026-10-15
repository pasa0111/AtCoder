#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

int solve(int x){
    int res = 0;
    while(x > 0){
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main(){
    int N, A = 0, B = 1;
    cin >> N;
    for(int i = 0; i < N; i++){
        A += solve(B);
        B = A;
    }
    cout << A << endl;
}