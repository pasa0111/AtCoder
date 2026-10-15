#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <deque>
using namespace std;

int main(){
    int N, a;
    cin >> N;
    vector<int> ameba(2 * (N+1), 0);
    for(int i = 1; i <= N; i++){
        cin >> a;
        ameba.at(2 * i) = ameba.at(a) + 1;
        ameba.at(2 * i + 1) = ameba.at(a) + 1;
    }

    for(int i = 1; i <= 2 * N + 1; i++){
        cout << ameba.at(i) << endl;
    }
}