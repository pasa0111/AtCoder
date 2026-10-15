#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
using namespace std;

int main(){
    int N, m = 500, I=0;
    cin >> N;
    vector<int> P(N), Q(N);
    set<int> q;
    for(int i = 0; i < N; i++){cin >> P.at(i);}
    for(int i = N-1; i >= 0; i--){
        q.insert(P.at(i));
        if(P.at(i) < m){m = P.at(i);}
        if(P.at(i) > m){
            I = i;
            break;
        }
    }

    for(int i = 0; i < I; i++){
        Q.at(i) = P.at(i);
        cout << Q.at(i) << " ";
    }
    for(int i :q){
        if(i <= P.at(I)-1){Q.at(I) = i;}
        if(i >= P.at(I)){
            q.erase(Q.at(I));
            break;
        }
    } 
    cout << Q.at(I) << " ";
    for(int i = I+1; i < N; i++){
        Q.at(i) = *rbegin(q);
        q.erase(Q.at(i));
        cout << Q.at(i) << " ";
    }

}