#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    long long N, M, C;
    cin >> N >> M >> C;
    map<long long, long long> A;
    for(int i = 0; i < N; i++){
        long long B;
        cin >> B;
        if(!A.count(B)){A[B] = 0;}
        A.at(B)++;
    }

    vector<pair<long long, long long>> P;
    for(pair<long long, long long> a:A){P.push_back(a);}

    long long n = 0, a = 0, ans = 0;
    long long q = P.size();
    while(a < q){
    for(pair<long long, long long> x:A){
        n += x.second;
        if(n >= C){
            while(n >= C && a < q){
                if(a == 0){ans += (P.at(a).first+M-P.at(q-1).first)*n;}
                if(a > 0){ans += (P.at(a).first-P.at(a-1).first)*n;}
                n -= P.at(a).second;
                a++;
            }
        }
    }
    }

    cout << ans << endl;
}