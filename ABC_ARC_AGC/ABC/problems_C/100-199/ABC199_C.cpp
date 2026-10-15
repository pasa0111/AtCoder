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
    int N, Q, n = 0;
    string S;
    cin >> N >> S >> Q;
    for(int q = 0; q < Q; q++){
        int T,A,B;
        cin >> T >> A >> B;
        if(T == 1){
            A = (A-1+n)%(2*N);
            B = (B-1+n)%(2*N);
            char k = S.at(A);
            S.at(A) = S.at(B);
            S.at(B) = k;
        }

        if(T == 2){
            n = (n+N)%(2*N);
        }
    }

    int t = n;
    for(int i = 0; i < 2*N; i++){
        if(t >= 2*N){t %= 2*N;}
        cout << S.at(t);
        t++;
    }
    cout << endl;
}