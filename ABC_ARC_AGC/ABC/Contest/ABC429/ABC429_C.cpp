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
    long long N;
    cin >> N;
    map<int,long long> B; //整数[i]がAに何個含まれているか保存
    set<int> X, Y; //X:Aに含まれる整数を保存, Y:Aに2個以上含まれる整数を保存
    for(int i = 0; i < N; i++){
        int A;
        cin >> A;
        X.insert(A);
        if(!B.count(A)){B[A] = 0;}
        B.at(A)++;
        if(B.at(A) == 2){Y.insert(A);}
    }

    long long ans = 0;
    for(int i:Y){
        //cout << i << "  " << B.at(i) << endl;
        ans += B.at(i)*(B.at(i)-1)/2 * (N-B.at(i));
    }
    cout << ans << endl;
}