#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <deque>
using namespace std;

int main(){
    int N, K, a, ans = 0, t;
    cin >> N >> K;
    vector<int> balls(N);
    for(int i = 0; i < N; i++){
        cin >> a;
        balls.at(a)++;
    }

    t = min(balls.at(0), K);
    for(int i = 1; i < N; i++){
        if(t == 0){break;}
        if(balls.at(i) <= t){
            ans += i * (t - balls.at(i));
            t = balls.at(i);
        }
    }
    cout << ans << endl;
}