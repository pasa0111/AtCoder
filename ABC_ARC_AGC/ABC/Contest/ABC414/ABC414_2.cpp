#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
    int64_t N, l, t = 0;
    string c, S;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> c >> l;
        t += l;
        if(t <= 100){
            for(int j = 0; j < l; j++){
                S += c;
            }
        }
        if(t > 100){
            cout << "Too Long" << endl;
            break;
        }
    }
    if(t <= 100){
        cout << S << endl;
    }
}