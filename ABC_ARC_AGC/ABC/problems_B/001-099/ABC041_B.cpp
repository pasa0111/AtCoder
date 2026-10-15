#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
using namespace std;

int main(){
    long long A, B, C;
    cin >> A >> B >> C;
    A = A * B % 1000000007;
    A = A * C % 1000000007;
    cout << A << endl;
}