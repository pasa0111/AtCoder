#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, M, S = 0, A;
    cin >> N >> M;

    for(int i = 0; i < N; i ++){
        cin >> A;
        S += A;
    }

    if(S <= M){
        cout << "Yes" << endl;
    }

    else{
        cout << "No" << endl;
    }
}