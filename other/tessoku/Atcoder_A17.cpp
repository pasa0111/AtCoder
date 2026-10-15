#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

//部屋xに行くまでにかかる時間の最小値を返す
int MinTime(int x, vector<int> &a, vector<int> &b, vector<int> &m, vector<int> &r){

    if(x >= 3){

        if(m.at(x-1) == -1){
            m.at(x-1) = MinTime(x-1, a, b, m, r);
        }

        if(m.at(x-2) == -1){
            m.at(x-2) = MinTime(x-2, a, b, m, r);
        }
        
        int y = m.at(x-1) + a.at(x);
        int z = m.at(x-2) + b.at(x);

        if(y >= z){
            r.at(x) = x-2;
            m.at(x) = z;
        }

        if(y < z){
            r.at(x) = x-1;
            m.at(x) = y;
        }

        return m.at(x);
    }

    if(x == 2){
        r.at(x) = 1;
        return a.at(2);
    }

    else{
        return 0;
    }

}



int main(){
    int N;
    cin >> N;
    vector<int> A(N+1), B(N+1), M(N+1, -1), R(N+1, -1); //M.at(i) = MinTime(i), R(i) = 部屋iに来る直前にいた部屋の番号
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

    MinTime(N, A, B, M, R);

    bool t = true;
    int y = N;
    stack<int> ans;
    ans.push(N);

    while(t == true){

        ans.push(R.at(y));
        y = R.at(y);

        if(y == 1){
            break;
        }

    }

    cout << ans.size() << endl;

    while(ans.empty() == false){
        cout << ans.top() << " ";
        ans.pop();
    }

}