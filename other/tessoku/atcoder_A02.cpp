#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int X;
    cin >> X;
    int a = 0;
    while (a < N){
        int A;
        cin >> A;
        if (X == A) {
            cout << "Yes" << endl;
            a = N;
        }
        a = a + 1;
    }
    if (a == N)
    cout << "No" << endl;
}