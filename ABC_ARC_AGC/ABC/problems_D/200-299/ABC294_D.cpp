#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
using namespace std;

int main(){
    set<int> one; //まだ受付に呼ばれてない人の番号を保存
    set<int> two; //呼ばれているのに受付に行っていない人の番号を保存
    int N, Q, a, x;
    cin >> N >> Q;
    for(int i = 1; i <= N; i++){one.insert(i);}
    for(int q = 0; q < Q; q++){
        cin >> a;
        if(a == 1){
            two.insert(*begin(one));
            one.erase(*begin(one));
        }

        if(a == 2){
            cin >> x;
            two.erase(x);
        }

        if(a == 3){
            cout << *begin(two) << endl;
        }
    }
}