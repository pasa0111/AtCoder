#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
using namespace std;

int main(){
    int ans = 0, N, T;
    cin >> N >> T;
    vector<int> A(N);
    for(int i = 0; i < N; i++){cin >> A.at(i);}
    for(int i = 0; i < N-1; i++){
        if(A.at(i+1) <= A.at(i)+T){ans+=A.at(i+1)-A.at(i);}
        if(A.at(i+1) > A.at(i)+T){ans+=T;}
    }
    ans+=T;
    cout << ans << endl;
}