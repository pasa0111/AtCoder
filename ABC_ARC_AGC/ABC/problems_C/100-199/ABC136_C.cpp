#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <deque>
using namespace std;

int main(){
    int N;
    bool ans = true;
    cin >> N;
    vector<int> H(N+1, 1);
    for(int i = 1; i <= N; i++){cin >> H.at(i);}
    for(int i = 1; i <= N; i++){
        if(H.at(i) == H.at(i-1)){
            H.at(i) = H.at(i-1);
        }
        if(H.at(i) >= H.at(i-1)+1){
            H.at(i)--;
        }
        if(H.at(i) < H.at(i-1)){
            ans = false;
            break;
        }
    }
    if(ans == true){cout << "Yes" << endl;}
    if(ans == false){cout << "No" << endl;}
}