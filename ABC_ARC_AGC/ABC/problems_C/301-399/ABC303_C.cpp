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
    int N, M, H, K;
    string S;
    bool ans = true;
    cin >> N >> M >> H >> K >> S;
    pair<int,int> takahashi = make_pair(0,0);
    set<pair<int,int>> item;
    for(int i = 0; i < M; i++){
        int x, y;
        cin >> x >> y;
        item.insert(make_pair(x,y));
    }

    for(int i = 0; i < N; i++){
        if(H == 0){
            ans = false;
            break;
        }
        
        if(H > 0){
            if(S.at(i) == 'R'){takahashi.first++;}
            if(S.at(i) == 'L'){takahashi.first--;}
            if(S.at(i) == 'U'){takahashi.second++;}
            if(S.at(i) == 'D'){takahashi.second--;}

            H--;
            
            if(item.count(make_pair(takahashi.first,takahashi.second)) && H < K){
                H = K;
                item.erase(make_pair(takahashi.first,takahashi.second));
            }
        }
    }
    if(ans){cout << "Yes" << endl;}
    if(!ans){cout << "No" << endl;}
}