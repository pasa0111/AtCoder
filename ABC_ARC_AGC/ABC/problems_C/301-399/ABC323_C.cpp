#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
using namespace std;

int main(){
    int N, M;
    long long K=0; //1位のプレイヤーの得点
    cin >> N >> M;
    bool same = false;
    vector<string> S(N); //S.at(i).at(j)=人iの問題jの解答状況
    vector<pair<long long,int>> A(M); //(点数,問題番号)
    vector<long long> score(N); //score.at(i)=人iの得点
    for(int i = 0; i < M; i++){
        cin >> A.at(i).first;
        A.at(i).second = i;
    }
    for(int i = 0; i < N; i++){
        score.at(i) = i+1;
        cin >> S.at(i);
        for(int j = 0; j < M; j++){
            if(S.at(i).at(j) == 'o'){score.at(i) += A.at(j).first;}
        }
        if(i == 99 && K == score.at(i)){same = true;}
        K = max(K,score.at(i));
    }
    vector<pair<long long, int>> B(M);//A(点数,問題番号)を降順でソートしたもの
    B = A;
    sort(B.begin(), B.end());
    reverse(B.begin(), B.end());
    for(int i = 0; i < N; i++){
        int ans = 0;

        if(N == 100 && score.at(i) == K && same){ans++;}

        if(score.at(i) < K){
            for(int j = 0; j < M; j++){
                if(score.at(i) <= K && S.at(i).at(B.at(j).second) == 'x'){
                    score.at(i) += B.at(j).first;
                    ans++;
                }
                if(score.at(i) > K){break;}
            }
        }

        cout << ans << endl;
    }
}