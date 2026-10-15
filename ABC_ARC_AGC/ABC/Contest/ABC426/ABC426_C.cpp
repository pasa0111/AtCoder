#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
    int N, Q, osmin = 1, osminpc = 1, ans, X, Y;
    cin >> N >> Q;
    vector<int> PC(N+1,1);
    for(int i = 0; i < Q; i++){
        ans = 0;
        cin >> X >> Y;

        if(X >= osmin){
            for(int i = osmin; i <= X; i++){
                PC.at(Y) += PC.at(i);
                ans += PC.at(i);
                PC.at(i) = 0;
            }

            osmin = X + 1;
        }

        cout << ans << endl;
    }
}