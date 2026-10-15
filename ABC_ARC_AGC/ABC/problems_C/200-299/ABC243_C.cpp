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
    bool ans = false;
    int N;
    string S;
    cin >> N;
    vector<pair<int,int>> P(N);
    map<int,vector<pair<int,int>>> Q; //y座標をkeyとし、y座標が同じ人の(x座標,番号)を保存
    for(int i = 0; i < N; i++){
        cin >> P.at(i).first >> P.at(i).second;
        if(!Q.count(P.at(i).second)){Q[P.at(i).second]={};}
        Q.at(P.at(i).second).push_back(make_pair(P.at(i).first,i));
    }
    cin >> S;
    for(auto &i:Q){sort(i.second.begin(), i.second.end());}

    for(auto &i:Q){
        if(i.second.size() >= 2){
            int n = i.second.size();
            for(int j = 0; j < n-1; j++){
                if(S.at(i.second.at(j).second) == 'R'){
                    for(int k = j+1; k < n; k++){
                        if(S.at(i.second.at(k).second) == 'L'){
                            ans = true;
                            j = n;
                            break;
                        }
                    }
                }
            }
        }
        if(ans){break;}
    }
    if(ans){cout << "Yes" << endl;}
    if(!ans){cout << "No" << endl;}
}