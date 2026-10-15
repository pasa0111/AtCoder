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
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for(int i = 0; i < H; i++){cin >> S.at(i);}

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S.at(i).at(j) == 's'){
                if(i >= 4){
                    if(S.at(i-1).at(j) == 'n' && S.at(i-2).at(j) == 'u' && S.at(i-3).at(j) == 'k' && S.at(i-4).at(j) == 'e'){
                        cout << i+1 << " " << j+1 << endl;
                        cout << i << " " << j+1 << endl;
                        cout << i-1 << " " << j+1 << endl;
                        cout << i-2 << " " << j+1 << endl;
                        cout << i-3 << " " << j+1 << endl;
                        i = H;
                        break;
                    }
                    if(j+4 < W){
                        if(S.at(i-1).at(j+1) == 'n' && S.at(i-2).at(j+2) == 'u' && S.at(i-3).at(j+3) == 'k' && S.at(i-4).at(j+4) == 'e'){
                            cout << i+1 << " " << j+1 << endl;
                            cout << i << " " << j+2 << endl;
                            cout << i-1 << " " << j+3 << endl;
                            cout << i-2 << " " << j+4 << endl;
                            cout << i-3 << " " << j+5 << endl;
                            i = H;
                            break;
                        }
                    }
                    if(j-4 >= 0){
                        if(S.at(i-1).at(j-1) == 'n' && S.at(i-2).at(j-2) == 'u' && S.at(i-3).at(j-3) == 'k' && S.at(i-4).at(j-4) == 'e'){
                            cout << i+1 << " " << j+1 << endl;
                            cout << i << " " << j << endl;
                            cout << i-1 << " " << j-1 << endl;
                            cout << i-2 << " " << j-2 << endl;
                            cout << i-3 << " " << j-3 << endl;
                            i = H;
                            break;
                        }
                    }
                }

                if(i+4 < H){
                    if(S.at(i+1).at(j) == 'n' && S.at(i+2).at(j) == 'u' && S.at(i+3).at(j) == 'k' && S.at(i+4).at(j) == 'e'){
                        cout << i+1 << " " << j+1 << endl;
                        cout << i+2 << " " << j+1 << endl;
                        cout << i+3 << " " << j+1 << endl;
                        cout << i+4 << " " << j+1 << endl;
                        cout << i+5 << " " << j+1 << endl;
                        i = H;
                        break;
                    }
                    if(j+4 < W){
                        if(S.at(i+1).at(j+1) == 'n' && S.at(i+2).at(j+2) == 'u' && S.at(i+3).at(j+3) == 'k' && S.at(i+4).at(j+4) == 'e'){
                            cout << i+1 << " " << j+1 << endl;
                            cout << i+2 << " " << j+2 << endl;
                            cout << i+3 << " " << j+3 << endl;
                            cout << i+4 << " " << j+4 << endl;
                            cout << i+5 << " " << j+5 << endl;
                            i = H;
                            break;
                        }
                    }
                    if(j-4 >= 0){
                        if(S.at(i+1).at(j-1) == 'n' && S.at(i+2).at(j-2) == 'u' && S.at(i+3).at(j-3) == 'k' && S.at(i+4).at(j-4) == 'e'){
                            cout << i+1 << " " << j+1 << endl;
                            cout << i+2 << " " << j << endl;
                            cout << i+3 << " " << j-1 << endl;
                            cout << i+4 << " " << j-2 << endl;
                            cout << i+5 << " " << j-3 << endl;
                            i = H;
                            break;
                        }
                    }
                }

                if(j+4 < W){
                    if(S.at(i).at(j+1) == 'n' && S.at(i).at(j+2) == 'u' && S.at(i).at(j+3) == 'k' && S.at(i).at(j+4) == 'e'){
                            cout << i+1 << " " << j+1 << endl;
                            cout << i+1 << " " << j+2 << endl;
                            cout << i+1 << " " << j+3 << endl;
                            cout << i+1 << " " << j+4 << endl;
                            cout << i+1 << " " << j+5 << endl;
                            i = H;
                            break;
                        }
                }

                if(j-4 >= 0){
                    if(S.at(i).at(j-1) == 'n' && S.at(i).at(j-2) == 'u' && S.at(i).at(j-3) == 'k' && S.at(i).at(j-4) == 'e'){
                            cout << i+1 << " " << j+1 << endl;
                            cout << i+1 << " " << j << endl;
                            cout << i+1 << " " << j-1 << endl;
                            cout << i+1 << " " << j-2 << endl;
                            cout << i+1 << " " << j-3 << endl;
                            i = H;
                            break;
                        }
                }
            }
        }
    }
}