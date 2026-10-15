#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A = {-999};
    int a = 0, c = 0;
    int x;
    
    while (a < N) {
        cin >> x;
        if (x < K){
            A[c] = x;
            c = c + 1;
        }
        a = a + 1;
    }

    vector<int> B = {-999};
    int b = 0, d = 0;

    while (b < N){
        cin >> x;
        if (x < K){
        B[d] = x;
        d = d + 1;
        }
        b = b + 1;
    }

    b = 0;
    int S;

    while (b < d){
    a = 0;
        while (a < c) {
            S = A[a] + B[b];
            cout << S << endl;
           if (S == K) {
            cout << "Yes" << endl;
            a = c;
            b = d;
           }
           a = a + 1;
        }
    b =  b + 1;
    }

    if (b == d){
        cout << "No" << endl;
    }
}