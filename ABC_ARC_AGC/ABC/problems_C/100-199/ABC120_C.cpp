#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
using namespace std;

int main(){
    string S;
    int a=0, b=0;
    cin >> S;
    for(unsigned long i = 0; i < S.size(); i++){
        if(S.at(i) == '0'){a+=2;}
        else{b+=2;}
    }
    cout << min(a,b) << endl;
}