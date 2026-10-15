#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int64_t Q, c, x, k, h, t = 0, S, u;
    bool a = true;
    cin >> Q;
    vector<pair<int64_t, int64_t>> A(0); //(x, c)

    for(int q = 0; q < Q; q++){
        cin >> h;

        if(h == 1){
            cin >> c >> x;
            A.push_back(make_pair(x, c));
        }

        if(h == 2){
            S = 0;
            cin >> k;
            u = k;

            while(a == true){
            if(u <= A.at(t).second){
                S += A.at(t).first * u;
                A.at(t).second -= u;
                break;
            }

            if(u > A.at(t).second){
                    S += A.at(t).first * A.at(t).second;
                    u -= A.at(t).second;
                    t++;
                }
            }

            cout << S << endl;

        }
    }
}