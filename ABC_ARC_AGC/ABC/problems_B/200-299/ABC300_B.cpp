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
    bool ans = true;
    vector<vector<char>> A(H,vector<char>(W)), B(H,vector<char>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> A.at(i).at(j);
        }
    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> B.at(i).at(j);
        }
    }

    for(int s = 0; s < H; s++){
        for(int t = 0; t < W; t++){
            ans = true;
            for(int i = 0; i < H; i++){
                for(int j = 0; j < W; j++){ 
                    int x = i + s, y = j + t;
                    if(x >= H){x -= H;}
                    if(y >= W){y -= W;}
                    //cout << "A(" << x << "," << y << ") = " << A.at(x).at(y) << endl;
                    //cout << "B(" << i << "," << j << ") = " << B.at(i).at(j) << endl;
                    if(A.at(x).at(y) != B.at(i).at(j)){
                        i = H;
                        j = W;
                        ans = false;
                    }
                }
            }
            if(ans == true){
                s = H;
                t = W;
            }
        }
    }

    if(ans == true){cout << "Yes" << endl;}
    if(ans == false){cout << "No" << endl;}
}