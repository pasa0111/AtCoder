#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
using namespace std;

int main(){
    int N, D, t=1;
    cin >> D >> N;
    for(int i = 0; i < D; i++){t *= 100;}
    if(N == 100){N++;}
    cout << N * t << endl;
}