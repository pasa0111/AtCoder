#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<string> room(N);
    for(int i = 0; i < N; i++){
        cin >> room.at(i);
    }
    int X;
    string Y;
    cin >> X >> Y;
    if(room.at(X-1) == Y){cout << "Yes" << endl;}
    else{cout << "No" << endl;}
}