#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

int main(){
    int a,b,c,d,e,f,g,h,i,j,k,l;
    bool ans = false;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l;
    if(min(g,j) < max(a,d) && min(a,d) < max(g,j)){
        if(min(h,k) < max(b,e) && min(b,e) < max(h,k)){
            if(min(i,l) < max(c,f) && min(c,f) < max(i,l)){
                ans = true;
            }
        }
    }
    if(ans == true){cout << "Yes" << endl;}
    if(ans == false){cout << "No" << endl;}
}