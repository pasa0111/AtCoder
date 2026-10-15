#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
using namespace std;

int main(){
    long long N, e=0, T=0;
    cin >> N;
    vector<int> H(N);
    vector<int> &h = H;
    for(int i = 0; i < N; i++){
        cin >> H.at(i);
    }
    while(e < N){
        if(h.at(e)/5 == 0){
            T++;
            if(T % 3 == 0){h.at(e) -= 3;}
            if(T % 3 != 0){h.at(e)--;}
            if(h.at(e) <= 0){e++;}
        }

        else{
            int y = h.at(e)/5*3;
            int z = h.at(e)%5;
            T += y;
            h.at(e) = z;
            if(z == 0){e++;}
        }
    }
    cout << T << endl;
}