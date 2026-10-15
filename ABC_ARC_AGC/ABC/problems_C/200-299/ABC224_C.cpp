#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <deque>
using namespace std;

int main(){
    int N, ans = 0;
    cin >> N;
    vector<pair<long long,long long>> P(N); //(x,y)
    for(int i = 0; i < N; i++){
        cin >> P.at(i).first >> P.at(i).second;
    }
    for(int i = 0; i <= N-3; i++){
        for(int j = i+1; j <= N-2; j++){
            for(int k = j+1; k <= N-1; k++){
                if(P.at(i).first != P.at(j).first || P.at(j).first != P.at(k).first || P.at(k).first != P.at(i).first){
                    if(P.at(i).second != P.at(j).second || P.at(j).second != P.at(k).second || P.at(k).second != P.at(i).second){
                        if(P.at(k).second * (P.at(j).first-P.at(i).first) != (P.at(j).second-P.at(i).second) * (P.at(k).first - P.at(i).first) + P.at(i).second * (P.at(j).first-P.at(i).first)){
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}