#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
using namespace std;

int main(){
    int N;
    cin >> N;
    long long ans=0;
    vector<long long> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
        if(i != 0){
            A.at(i) += A.at(i-1);
            A.at(i) %= 1000000007;
        }
    }

    for(int i = 0; i < N-1; i++){
        if(i == 0){ans += A.at(0) * (A.at(N-1)-A.at(0));}
        if(i != 0){ans += (A.at(i)-A.at(i-1)) * (A.at(N-1)-A.at(i));}
        if(ans >= 0){ans %= 1000000007;}
        if(ans < 0){while(ans < 0){ans += 1000000007;}}
    }
    while(ans < 0){ans += 1000000007;}
    cout << ans << endl;
}