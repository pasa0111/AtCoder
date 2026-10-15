#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <deque>
using namespace std;

int main(){
    int a, b, c, ans = 0;
    cin >> a >> b >> c;
    vector<int> v = {a, b, c};
    sort(v.begin(), v.end());
    a = v.at(0),
    b = v.at(1);
    c = v.at(2);
    int p = a % 2, q = b % 2, r = c % 2, t = p + q + r;
    if(t == 0 || t == 3){
        while(a < c){
            a += 2;
            ans++;
        }
        while(b < c){
            b += 2;
            ans++;
        }
    }

    if(t == 1){
        if(p == 1){
            a--;
            ans++;
        }
        if(q == 1){
            b--;
            ans++;
        }
        if(r == 1){
            c--;
            ans++;
        }

        while(a < c){
            a += 2;
            ans++;
        }
        while(b < c){
            b += 2;
            ans++;
        }
    }

    if(t == 2){
        if(p == 0){
            a--;
            ans++;
        }
        if(q == 0){
            b--;
            ans++;
        }
        if(r == 0){
            c--;
            ans++;
        }

        while(a < c){
            a += 2;
            ans++;
        }
        while(b < c){
            b += 2;
            ans++;
        }
    }

    cout << ans << endl;
}