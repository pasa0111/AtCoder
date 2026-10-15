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
    int N, Q;
    string S;
    cin >> N >> Q >> S;
    int k = 0;
    for(int q = 0; q < Q; q++){
        int t, x;
        cin >> t >> x;
        if(t == 1){
            k = (k+x)%N;
        }

        if(t == 2){
            int y = x-1-k;
            if(y < 0){y += N;}
            cout << S.at(y) << endl;
        }
    }
}