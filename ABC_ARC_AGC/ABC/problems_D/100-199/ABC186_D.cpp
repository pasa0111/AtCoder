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
    long long N, ans = 0;
    cin >> N;
    vector<long long> A(N);
    for(int i = 0; i < N; i++){cin >> A.at(i);}
    sort(A.begin(),A.end());
    for(long long i = 0; i < N; i++){ans += A.at(i)*(2*i-N+1);}
    cout << ans << endl;
}