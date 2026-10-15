#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    string S;
    vector<vector<int>> ms(H, vector<int>(W,0));
    for(int i = 0; i < H; i++){
        cin >> S;
        for(int j = 0; j < W; j++){
            if(S.at(j) == '.'){ms.at(i).at(j) = 0;}
            if(S.at(j) == '#'){ms.at(i).at(j) = -1;}
        }
    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(ms.at(i).at(j) == -1){
                for(int k = 1; k >= -1; k--){
                    for(int l = -1; l <= 1; l++){
                        if(0 <= i+k && i+k <= H-1 && 0 <= j+l && j+l <= W-1){
                            if((k != 0 || l != 0) && ms.at(i+k).at(j+l) != -1){ms.at(i+k).at(j+l)++;}
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(ms.at(i).at(j) == -1){
                cout << '#';
            }
            else{cout << ms.at(i).at(j);}
        }
        cout << endl;
    }
}