#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
using namespace std;

int main(){
    int N,a,M,m;
    cin >> N;
    set<int> card;
    for(int i = 0; i < N; i++){
        cin >> a;
        card.insert(a);
    }
    M = *rbegin(card);
    m = *begin(card);
    while(M != m){
        if(M != m){
            card.erase(M);
            card.insert(M-m);
        }
        M = *rbegin(card);
        m = *begin(card);
    }
    cout << *begin(card) << endl;
}