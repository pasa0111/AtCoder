#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <set>
using namespace std;

int main(){
    int N, Y, y, b, c, d, e; //10000*(N-b-c) 5000*b 1000*c
    bool ans = false;
    cin >> N >> Y;
    d = (Y % 10000) / 1000;

    for(int i = 0; 5 * i + d - 5 < N + 1; i++){
        c = i*5 + d - 5;
        if(c >= 0){
            y = Y - 1000 * c;
            e = (y % 10000) / 1000;

            if(e == 5){
                for(int k = 0; 2 * k + 1 < N-c+1; k++){
                    b = 2 * k + 1;
                    if(b+c <= N){
                        y = Y - 1000 * c - 5000 * b;
                        if(y / 10000 == N - b - c){
                            cout << N-b-c << " " << b << " " << c << endl;
                            i = N;
                            k = N;
                            ans = true;
                        }
                    }
                }
            }

            if(e == 0){
                for(int k = 0; 2 * k < N-c+1; k++){
                    b = 2 * k;
                    if(b+c <= N){
                        y = Y - 1000 * c - 5000 * b;
                        if(y / 10000 == N - b - c){
                            cout << N-b-c << " " << b << " " << c << endl;
                            i = N;
                            k = N;
                            ans = true;
                        }
                    }
                }
            }
        }
    }
    if(ans == false){cout << -1 << " " << -1 << " " << -1 << endl;}
}