#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <set>
using namespace std;

int main(){
    string S;
    bool ans = false;
    cin >> S;
    for(unsigned long i = 0; i < S.size(); i++){
        if(S.at(i) == 'd'){

            if(i+4 == S.size()-1){
                if(S.at(i)== 'd' && S.at(i+1) == 'r' && S.at(i+2) == 'e' && S.at(i+3) == 'a' && S.at(i+4) == 'm'){
                    cout << "YES" << endl;
                    ans = true;
                }
            }

            if(i+6 == S.size()-1){
                if(S.at(i)== 'd' && S.at(i+1) == 'r' && S.at(i+2) == 'e' && S.at(i+3) == 'a' && S.at(i+4) == 'm' && S.at(i+5) == 'e' && S.at(i+6) == 'r'){
                    cout << "YES" << endl;
                    ans = true;
                }
            }

            if(i+7 < S.size()){

            if(S.at(i)== 'd' && S.at(i+1) == 'r' && S.at(i+2) == 'e' && S.at(i+3) == 'a' && S.at(i+4) == 'm' && S.at(i+5)== 'e' && S.at(i+6) == 'r' && S.at(i+7) == 'a'){
                i += 4;
            }
            if(S.at(i)== 'd' && S.at(i+1) == 'r' && S.at(i+2) == 'e' && S.at(i+3) == 'a' && S.at(i+4) == 'm' && S.at(i+5)== 'd' && S.at(i+6) == 'r' && S.at(i+7) == 'e'){
                i += 4;
            }
            if(S.at(i)== 'd' && S.at(i+1) == 'r' && S.at(i+2) == 'e' && S.at(i+3) == 'a' && S.at(i+4) == 'm' && S.at(i+5)== 'e' && S.at(i+6) == 'r' && S.at(i+7) == 'd'){
                i += 6;
            }
            if(S.at(i)== 'd' && S.at(i+1) == 'r' && S.at(i+2) == 'e' && S.at(i+3) == 'a' && S.at(i+4) == 'm' && S.at(i+5)== 'e' && S.at(i+6) == 'r' && S.at(i+7) == 'e'){
                i += 6;
            }
            }

        }

        else if(S.at(i) == 'e'){

            if(i+4 == S.size()-1){
                if(S.at(i)== 'e' && S.at(i+1) == 'r' && S.at(i+2) == 'a' && S.at(i+3) == 's' && S.at(i+4) == 'e'){
                    cout << "YES" << endl;
                    ans = true;
                }
            }

            if(i+5 == S.size()-1){
                if(S.at(i)== 'e' && S.at(i+1) == 'r' && S.at(i+2) == 'a' && S.at(i+3) == 's' && S.at(i+4) == 'e' && S.at(i+5) == 'r'){
                    cout << "YES" << endl;
                    ans = true;
                }
            }

            if(i+5 < S.size()){

            if(S.at(i)== 'e' && S.at(i+1) == 'r' && S.at(i+2) == 'a' && S.at(i+3) == 's' && S.at(i+4) == 'e' && S.at(i+5)== 'd'){
                i += 4;
            }
            if(S.at(i)== 'e' && S.at(i+1) == 'r' && S.at(i+2) == 'a' && S.at(i+3) == 's' && S.at(i+4) == 'e' && S.at(i+5)== 'e'){
                i += 4;
            }
            if(S.at(i)== 'e' && S.at(i+1) == 'r' && S.at(i+2) == 'a' && S.at(i+3) == 's' && S.at(i+4) == 'e' && S.at(i+5)== 'r'){
                i += 5;
            }
            }
        }

        else{
            break;
        }
    }

    if(ans == false){cout << "NO" << endl;}
}