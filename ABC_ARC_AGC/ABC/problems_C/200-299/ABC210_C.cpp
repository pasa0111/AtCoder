#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
using namespace std;

int main(){
    long long N, K, c;
    int ans = 0;
    cin >> N >> K;
    deque<long long> row;//注目しているキャンディK個の列
    set<long long> kind;//注目しているK個の中にある色を保存
    map<long long, int> candy; //(色,個数)
    for(int i = 1; i <= N; i++){
        cin >> c;
        row.push_back(c);
        if(kind.count(c)){candy.at(c)++;}
        if(kind.count(c) == false){
            candy[c]=1;
            kind.insert(c);
        }

        if(i >= K+1){
            candy.at(row.front())--;
            if(candy.at(row.front()) == 0){kind.erase(row.front());}
            row.pop_front();
        }

        if(i >= K){
            int a = kind.size();
            ans = max(ans,a);
        }
    }
    cout << ans << endl;
}