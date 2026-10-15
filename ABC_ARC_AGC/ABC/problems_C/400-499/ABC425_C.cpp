#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <deque>
using namespace std;

int main(){
    long long N, Q, x, c, l, r, k = 0, res;
    cin >> N >> Q;
    vector<long long> A(N,0);
    cin >> A.at(0);
    for(int i = 1; i < N; i++){
        cin >> A.at(i);
        A.at(i) += A.at(i-1);
    }

    for(int q = 0; q < Q; q++){
        cin >> x;
        if(x == 1){
            cin >> c;
            k += c;
            k %= N;
        }

        if(x == 2){
            res = 0;
            cin >> l >> r;
            r = (r-1 + k) % N;
            l = (l-1 + k) % N;
            if(r >= l){
                if(l != 0){
                    res = A.at(r) - A.at(l-1);
                }
                if(l == 0){
                    res = A.at(r);
                }
            }

            if(r < l){
                res = A.at(N-1) - A.at(l-1) + A.at(r);
            }
            cout << res << endl;
        }
    }
}