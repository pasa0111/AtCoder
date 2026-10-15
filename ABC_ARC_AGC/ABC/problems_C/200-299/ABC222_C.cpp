#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<pair<int,int>> rank(N*2);//(勝利回数,人の番号)
    vector<string> play(N*2);
    for(int i = 0; i < N*2; i++){rank.at(i) = make_pair(0,2*N-1-i);}
    for(int i = 0; i < N*2; i++){cin >> play.at(i);}
    for(int r = 0; r < M; r++){
        //for(int i = 0; i < 2*N; i++){cout << "(" << rank.at(i).first << "," << 2*N-1-rank.at(i).second << ")" << endl;}
        for(int k = 0; k < N; k++){
            if(play.at(2*N-1-rank.at(2*k).second).at(r) == 'G'){
                if(play.at(2*N-1-rank.at(2*k+1).second).at(r) == 'C'){rank.at(2*k).first++;}
                if(play.at(2*N-1-rank.at(2*k+1).second).at(r) == 'P'){rank.at(2*k+1).first++;}
            }
            if(play.at(2*N-1-rank.at(2*k).second).at(r) == 'C'){
                if(play.at(2*N-1-rank.at(2*k+1).second).at(r) == 'P'){rank.at(2*k).first++;}
                if(play.at(2*N-1-rank.at(2*k+1).second).at(r) == 'G'){rank.at(2*k+1).first++;}
            }
            if(play.at(2*N-1-rank.at(2*k).second).at(r) == 'P'){
                if(play.at(2*N-1-rank.at(2*k+1).second).at(r) == 'G'){rank.at(2*k).first++;}
                if(play.at(2*N-1-rank.at(2*k+1).second).at(r) == 'C'){rank.at(2*k+1).first++;}
            }
        }
        sort(rank.begin(), rank.end());
        reverse(rank.begin(), rank.end());
    }
    for(int i = 0; i < 2*N; i++){
        cout << 2*N-rank.at(i).second << endl;
    }
}