#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
using namespace std;

int main(){
    int N,M=0,m=0, A;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A;
        if(A > M){
            m = M;
            M = A;
        }
        if(m < A && A < M){m = A;}
    }
    cout << m << endl;
}