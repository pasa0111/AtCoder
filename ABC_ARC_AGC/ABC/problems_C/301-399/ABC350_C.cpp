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
    int N, K = 0;
    cin >> N;
    vector<int> A(N+1);
    vector<int> &B = A;
    vector<pair<int,int>> ans(N);
    for(int i = 1; i <= N; i++){cin >> B.at(i);}
    for(int i = 1; i <= N; i++){
        while(B.at(i) != i){
            int x = B.at(i), y = B.at(B.at(i));
            B.at(i) = y;
            B.at(x) = x;
            ans.at(K).first = i;
            ans.at(K).second = x;
            K++;
        }
    }
    cout << K << endl;
    for(int i = 0; i < K; i++){cout << ans.at(i).first << " " << ans.at(i).second << endl;}
}