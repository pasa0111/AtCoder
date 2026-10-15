#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <set>
using namespace std;

int main(){
    int N, d;
    cin >> N;
    set<int> mochi;
    for(int i = 0; i < N; i++){
        cin >> d;
        mochi.insert(d);
    }
    cout << mochi.size() << endl;
}