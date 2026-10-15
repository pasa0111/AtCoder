#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

int main(){
    long long N, K, X;
    cin >> N >> K >> X;
    vector<string> S(N);
    string ans = "";
    for(int i = 0; i < N; i++){cin >> S.at(i);}
    sort(S.begin(), S.end());
    long long n=1;
    long long a;
    X--;
        for(int i = 0; i < K; i++){
            n = 1;
            for(int j = 0; j < K-i-1; j++){n *= N;}
            a = X / n;
            ans += S.at(a);
            X %= n;
        }
    cout << ans << endl;
}