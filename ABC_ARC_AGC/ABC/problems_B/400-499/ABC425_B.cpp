#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

int main(){
    int N, a, x=0, t=0;
    bool ans = true;
    cin >> N;
    vector<int> A(N), P(N, -5);
    set<int> S;

    for(int i = 0; i < N; i++){
        cin >> A.at(i);
        if(A.at(i) >= 1){
            S.insert(A.at(i));
            x++;
        }
    }


    if(x > S.size()){ans = false;}

    if(x == S.size()){
        for(int i = 1; i <= N; i++){
            if(S.count(i)){
                for(int j = 0; j < N; j++){
                    if(A.at(j) == i){
                        P.at(j) = i;
                    }
                }
            }

            if(S.count(i) == false){
                while(true){
                if(t >= N){break;}
                if(P.at(t) == -5){
                    P.at(t) = i;
                    break;
                }
                t++;
                }
            }
        }
    }

    if(ans == false){cout << "No" << endl;}

    if(ans == true){
        cout << "Yes" << endl;
        for(int i = 0; i < N-1; i++){
            cout << P.at(i) << " ";
        }
        cout << P.at(N-1) << endl;
    }

}   