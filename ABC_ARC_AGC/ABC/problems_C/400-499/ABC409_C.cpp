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
    int N, L;
    long long ans = 0;
    cin >> N >> L;

    if(L % 3 != 0){
        for(int i = 0; i < N-1; i++){
            int d;
            cin >> d;
        }
    }

    if(L % 3 == 0){
        int l = L/3;
        vector<int> P(N); //点iの座標を保存
        map<int,long long> Q; //座標[i]にある点の数を保存
        Q[0] = 1;
        for(int i = 0; i < N-1; i++){
            int d;
            cin >> d;
            P.at(i+1) = (P.at(i)+d)%L;
            Q[P.at(i+1)]++;
        }
        for(int i = 0; i < l; i++){
            ans += Q[i]*Q[i+l]*Q[i+2*l];
        }
    }

    cout << ans << endl;
}