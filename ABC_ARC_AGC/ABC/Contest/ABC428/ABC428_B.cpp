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
    int N, K, M = 0;
    string S;
    cin >> N >> K >> S;
    set<string> ans;
    map<string, int> res;
    for(int i = 0; i <= N-K; i++){
        //cout << "i:" << i << endl;
        string s = S.substr(i,K);
        if(ans.count(s)){
            res.at(s)++;
        }
        if(!ans.count(s)){
            ans.insert(s);
            res[s] = 1;
        }
        M = max(M,res.at(s));
    }
    cout << M << endl;
    for(string i:ans){
        if(res.at(i) == M){
            cout << i << " ";
        }
    }
    cout << endl;
}