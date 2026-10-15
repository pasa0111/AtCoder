#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
using namespace std;

int main(){
    int N, ans=0;
    string S;
    cin >> N >> S;
    for(int i = 0; i <= N-2; i++){
        //cout << "i:" << i;
        set<char> X, Y;
        for(int j = 0; j <= i; j++){
            X.insert(S.at(j));
        }
        for(int j = i+1; j <= N-1; j++){
            if(X.count(S.at(j))){Y.insert(S.at(j));}
        }
        int y = Y.size();
        //cout << " y:" << y << endl;
        ans = max(ans,y);
        //cout << ans << endl;
    }
    cout << ans << endl;
}