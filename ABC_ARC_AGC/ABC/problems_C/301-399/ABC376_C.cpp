#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
using namespace std;

int main(){
    int N, x = -1;
    cin >> N;
    vector<int> A(N), B(N-1);
    for(int i = 0; i < N; i++){cin >> A.at(i);}
    for(int i = 0; i < N-1; i++){cin >> B.at(i);}
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    //おもちゃiを除いて箱におもちゃを全部入れる
    for(int i = 0; i < N; i++){
        if(A.at(N-1) > B.at(N-2)){i=N-1;}
        //cout << "i=" << i << endl;
        bool p = true;
        int k = 0;
        //おもちゃjを空いている最も小さい箱に入れる
        for(int j = 0; j < N; j++){
            //cout << "A:" << A.at(j) << ", B:" << B.at(j-k) << endl; 
            if(i == j){k++;}
            else{
                if(B.at(j-k) < A.at(j)){
                    if(i < j){i = j-1;}
                    if(i > j){i = N;}
                    p = false;
                    break;
                }
            }
        }

        if(p == true){
            x = A.at(i);
            break;
        }
    }
    cout << x << endl;
}