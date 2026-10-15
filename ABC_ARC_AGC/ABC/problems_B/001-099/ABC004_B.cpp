#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
using namespace std;

int main(){
    vector<vector<char>> grid(4,vector<char>(4));
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cin >> grid.at(i).at(j);
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << grid.at(3-i).at(3-j) << " ";
        }
        cout << endl;
    }
}