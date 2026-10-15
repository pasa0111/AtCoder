#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
    string S;
    cin >> S;
    char x = S.at(0), y = S.at(1), z = S.at(2);

    if(x == y){
        for(int i = 2; i < S.size(); i++){
            if(x != S.at(i)){
                cout << S.at(i) << endl;
            }
        }
    }

    if(x != y){
        if(x == z){cout << y << endl;}
        else{cout << x << endl;}
    }
}