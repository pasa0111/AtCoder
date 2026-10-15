#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
    int x, y;
    string X, Y;
    cin >> X >> Y;
    if(X == "Ocelot"){x = 0;}
    if(X == "Serval"){x = 1;}
    if(X == "Lynx"){x = 2;}
    if(Y == "Ocelot"){y = 0;}
    if(Y == "Serval"){y = 1;}
    if(Y == "Lynx"){y = 2;}
    if(x >= y){cout << "Yes" << endl;}
    if(x < y){cout << "No" << endl;}
}