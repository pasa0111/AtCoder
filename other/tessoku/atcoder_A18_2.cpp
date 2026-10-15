#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
    int N, S, max, x = 0, J = 1;
    bool ans = false;
    cin >> N >> S;
    vector<int> A(N);
    vector<pair<int, string>> card_used(N);

    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    sort(A.begin(), A.end());

    for(int i = 0; i < N; i++){
        card_used.at(i) = make_pair(A.at(i), "x");
        x += A.at(i);
        if(x <= S){
            max = i+1;
        }
    }

    for(int q = 1; q <= max; q++){
        vector<pair<int, int>> T(q+1); //部分和の推移を記録する T[i] = (T[i-1], A)
        for(int n = max; n > 0; n--){
            
        }
        

    }
    
}