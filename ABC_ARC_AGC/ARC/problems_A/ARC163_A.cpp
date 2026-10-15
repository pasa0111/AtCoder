#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
using namespace std;

int main(){
    int N, T;
    string S;
    cin >> T;
    vector<int> u;
    bool ans = false, q;
    for(int t = 0; t < T; t++){
        ans = false;
        q = false;
        u = {};
        cin >> N >> S;
        for(int i = 1; i < N; i++){
            if(S.at(i) == S.at(0)){
                u.push_back(i);
            }
            if(S.at(i) > S.at(0)){
                ans = true;
            }
        }
        if(ans == false && u.size() >= 1){
            for(int i = 0; i < u.size(); i++){
                q = false;
                for(int j = 1; j < u.at(i); j++){
                    if(j+u.at(i) >= N){break;}
                    if(S.at(j) < S.at(j+u.at(i))){
                        ans = true;
                        q = true;
                    }
                    if(S.at(j) > S.at(j+u.at(i))){
                        ans = false;
                        q = true;
                    }
                    if(q == true){break;}
                }
                if(q == false && 2 * u.at(i) < N){ans = true;}
                if(ans == true){break;}
            }
        }
        if(ans == true){cout << "Yes" << endl;}
        if(ans == false){cout << "No" << endl;}
    }
}