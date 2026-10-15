#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
using namespace std;

int main(){
    int N, a, b, K, P;
    cin >> N >> a >> b >> K;
    bool ans = true;

    set<int> city;
    city.insert(a);
    city.insert(b);
    for(int i = 0; i < K; i++){
        cin >> P;
        if(city.count(P)){
            ans = false;
            break;
        }
        city.insert(P);
    }
    if(ans == true){cout << "YES" << endl;}
    if(ans == false){cout << "NO" << endl;}
}