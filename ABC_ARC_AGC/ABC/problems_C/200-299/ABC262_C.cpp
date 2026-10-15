#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
using namespace std;

int main(){
    long long N, ans = 0, k = 0;
    cin >> N;
    vector<int> A(N+1);
    for(int i = 1; i <= N; i++){
        cin >> A.at(i);
        if(A.at(i) == i){k++;}
    }
    ans += k*(k-1)/2;
    for(int i = 1; i <= N-1; i++){
        if(A.at(A.at(i)) == i && A.at(i) > i){
            ans++;
        }
    }
    cout << ans << endl;
}