#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

int main(){
    int N, ans = 0;
    cin >> N;
    vector<tuple<int, int, int>> skills(N+1, make_tuple(-1,-1,-1));
    set<int> learned;
    stack<int> learning;
    for(int i = 1; i <= N; i++){
        cin >> get<0>(skills.at(i)) >> get<1>(skills.at(i));
        get<2>(skills.at(i)) = i;
        if(get<0>(skills.at(i)) == 0 && get<1>(skills.at(i)) == 0){
            ans++;
            learned.insert(i);
            learning.push(i);
        }
    }
    sort(skills.begin(), skills.end());

    if(ans > 0){
        while(learning.empty() == false){
            for(int i = ans+1; i <= N; i++){
                if(learning.top() == get<0>(skills.at(i)) || learning.top() == get<1>(skills.at(i))){
                    get<0>(skills.at(i)) = 0;
                    get<1>(skills.at(i)) = 0;
                    ans++;
                    learned.insert(get<2>(skills.at(i)));
                    learning.push(get<2>(skills.at(i)));
                }
            }
            sort(skills.begin(), skills.end());
            learning.pop();
        }
    }

    cout << ans << endl;
}