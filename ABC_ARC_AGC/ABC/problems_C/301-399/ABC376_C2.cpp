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
    vector<pair<int,char>> TB(N+N-1);
    for(int i = 0; i < N; i++){
        cin >> TB.at(i).first;
        TB.at(i).second = 'A';
    }
    for(int i = N; i < N+N-1; i++){
        cin >> TB.at(i).first;
        TB.at(i).second = 'B';
    }

    sort(TB.begin(), TB.end());

    int t = 0, ans = 0;
    for(int i = N+N-2; i >= 0; i--){
        if(TB.at(i).second == 'A'){t--;}
        if(TB.at(i).second == 'B'){t++;}
        //cout << TB.at(i).second <<  "," << TB.at(i).first << " i:" << i << " t:" << t << endl;
        if(t == -1 && ans == 0){
            //cout << "ans?" << endl;
            ans = TB.at(i).first;
            t++;
        }
        if(t == -1 && ans != 0){
            ans = -1;
            break;
        }
    }
    cout << ans << endl;
}