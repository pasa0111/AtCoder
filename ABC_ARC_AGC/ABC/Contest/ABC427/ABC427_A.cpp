#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

int main(){
    string S, ans = "";
    cin >> S;
    for(int i = 0; i < S.size(); i++){
        if(i != (S.size()+1)/2 - 1){
            ans += S.at(i);
        }
    }
    cout << ans << endl;
}