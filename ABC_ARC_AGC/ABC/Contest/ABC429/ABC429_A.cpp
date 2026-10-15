#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    if(N > M){
        for(int i = 0; i < M; i++){cout << "OK" << endl;}
        for(int i = M; i < N; i++){cout << "Too Many Requests" << endl;}
    }
    if(N <= M){
        for(int i = 0; i < N; i++){cout << "OK" << endl;}
    }
}