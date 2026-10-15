#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
using namespace std;

int main(){
    long long N, T=0, U=0;
    cin >> N;
    vector<long long> A(N), S(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
        if(i != 0){S.at(i) = S.at(i-1);}
        S.at(i) += A.at(i);
        T += A.at(i)*A.at(i);
    }
    for(int i = 1; i <= N-1; i++){U += A.at(i)*S.at(i-1);}
    cout << (N-1)*T - 2*U << endl;
}