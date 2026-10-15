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
    int N;
    cin >> N;
    long long A = 1;
    bool large = false;
    for(int i = 0; i < N; i++){
        long long a;
        cin >> a;
        if(a > 1000000000000000000/A){large = true;}
        if(a == 0){
            large = false;
            A = 0;
            break;
        }
        if(!large){A *= a;}
    }

    if(large){cout << -1 << endl;}
    if(!large){cout << A << endl;}
}