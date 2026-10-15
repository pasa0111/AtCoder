#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
using namespace std;

int main(){
    long long N, M, ans=0, m=0;
    cin >> N >> M;
    vector<pair<long long, long long>> A(N); //(値段,店番号)
    vector<long long> B(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i).first >> B.at(i);
        A.at(i).second = i;
    }
    sort(A.begin(), A.end());
    int i = 0;
    while(m < M){
        if(m + B.at(A.at(i).second) > M){
            ans += A.at(i).first * (M-m);
            break;
        }
        if(m + B.at(A.at(i).second) <= M){
            ans += A.at(i).first * B.at(A.at(i).second);
            m += B.at(A.at(i).second);
            i++;
        }
    }
    cout << ans << endl;
}