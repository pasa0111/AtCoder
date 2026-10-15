#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;

//k:(x,y)の数字
void dragon(int x, int y, int k, int n, vector<vector<int>> &G){

    if(n == 1){return;}

    for(int i = 0; i < n; i++){
        G.at(x).at(y+i) = k;
        k++;
    }
    for(int i = 1; i < n; i++){
        G.at(x+i).at(y+n-1) = k;
        k++;
    }
    for(int i = n-2; i >= 0; i--){
        G.at(x+n-1).at(y+i) = k;
        k++;
    }
    for(int i = n-2; i >= 1; i--){
        G.at(x+i).at(y) = k;
        k++;
    }

    dragon(x+1,y+1,k,n-2,G);
    return;
}

int main(){
    int N;
    cin >> N;
    vector<vector<int>> G(N,vector<int>(N));
    dragon(0,0,1,N,G);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i != (N-1)/2 || j != (N-1)/2){
                cout << G.at(i).at(j) << " ";
            }
            if(i == (N-1)/2 && j == (N-1)/2){
                cout << "T ";
            }
        }
        cout << endl;
    }
}