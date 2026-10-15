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
    int N, K;
    cin >> N >> K;
    map<int,int> ball; //[i]が書かれたボールが何個あるか保存
    map<int,int> num; //同じ数字が[i]個あるボールの種類数を保存
    set<int> kind;
    for(int i = 0; i < N; i++){
        int A;
        cin >> A;
        kind.insert(A);
        if(!ball.count(A)){ball[A] = 0;}
        if(num.count(ball.at(A))){num.at(ball.at(A))--;}
        ball.at(A)++;
        if(!num.count(ball.at(A))){num[ball.at(A)] = 0;}
        num.at(ball.at(A))++;
    }
    
    int s = kind.size();
    int j = 1;
    int ans = 0;
    while(s > K){
        if(num.count(j)){
            if(s - num.at(j) < K){
                while(s > K){
                    s--;
                    ans += j;
                }
                continue;
            }

            if(s - num.at(j) >= K){
                s = s - num.at(j);
                ans += num.at(j)*j;
            }
        }
        j++;
    }
    cout << ans << endl;
}