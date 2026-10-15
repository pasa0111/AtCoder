#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
using namespace std;

int main(){
    int N, A;
    map<int,int> a;
    vector<pair<int, int>> P;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A;
        if(a.count(A) == false){a[A] = 0;}
        a.at(A)++;
    }
    for(pair<int,int> i:a){P.push_back(make_pair(i.first,i.second));}
    int ps = P.size();
    for(int K = 0; K < N; K++){
        if(ps-K-1 >= 0){
            cout << P.at(ps-K-1).second << endl;
        }
        else{cout << 0 << endl;}
    }
}