#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

int main(){
    int N, j;
    cin >> N;
    vector<long long> sunuke(N), S(N), T(N);
    cin >> S.at(0);
    for(int i = 1; i < N; i++){
        cin >> S.at(i);
        S.at(i) += S.at(i-1);
    }
    for(int i = 0; i < N; i++){
        cin >> T.at(i);
        sunuke.at(i) = T.at(i);
    }
    for(int i = 0; i < N; i++){
        //cout << "i:" << i << endl;
        for(int q = i; q < i+N; q++){
            j = q;
            //cout << " j:" << j << endl;
            if(0 < j && j < N){
                if(i >= 1){
                    //cout << "A:" << T.at(i) + S.at(j-1) - S.at(i-1) << endl;
                    if(sunuke.at(j) >= T.at(i) + S.at(j-1) - S.at(i-1)){
                        sunuke.at(j) = T.at(i) + S.at(j-1) - S.at(i-1);
                        //cout << "  at(" << j << ") == " << sunuke.at(j) << endl;
                    }
                    else{j = -1;}
                }
                if(i == 0){
                    //cout << "B:" << T.at(i) + S.at(j-1) << endl;
                    if(sunuke.at(j) >= T.at(i) + S.at(j-1)){
                        sunuke.at(j) = T.at(i) + S.at(j-1);
                        //cout << "  at(" << j << ") == " << sunuke.at(j) << endl;
                    }
                    else{j = -1;}
                }
            }
            if(j == N){
                //cout << "C:" << T.at(i) + S.at(N-1) - S.at(i-1) << endl;
                if(sunuke.at(0) >= T.at(i) + S.at(N-1) - S.at(i-1)){
                    sunuke.at(0) = T.at(i) + S.at(N-1) - S.at(i-1);
                    //cout << "  at(" << j << ") == " << sunuke.at(0) << endl;
                }
                else{j = -1;}
            }
            if(j > N){
                j %= N;
                //cout << "D:" << T.at(i) + S.at(N) - S.at(i-1) + S.at(j-1) << endl;
                if(sunuke.at(j) >= T.at(i) + S.at(N-1) - S.at(i-1) + S.at(j-1)){
                    sunuke.at(j) = T.at(i) + S.at(N-1) - S.at(i-1) + S.at(j-1);
                    //cout << "  at(" << j << ") == " << sunuke.at(j) << endl;
                }
                else{j = -1;}
            }
            if(j == -1){
                break;
            }
        }
    }

    for(int i = 0; i < N; i++){
        cout << sunuke.at(i) << endl;
    }
}