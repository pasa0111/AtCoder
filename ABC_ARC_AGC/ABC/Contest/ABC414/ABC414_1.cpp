#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
    int N, L, R, x, y, ans = 0;
    cin >> N >> L >> R;
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        if((x <= L) && (y >= R)){
            ans++;
        }
    }
    cout << ans << endl;
}