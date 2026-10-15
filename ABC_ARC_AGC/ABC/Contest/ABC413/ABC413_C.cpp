#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int main(){
    int64_t Q, c, x, k, h, t = 0, S, u;
    bool a = true;
    cin >> Q;
    vector<pair<int64_t, int64_t>> A(0); //(x, c)
    vector<tuple<int64_t, int64_t, int64_t>> B(Q);

    for(int q = 0; q < Q; q++){
        cin >> h;
        if(h == 1){
            cin >> c >> x;
            B.at(q) = make_tuple(h, c, x);
        }

        if(h == 2){
            cin >> k;
            B.at(q) = make_tuple(h, k, 0);
        }
    }

    for(int q = 0; q < Q; q++){

        if(get<0>(B.at(q)) == 1){
            x = get<2>(B.at(q));
            c = get<1>(B.at(q));
            A.push_back(make_pair(x, c));
        }

        if(get<0>(B.at(q)) == 2){
            S = 0;
            u = get<1>(B.at(q));
            //cout << "k:" << u << endl;

            while(a == true){
                //cout << "->" << S;
            if(u <= A.at(t).second){
                S += A.at(t).first * u;
                A.at(t).second -= u;
                //cout << endl;
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