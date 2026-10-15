#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

int main(){
    int a, b, p, q;
    cin >> a >> b;
    vector<int> pin(11,-1); //pin(i)が何投目に倒されたか保存
    for(int i = 1; i <= a; i++){
        cin >> p;
        if(p == 0){p = 10;}
        pin.at(p) = 1;
    }
    for(int i = 1; i <= b; i++){
        cin >> q;
        if(q == 0){q = 10;}
        pin.at(q) = 2;
    }
    for(int i = 7; i <= 10; i++){
        if(pin.at(i) == -1){
            cout << "x ";
        }
        if(pin.at(i) == 1){
            cout << ". ";
        }
        if(pin.at(i) == 2){
            cout << "o ";
        }
    }
    cout << endl << " ";
    for(int i = 4; i <= 6; i++){
        if(pin.at(i) == -1){
            cout << "x ";
        }
        if(pin.at(i) == 1){
            cout << ". ";
        }
        if(pin.at(i) == 2){
            cout << "o ";
        }
    }
    cout << endl << "  ";
    for(int i = 2; i <= 3; i++){
        if(pin.at(i) == -1){
            cout << "x ";
        }
        if(pin.at(i) == 1){
            cout << ". ";
        }
        if(pin.at(i) == 2){
            cout << "o ";
        }
    }
    cout << endl << "   ";
    if(pin.at(1) == -1){
            cout << "x ";
    }
    if(pin.at(1) == 1){
            cout << ". ";
    }
    if(pin.at(1) == 2){
            cout << "o ";
    }
    cout << endl;
}