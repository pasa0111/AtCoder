#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    bool a = true;
    cin >> N;
    vector<string> S(N);
    vector<string> T(1);
    for(int i = 0; i < N; i++){
        cin >> S.at(i);
    }

    T.at(0) = S.at(0) + S.at(1);


    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i != j){
                a = true;
                for(int k = 0; k < T.size(); k++){
                    if(T.at(k) == S.at(i) + S.at(j)){
                        a = false;
                        break;
                    }
                }
                if(a == true){
                    T.push_back(S.at(i) + S.at(j));
                }
            }
        }
    }

    cout << T.size() << endl;
    
}