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
    long long N, L = 0, R = 0;
    cin >> N;
    vector<pair<int,int>> A(N); //(L,R)
    for(int i = 0; i < N; i++){
        cin >> A.at(i).first >> A.at(i).second;
        L += A.at(i).first;
        R += A.at(i).second;
    }
    if(L <= 0 && 0 <= R){
        cout << "Yes" << endl;
        long long t = 0;
        vector<long long> ans(N);
        for(int i = 0; i < N; i++){
            long long x;
            if(t == R){x = A.at(i).second;}
            if(t != R){
                x = A.at(i).first;
                t += A.at(i).second - x;
                if(t >= R){
                    x += t-R;
                    t = R;
                }
            }
            cout << x << " ";
        }
        cout << endl;
    }

    if(L > 0 || 0 > R){
        cout << "No" << endl;
    }
}