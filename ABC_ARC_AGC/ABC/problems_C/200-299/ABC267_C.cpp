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
    long long N, M, ans;
    cin >> N >> M;
    vector<long long> A(N);
    long long S = 0;
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
        if(i < M){S += (i+1)*A.at(i);}
        if(i >= 1){A.at(i) += A.at(i-1);}
    }

    ans = S;
    for(int i = 0; i < N-M; i++){
        long long T;
        if(i >= 1){T = S + M*(A.at(i+M)-A.at(i+M-1)) - (A.at(i+M-1)-A.at(i-1));}
        if(i == 0){T = S + M*(A.at(i+M)-A.at(i+M-1)) - A.at(i+M-1);}
        ans = max(T,ans);
        S = T;
    }

    cout << ans << endl;
}