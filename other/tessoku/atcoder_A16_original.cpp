#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//部屋xに行くまでにかかる時間の最小値を返す
int MinTime(int x, vector<int> &a, vector<int> &b){
    int y, z;
    if(x >= 3){
        return min(MinTime(x-1, a, b) + a.at(x), MinTime(x-2, a, b) + b.at(x));
    }

    if(x == 2){
        return a.at(2);
    }

    else{
        return 0;
    }

}

int main(){
    int N, ans;
    cin >> N;
    vector<int> A(N+1), B(N+1), M(N+1);
    A.at(0) = 0;
    A.at(1) = 0;
    B.at(0) = 0;
    B.at(1) = 0;
    B.at(2) = 0;

    for (int i = 2; i <= N; i++){
        cin >> A.at(i);
    }

    for (int i = 3; i <= N; i++){
        cin >> B.at(i);
    }


    for(int i = 0; i < N+1; i++){
        M.at(i) = MinTime(i, A, B);
    }

    for(int i = 0; i < N+1; i++){
        cout << M.at(i) << " ";
    }


    ans = MinTime(N, A, B);

    cout << ans << endl;

}