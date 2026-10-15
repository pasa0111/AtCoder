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
    double ans = 0;
    cout << fixed << setprecision(7);
    int N, K;
    cin >> N >> K;
    set<int> light; //明かりを持っている人の番号を保存
    vector<pair<long long, long long>> P(N); //人iの座標を保存
    for(int i = 0; i < K; i++){
        int a;
        cin >> a;
        light.insert(a-1);
    }
    for(int i = 0; i < N; i++){cin >> P.at(i).first >> P.at(i).second;}
    
    for(int i = 0; i < N; i++){
        double D = 0; //人iから最も近くにいる明かりを持った人までの距離
        if(!light.count(i)){
            D = 10000000;
            for(int j :light){
                double d = sqrt((P.at(j).first - P.at(i).first)*(P.at(j).first - P.at(i).first) + (P.at(j).second - P.at(i).second)*(P.at(j).second - P.at(i).second));
                //cout << "(i,j) = (" << i << "," << j << ")" << endl; 
                //cout << "d = " << d << endl;
                D = min(d,D);
            }
        }
        ans = max(D,ans);
    }
    cout << ans << endl;
}