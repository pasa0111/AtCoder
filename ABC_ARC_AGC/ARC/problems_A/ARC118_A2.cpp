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
    long long t, N;
    cin >> t >> N;
    long long A = (100*N + t - 1) / t;
    cout << A + N - 1 << endl;
}