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
    long long R, X, Y, ans;
    cin >> R >> X >> Y;
    if(R*R <= X*X + Y*Y){ans = ceil(sqrt(X*X+Y*Y) / R);}
    if(R*R > X*X + Y*Y){ans = 2;}
    cout << ans << endl;
}