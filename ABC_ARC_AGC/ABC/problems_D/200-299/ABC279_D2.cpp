#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

// 高橋くんが地面に到達する時間を計算する関数
// k: 操作回数 (整数)
long double calc_time(long long k, long long A, long long B) {
    // 操作回数が負になることはないが、念のため
    if (k < 0) return 1e18; // 無限大扱いで返す
    
    // 時間 = (操作にかかる時間) + (落下にかかる時間)
    // g は初期値 1 から k 増えるので (1 + k) になる
    return (long double)B * k + (long double)A / sqrt(1.0 + k);
}

int main() {
    // 精度を高く設定して、観客（ジャッジ）を魅了しよう！
    cout << fixed << setprecision(20);

    long long A, B;
    cin >> A >> B;

    // 1. まずは数学の力（微分）で、実数としての最適な k を予測する！
    // 式: k = (A / 2B)^(2/3) - 1
    long double optimal_k_real = pow((long double)A / (2.0 * B), 2.0 / 3.0) - 1.0;

    // 2. 予測した k を挟む「2つの整数」を候補にする
    // floor: 切り捨て（例: 5.7 -> 5）
    // ceil : 切り上げ（例: 5.7 -> 6）
    long long k_floor = (long long)floor(optimal_k_real);
    long long k_ceil  = (long long)ceil(optimal_k_real);

    // 3. k は絶対に 0 以上でなければならない！
    if (k_floor < 0) k_floor = 0;
    if (k_ceil < 0)  k_ceil = 0;

    // 4. 2つの候補で実際にタイムを計測し、速い方を選ぶ！
    long double time1 = calc_time(k_floor, A, B);
    long double time2 = calc_time(k_ceil,  A, B);

    // 小さい方が正義だ！
    if (time1 < time2) {
        cout << time1 << endl;
    } else {
        cout << time2 << endl;
    }

    return 0;
}