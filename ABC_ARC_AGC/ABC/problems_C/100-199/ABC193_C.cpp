#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
using namespace std;

int main(){
    unsigned long long N;
    cin >> N;
    set<unsigned long long> ans;
    for(unsigned long long i = 2; i <= sqrt(N); i++){
        if(ans.count(i)==false){
            unsigned long long I = i;
            for(unsigned long long j = 2; j <= 34; j++){
                I *= i;
                //cout << "I = " << I << endl;
                if(I > N){break;}
                if(ans.count(I) == false){
                    ans.insert(I);
                    //cout << "add:" << I << endl;
                }
            }
        }
    }
    cout << N - ans.size() << endl;
}