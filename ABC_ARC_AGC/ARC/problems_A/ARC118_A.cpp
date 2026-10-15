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
    int t, N, num = 0;
    long long A = 1, B = 1;
    cin >> t >> N;
    while(num < N){
        long long C = (100+t)*A/100;
        cout << "A:" << A << "  B:" << B << "  C:" << C << endl;
        if(B == C){B++;}
        if(B < C){
            cout << "jump" << endl;
            num += C-B;
            if(num >= N){B = C-1;}
            if(num < N){B = C+1;}
        }
        
        while(num > N){
            B--;
            num--;
        }

        A++;
    }
    cout << B << endl;
}