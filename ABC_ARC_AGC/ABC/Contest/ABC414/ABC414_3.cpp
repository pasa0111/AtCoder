#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int bit(int n, int a){
    int s = 0;
    while(n > 0){
        
    }
}



//n=数字 k=nの桁数 m桁目
//nのm桁目の数字を取り出す関数
int super(int n, int k, int m){
    if(m > k){
        return -1;
    }
    int x = 1, y, z;
    for(int i = 0; i < m; i++){
        x *= 10;
    }
    y = x / 10;
    z = n % x - n % y;
    return z / y;
}

int main(){
    int N, k = 0, x; //kはNの桁数
    cin >> N;
    x = N;
    while(x > 0){
        x /= 10;
        k++;
    }

    for(int i = 0; i < N/2; i++){
    }

}