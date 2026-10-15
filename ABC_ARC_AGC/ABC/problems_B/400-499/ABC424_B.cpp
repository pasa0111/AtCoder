#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

int main(){
    int N, M ,K, a, b, t = 0;
    cin >> N >> M >> K;
    vector<int> P(N, 0), ans(N, -1);
    for(int i = 0; i < K; i++){
        cin >> a >> b;
        P.at(a-1)++; 

        for(int j = 0; j < N; j++){
            if(P.at(j) == M){
                P.at(j) = -1;
                ans.at(t) = j+1;
                t++;
            }
        }
    }
    t = 0;
    while(ans.at(t) != -1){
        cout << ans.at(t);
        t++;
        if(t >= N){break;}
        if(ans.at(t) != -1){
            cout << " ";
        }
        if(ans.at(t) == -1){
            cout << endl;
        }
    }
}