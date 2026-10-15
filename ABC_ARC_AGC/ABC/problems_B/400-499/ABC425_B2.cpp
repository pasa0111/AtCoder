#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

int main(){
    unsigned long N, x = 0;
    bool ans = false;
    cin >> N;
    vector<int> A(N), P(N, 0);
    set<int> S;

    for(unsigned long i = 0; i < N; i++){
        cin >> A.at(i);
        if(A.at(i) > 0){
            S.insert(A.at(i));
            x++;
        }
    }

    if(S.size() == x){
        ans = true;
        for(unsigned long i = 1; i <= N; i++){
            if(S.count(i)){
                for(unsigned long j = 0; j < N; j++){
                    if(A.at(j) == i){
                        P.at(j) = i;
                    }
                }
            }
        }

        for(unsigned long i = 1; i <= N; i++){
            if(S.count(i) == false){
                for(unsigned long j = 0; j < N; j++){
                    if(P.at(j) == 0){
                        P.at(j) = i;
                        break;
                    }
                }
            }
        }
    }

    if(ans == false){
        cout << "No" << endl;
    }

    if(ans == true){
        cout << "Yes" << endl;
        for(unsigned long i = 0; i < N-1; i++){
            cout << P.at(i) << " ";
        }
        cout << P.at(N-1) << endl;
    }
}   