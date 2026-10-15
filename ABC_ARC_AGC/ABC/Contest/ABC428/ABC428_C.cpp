#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    int Q, t = 0, I = 10000000, n = 0;
    cin >> Q;
    string S = "";
    for(int q = 0; q < Q; q++){
        int x;
        char c;
        cin >> x;
        if(x == 1){
            cin >> c;
            S += c;
            if(c == '('){t++;}
            if(c == ')'){t--;}
            n++;
        }

        if(x == 2){
            if(S.at(n-1) == '('){t--;}
            if(S.at(n-1) == ')'){t++;} 
            S.pop_back();
            n--;
        }

        //cout << S << "   I = " << I << endl;
        if(t < 0){I = min(n,I);}
        if(t == 0 && n < I){
            cout << "Yes" << endl;
            I = 10000000;
        }
        if(t != 0 || n >= I){cout << "No" << endl;}
    }
}