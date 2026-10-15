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
    int N;
    cin >> N;
    vector<tuple<string,int,int>> R(N); //(市,点数,番号)
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        get<0>(R.at(i)) = s;
        int p;
        cin >> p;
        get<1>(R.at(i)) = 100-p;
        get<2>(R.at(i)) = i+1;
    }
    sort(R.begin(), R.end());
    for(int i = 0; i < N; i++){
        cout << get<2>(R.at(i)) << endl;
    }
}