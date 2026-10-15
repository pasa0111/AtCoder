#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
using namespace std;

int main(){
    int N;
    cin >> N;
    for(int n = 1; n <= N; n++){
        set<tuple<int,int,int>> ans;
        int s = sqrt(n/6), t = sqrt(n);
        for(int x = 1; x <= s; x++){
            for(int z = s; z <= t; z++){
                for(int y = x; y <= z; y++){
                    if(x*x + y*y + z*z + x*y + y*z + z*x == n){
                        ans.insert(make_tuple(x,y,z));
                        ans.insert(make_tuple(x,z,y));
                        ans.insert(make_tuple(y,x,z));
                        ans.insert(make_tuple(z,x,y));
                        ans.insert(make_tuple(y,z,x));
                        ans.insert(make_tuple(z,y,x));
                    }
                }
            }
        }
        cout << ans.size() << endl;
    }
}