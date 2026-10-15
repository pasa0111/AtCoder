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
    int N, M, sum = 0;
    cin >> N >> M;
    bool ans = false;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
        sum += A.at(i);
    }

    for(int i = 0; i < N; i++){
        if(M + A.at(i) == sum){ans = true;}
    }

    if(ans){cout << "Yes" << endl;}
    if(!ans){cout << "No" << endl;}
}