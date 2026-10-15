#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <iomanip>
#include <bitset>


using namespace std;
#define ll long long
#define rep(i,e) for(ll i = 0; i < e; i++)
#define vecall(vec) vec.begin(),vec.end()
#define vecin(vec) for(unsigned ll i = 0, a = vec.size(); i < a; i++){cin >> vec.at(i);}
#define SORT(vec) sort(vecall(vec))
#define RSORT(vec) SORT(vec);reverse(vecall(vec));
#define MP make_pair

void yesno(bool b){
    if(b) cout << "Yes" << endl;
    if(!b) cout << "No" << endl;
}

int main(){
    int n,k,r,s,p;
    cin >> n >> k >> r >> s >> p;
    vector<vector<int>> hand(k); //0:グー, 1:チョキ, 2:パー
    vector<int> point = {r,s,p};
    string T;
    cin >> T;
    for(int i = 0; i < n; i++){
        char t = T[i];
        if(t == 'r') hand[i%k].push_back(0);
        if(t == 's') hand[i%k].push_back(1);
        if(t == 'p') hand[i%k].push_back(2);
    }
    int score = 0;
    for(int i = 0; i < k; i++){
        vector<int> copy = hand[i];
        int size = hand[i].size();
        for(int j = 0; j < size; j++){
            if(j == 0){
                if(copy[j] == 0) score += point[2];
                else score += point[copy[j]-1];
                continue;
            }
            if(copy[j] != copy[j-1]){
                if(copy[j] == 0) score += point[2];
                else score += point[copy[j]-1];
                continue;
            }
            if(copy[j] == copy[j-1]){
                if(j < size-1){
                    if(copy[j+1] == 0) score += point[2];
                    else score += point[copy[j+1]-1];
                    j++;
                }
            }
        }
    }
    cout << score << endl;
}