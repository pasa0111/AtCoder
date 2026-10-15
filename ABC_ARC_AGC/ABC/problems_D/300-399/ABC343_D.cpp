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
    int N, T;
    cin >> N >> T;
    map<long long,int> num; //[i]点の人が何人いるか保存
    map<int,long long> score; //人[i]の得点を保存
    set<long long> ans; //得点の種類を保存
    num[0] = N;
    ans.insert(0);
    for(int i = 0; i < T; i++){
        int A;
        long long B;
        cin >> A >> B;
        if(!score.count(A)){
            score[A] = 0;
        }
        if(num.count(score.at(A))){
            num.at(score.at(A))--;
            if(num.at(score.at(A)) == 0){ans.erase(score.at(A));}
        }
        score.at(A) += B;
        if(!num.count(score.at(A))){
            num[score.at(A)] = 0;
        }
        ans.insert(score.at(A));
        //for(long long i:ans){cout << i << " ";}
        //cout << endl;
        num.at(score.at(A))++;
        cout << ans.size() << endl;
    }
}