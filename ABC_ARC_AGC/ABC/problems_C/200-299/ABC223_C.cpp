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
    cout << fixed << setprecision(10);
    int N;
    cin >> N;
    double ans=0;
    vector<double> A(N), B(N), T(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i) >> B.at(i);
        if(i >= 1){T.at(i) = T.at(i-1) + (A.at(i)/B.at(i));}
        if(i == 0){T.at(i) = A.at(i)/B.at(i);}
        if(i >= 1){A.at(i) += A.at(i-1);}
    }

    //for(int i = 0; i < N; i++){cout << T.at(i) << endl;}

    for(int i = 0; i < N; i++){
        if(2 * T.at(i) >= T.at(N-1)){
            //cout << "i = " << i << endl;
            if(i == 0){ans = B.at(i) * T.at(N-1)/2;}
            if(i >= 1){ans = A.at(i-1) + B.at(i) * (T.at(N-1)/2 -T.at(i-1));}
            break;
        }
    }
    cout << ans << endl;
}