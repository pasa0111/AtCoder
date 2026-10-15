#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
using namespace std;

int main(){
    string S;
    cin >> S;
    int n = S.size();

    //Sからi文字消す
    for(int i = 2; i <= n-2; i+=2){
        if(S.substr(0, (n-i)/2) == S.substr((n-i)/2, (n-i)/2)){
            cout << n-i << endl;
            break;
        }
    }
}