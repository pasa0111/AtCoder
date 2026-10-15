#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
using namespace std;

int main(){
    long long L, ans;
    cin >> L;
    ans = (L-1)*(L-2)/2*(L-3)/3*(L-4)/4*(L-5)/5*(L-6)/6*(L-7)/7*(L-8)/8*(L-9)/9*(L-10)/10*(L-11)/11;
    cout << ans << endl;
}