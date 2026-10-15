#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> Acopy(N);
    vector<pair<int, int>> Q(N);
    vector<pair<int, int>> P(N); //(A, number)

    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    Acopy = A;

    for(int i = 0; i < N; i++){
        P.at(i).first = A.at(i);
        P.at(i).second = i;
    }

    sort(P.begin(), P.end());
    sort(Acopy.begin(), Acopy.end());

    P.at(0).first = 1;

    for(int i = 1; i < N; i++){
        if(Acopy.at(i) > Acopy.at(i-1)){
            P.at(i).first = P.at(i-1).first + 1;
        }
        if(Acopy.at(i) == Acopy.at(i-1)){
            P.at(i).first = P.at(i-1).first;
        }
    }
    
    for(int i = 0; i < N; i++){
        Q.at(i) = make_pair(P.at(i).second, P.at(i).first);
    }

    sort(Q.begin(), Q.end());

    for(int i = 0; i < N; i++){
        cout << Q.at(i).second << " ";
    }

}