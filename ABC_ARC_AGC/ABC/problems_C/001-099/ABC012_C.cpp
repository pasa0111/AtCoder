#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

int main(){
    int N;
    cin >> N;
    int t = 2025-N;
    for(int i = 1; i <= 9; i++){
        if(t % i == 0 && t / i <= 9){
            cout << i << " x " << t/i << endl;
        }
    }
}