#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
using namespace std;

int main(){
    int N, A, B, d, x=0;
    string s;
    cin >> N >> A >> B;
    for(int i = 0; i < N; i++){
        cin >> s >> d;
        if(s == "East"){
            if(d < A){x += A;}

            if(A <= d && d <= B){x += d;}

            if(d > B){x += B;}
        }

        if(s == "West"){
            if(d < A){x -= A;}

            if(A <= d && d <= B){x -= d;}

            if(d > B){x -= B;}
        }
    }
    if(x == 0){cout << 0 << endl;}
    if(x > 0){cout << "East " << x << endl;}
    if(x < 0){cout << "West " << -x << endl;}
}