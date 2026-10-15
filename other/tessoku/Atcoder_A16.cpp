#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//部屋xに行くまでにかかる時間の最小値を返す
int MinTime(int x, vector<int> &a, vector<int> &b, vector<int> &m){

    if(x >= 3){

        if(m.at(x-1) == -1){
            m.at(x-1) = MinTime(x-1, a, b, m);
        }

        if(m.at(x-2) == -1){
            m.at(x-2) = MinTime(x-2, a, b, m);
        }
        
        m.at(x) = min(m.at(x-1) + a.at(x), m.at(x-2) + b.at(x));
        return m.at(x);
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
    vector<int> A(N+1), B(N+1), M(N+1, -1); //M.at(i) = MinTime(i)
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


    ans = MinTime(N, A, B, M);

    
    cout << ans << endl;

}