#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;

int main(){
    int A = 0, B = 0, N, a;
    cin >> N;
    vector<int> card(N);

    for(int i = 0; i < N; i++){
        cin >> card.at(i);
    }
    sort(card.begin(), card.end());

    if(N % 2 == 0){
        for(int i = 1; i <= N; i++){
            a = card.at(i-1);
            if(i % 2 == 0){A += a;}
            if(i % 2 == 1){B += a;}
        }
    }

    if(N % 2 == 1){
        for(int i = 1; i <= N; i++){
            a = card.at(i-1);
            if(i % 2 == 1){A += a;}
            if(i % 2 == 0){B += a;}
        }
    }

    cout << A - B << endl;
}