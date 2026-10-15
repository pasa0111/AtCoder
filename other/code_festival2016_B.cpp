#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

int main(){
    int N, A, B, japanese = 0, foreigners = 0;
    string S;
    bool pass = false;
    cin >> N >> A >> B >> S;
    for(int i = 0; i < N; i++){
        pass = false;
        //cout << "j:" << japanese << ",f:" << foreigners << endl;
        if(japanese + foreigners < A+B){
            if(S.at(i) == 'a'){
                cout << "Yes" << endl;
                japanese++;
                pass = true;
            }
            if(S.at(i) == 'b' && foreigners < B){
                cout << "Yes" << endl;
                foreigners++;
                pass = true;
            }
        }
        if(pass == false){cout << "No" << endl;}
    }
}