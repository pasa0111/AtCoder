# 競プロ用 C++ テンプレート解説ガイド (`template.cpp`)

`template.cpp` に含まれている型エイリアス・定数・マクロ・便利関数・演算子オーバーロードのリファレンスです。

---

## 早見表（チートシート）

| カテゴリ | 名前 | 概要 |
| :--- | :--- | :--- |
| **型・定数** | `ll`, `ull`, `ld` | `long long`, `unsigned long long`, `long double` の短縮名 |
| | `el` | 改行文字 `'\n'` |
| | `inf` / `INF` | `int` 用の無限大 / `ll` 用の無限大|
| | `DX[8]`, `DY[8]` | グリッド探索用の8方向移動ベクトル（先頭4つが上下左右） |
| **マクロ・型** | `rep(i, n)` | `0` から `n - 1` までのループ |
| | `PLqueue<T>` / `PGqueue<T>` | 最大値から出る `priority_queue` / 最小値から出る `priority_queue` |
| **入出力** | `set_stage` | `cin`/`cout` の高速化＆小数出力20桁指定|
| | `vecin(a)` | `vector` や `array` の全要素を一括入力 |
| | `cout << vec` | 配列・集合の中身を `{a,b,c}` 形式で出力 |
| | `yesno(b)` | `true` なら `"Yes"`、`false` なら `"No"` を出力 |
| **配列・グリッド** | `make_vector(...)` | 多次元 `vector` を任意の初期値で生成 |
| | `SORT(a)` / `RSORT(a)` | 昇順ソート / 降順ソート |
| | `REVERSE(a)` | 配列や文字列を反転 |
| | `rotate(S)` | 2次元グリッドを**反時計回りに90度回転**した配列を返す |
| | `sumvec(a)` / `sumvec2d(A)` | 1次元 / 2次元の配列を **in-place で累積和** に変換 |
| **比較更新** | `chmax(a, b)` / `chmin(a, b)` | 最大値 / 最小値の更新 |
| **数学** | `square(a)` | $a^2$ を返す |
| | `intpow(a, b)` | 繰り返し二乗法で $a^b$ を計算 |
| | `intpow(a, b, c)` | 繰り返し二乗法で $a^b \bmod c$ を計算 |
| **`pair` 関連** | `cin >> p` / `cout << p` | `pair` の直接入力 / `(first, second)` 形式での出力 |
| | `p1 + p2` / `p1 - p2` | `pair` 同士の成分ごとの足し算・引き算 |
| | `sqabs(p)` | `pair` $(x, y)$ に対し $x^2 + y^2$ を返す |
| | `dirvec(a, b)` | 2点 `a`, `b` を結ぶ直線の **正規化された方向ベクトル** を返す |

---

## 1. 型エイリアス・定数・マクロ・キュー

### 基本の型と定数
```cpp
using ll = long long;
using ull = unsigned long long;
using ld = long double;
constexpr char el = '\n';
[[maybe_unused]] constexpr ll inf = 1000001001;
[[maybe_unused]] constexpr ll INF = 4000000000000000000;
```
- **`ll`,`ull`,`ld`,`el`**: コードの書きやすさのために置き換えます。
- **`inf` と `INF`**: `inf` は約 $10^9$、`INF` は $4 \times 10^{18}$ です。計算過程で`inf`同士や`INF`同士の足し算が発生してもオーバーフローしない値に設定しています。

**使用例**
```cpp
vector<ll> dist(n, INF);
cout << ans << el;
```
<br>
<br>

### グリッド移動用の方向配列 `DX`, `DY`
```cpp
[[maybe_unused]] constexpr ll DX[8] = {-1, 1, 0, 0, -1, -1,  1, 1};
[[maybe_unused]] constexpr ll DY[8] = { 0, 0,-1, 1, -1,  1, -1, 1};
```

グリッドの隣接するマスに移動するときに使用します。前半の4つで上下左右、全体で8近傍のマスにアクセスできます。

**使用例**
```cpp
rep(k, 4) {
    ll nx = x + DX[k], ny = y + DY[k];
    if (nx < 0 || h <= nx || ny < 0 || w <= ny) continue;
    // (nx, ny) への遷移
}
```
<br>
<br>

### ループマクロ `rep` と優先度付きキュー `PLqueue` / `PGqueue`
```cpp
#define rep(i,n) for (ll i = 0; i < (ll)(n); i++)
template <typename T> using PLqueue = priority_queue<T>;
template <typename T> using PGqueue = priority_queue<T, vector<T>, greater<T>>;
```
- **`rep(i, n)`**：$0 \leq i \leq n-1$ の範囲で $i$ を`ll` 型でループします。
- **`PLqueue<T>`** (`less<T>`)：**大きい順**に取り出す優先度付きキューです。
- **`PGqueue<T>`** (`greater<T>`)：**小さい順**に取り出す優先度付きキューです。長い宣言を書かなくて済みます。

**使用例**
```cpp
PLqueue<ll> max_q;              // 大きい値から出る
PGqueue<pair<ll, ll>> min_q;    // (距離, 頂点) を小さい順に取り出す（ダイクストラ法など）
rep(i, n) max_q.push(A[i]);
```
<br>
<br>
<br>

---

## 2. 自動初期設定・入出力ヘルパー

### `set_stage`（自動実行される高速化＆小数設定）
```cpp
struct set_stage {
    set_stage() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout << fixed << setprecision(20);
    }
} set_stage_0w0;
```
`cin`,`cout`の高速化、小数点以下20桁の出力の設定を行います。グローバル変数 `set_stage_0w0` のコンストラクタとして `main()` が始まる前に自動で実行されます。

**使用例**
```cpp
// main() 内で設定を書かなくても、そのまま小数点以下20桁で出力される
ld ans = 1.0L / 3.0L;
cout << ans << el; // 0.33333333333333333334
```

<br>
<br>

### `vecin(a)`（コンテナの一括入力）
```cpp
template <typename T> T& vecin(T& a) {
    for (auto& x : a) cin >> x;
    return a;
}
```
配列の要素を一括で入力し、その参照を返します。`vector` だけでなく `array` や `deque` にも使えます。

**使用例**
```cpp
vector<ll> A(n); vecin(A);
array<ll, 3> B; vecin(B);
deque<ll> D(n); vecin(D);
```

<br>
<br>

### コンテナの出力 `operator<<`
```cpp
template <ranges::range R>
requires(!is_convertible_v<R, string_view>)
ostream &operator<<(ostream &os, const R &a) {
    if constexpr (is_same_v<ranges::range_value_t<R>, string>) {
        bool f = true;
        for (const auto &x : a) {
            if (!f) os << '\n';
            f = false;
            os << x;
        }
        return os;
    } else {
        os << "{";
        bool f = 1;
        for (const auto &x : a) {
            if (!f) os << ",";
            f = 0;
            os << x;
        }
        return os << "}";
    }
}
```
- `.begin()` と `.end()` を持つコンテナの要素 $x_1, x_2, \dots$ を `{x1,x2,...}` の形式で出力します。ただし、`vector<string>` は各文字列 $S_1, S_2, \dots$ をこの順で改行区切りで出力します。
- [後述](#pair-の入出力-operator-operator)する`pair`の出力と合わせると`map`の出力もできます。

**使用例**
```cpp
cout << A << el;   // vector や set は "{1,2,3}" の形式で出力
cout << S << el;   // vector<string> のときだけ、各行が改行区切りで綺麗に出力される
cout << M << el;   // mapは {(key,value),...} の形式で出力
```

<br>
<br>

### `yesno(b)`（判定結果の出力）
```cpp
void yesno(bool b) {
    cout << (b ? "Yes" : "No") << el;
}
```
渡した条件式 `b` が `true` なら `"Yes"`、`false` なら `"No"` を改行付きで出力します。

**使用例**
```cpp
// 問題:整数x,yが与えられるので x+y <= 10 かつ xy <= 20 であるか判定してください。
int x,y;
cin >> x >> y;
yesno(x+y <= 10 && x*y <= 20);
```

<br>
<br>
<br>

---

## 3. 配列・グリッド操作関数

### `make_vector`（多次元 `vector` 生成）
```cpp
template <typename T> vector<T> make_vector(size_t a, T b) {
    return vector<T>(a, b);
}
template <typename... Ts> auto make_vector(size_t a, Ts... ts) {
    return vector(a, make_vector(ts...));
}
```
`vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(x+1, vector<ll>(2,INF)));` のような長い宣言を書かずに`vector`を生成できます。
- **注意**: 一番最後の引数の型が要素の型になります。0で初期化された `ll` 配列を生成するときは最後の引数を `0LL` や`ll(0)`にしてください( `0` だと `int` 配列になります)。 

**使用例**
```cpp
auto dist = make_vector(h, w, INF);           // h × w を INF で初期化
auto dp = make_vector(n, m, 2, mint(0)); // n × m × 2 の mint 型配列
```
<br>
<br>

### `SORT(a)` / `RSORT(a)` / `REVERSE(a)`
```cpp
template <typename T> T &SORT(T &a) { sort(a.begin(), a.end()); return a; }
template <typename T> T &RSORT(T &a) { sort(a.rbegin(), a.rend()); return a; }
template <typename T> T &REVERSE(T &a) { reverse(a.begin(), a.end()); return a; }
```
コンテナ全体を昇順ソート・降順ソート・反転します。`vector`, `array`, `string`, `deque` すべてに使え、自分自身の参照（`T&`）を返すため式の途中に直接書くこともできます。

**使用例**
```cpp
SORT(A);                  // 昇順ソート
RSORT(A);                 // 降順ソート
REVERSE(S);               // 文字列や配列の反転
if (SORT(A) == SORT(B)) { // ソートした結果をその場で比較
    ...
}
```

<br>
<br>

### `rotate(S)`（2次元配列の90度回転）
```cpp
template <typename T> vector<T> rotate(const vector<T> &S) {
    assert(!S.empty());
    int h = S.size(), w = S[0].size();
    vector<T> res(w);
    for (int i = 0; i < w; i++) res[i].resize(h);
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            res[i][j] = S[j][w - 1 - i];
        }
    }
    return res;
}
```
2次元配列（サイズ $H \times W$）を **反時計回りに90度回転** した新しい2次元配列（サイズ $W \times H$）を返します。
- `vector<string>` にも `vector<vector<ll>>` にも使えます。
- 180度回転は `rotate(rotate(S))`、時計回り90度回転は3回重ねて `rotate(rotate(rotate(S)))` と書けます。

**使用例**
```cpp
vector<string> S = {"ABC", "DEF"};
S = rotate(S);
// 結果:
// CF
// BE
// AD
```

<br>
<br>

### `sumvec(a)` / `sumvec2d(A)`（in-place 累積和）
```cpp
template <typename T> T &sumvec(T &a) {
    for (size_t i = 1; i < a.size(); i++) a[i] += a[i - 1];
    return a;
}

template <typename T> vector<vector<T>> &sumvec2d(vector<vector<T>> &A) {
    ll h = A.size();
    if (h == 0) return A;
    ll w = A[0].size();
    for (ll i = 0; i < h; i++) for (ll j = 1; j < w; j++) A[i][j] += A[i][j - 1];
    for (ll j = 0; j < w; j++) for (ll i = 1; i < h; i++) A[i][j] += A[i - 1][j];
    return A;
}
```
元の配列を直接書き換えて累積和に変換し、その参照を返します。
- **1次元 `sumvec(A)`**: `vector` や `array`、`deque` に使え、`A[i]` が $A_0 + A_1 + \dots + A_i$ になります。
- **2次元 `sumvec2d(A)`**: `A[i][j]` が左上 `(0, 0)` から `(i, j)` までの長方形領域の総和になります。

**使用例**
```cpp
// 1次元累積和: 閉区間 [l, r] の和
sumvec(A);
ll s = A[r] - A[l-1];

// 2次元累積和: [x1, x2] × [y1, y2] の和を求める
auto S = make_vector(h+1, w+1, 0LL);
for(ll i = 1; i <= h; i++)for(ll j = 1; j <= w; j++) cin >> S[i][j];
sumvec2d(S);
ll rect_sum = S[x2][y2] - S[x1-1][y2] - S[x2][y1-1] + S[x1-1][y1-1];
```

<br>
<br>
<br>

---

## 4. 比較・更新ヘルパー

### `chmax(a, b)` / `chmin(a, b)`
```cpp
template <typename T, typename U> bool chmax(T& a, U b) {
    if (a < b) { a = b; return true; }
    return false;
}
template <typename T, typename U> bool chmin(T& a, U b) {
    if (a > b) { a = b; return true; }
    return false;
}
```
`a` より `b` の方が大きければ（`chmin` なら小さければ）`a = b` に書き換えて `true` を返し、それ以外は `false` を返します。

**使用例**
```cpp
chmax(ans, score); // ans = max(ans, score)

// ダイクストラ法などで「最短距離が更新されたときだけキューに入れる」処理
if (chmin(dist[to], dist[v] + cost)) {
    que.emplace(dist[to], to);
}
```

<br>
<br>
<br>

---

## 5. 数学関数

### `square(a)`
```cpp
template <typename T> auto square(T a) {
    using Ret = conditional_t<is_integral_v<T> && (sizeof(T) < sizeof(ll)), ll, T>;
    return Ret(a) * Ret(a);
}
```
- `a` の2乗を返します。特に`a`が複雑な式であるときに便利です。
- 引数が `int` などの32bit以下の整数型であっても自動で `ll` に昇格してから掛け算するため、オーバーフローを防げます（`double` や `mint` を渡した場合はそのままの型で計算されます）。

**使用例**
```cpp
ll d = square(x1 - x2); // x1, x2 が int でも ll で安全に2乗される
```

<br>
<br>

### `intpow(a, b)` / `intpow(a, b, c)` 
```cpp
template <typename T> auto intpow(T a, ll b) {
    using Ret = std::conditional_t<std::is_integral_v<T> && (sizeof(T) < sizeof(ll)), ll, T>;
    assert(b >= 0);
    Ret res = 1;
    Ret base = a;
    while (b) {
        if (b & 1) res *= base;
        b >>= 1;
        if (!b) break;
        base *= base;
    }
    return res;
}

ll intpow(ll a, ll b, ll c) {
    assert(b >= 0 && c > 0);
    ll res = 1 % c, base = (a % c + c) % c;
    while (b) {
        if (b & 1) res = (res * base) % c;
        b >>= 1;
        if (!b) break;
        base = (base * base) % c;
    }
    return res;
}
```
整数の自然数乗を繰り返し二乗法（$O(\log b)$）で計算します。
1. **`intpow(a, b)`**: $a^b$を計算します。`int` を渡しても自動で `ll` に昇格します。また ACL の `mint` を第1引数に渡すことも可能です。
2. **`intpow(a, b, c)`**: $a^b \bmod c$ を `ll` で計算します。`a` が負の数でも正しく $0$ 以上の余りを返します（※内部で `(base * base) % c` を行うため、$c \le 3 \times 10^9$ の範囲で使います）。

**使用例**
```cpp
ll p1 = intpow(2, 40);             // 1099511627776LL（int でも溢れない）
mint p2 = intpow(mint(2), n);      // mint 上での 2^n
ll p3 = intpow(a, b, 998244353LL); // a^b mod 998244353
```

<br>
<br>
<br>

---

## 6. `pair` 型関連の機能（入出力・ベクトル演算・幾何）

### `pair` の入出力 `operator>>`, `operator<<`
```cpp
template <typename T, typename U> istream &operator>>(istream &is, pair<T, U> &p) {
    is >> p.first >> p.second;
    return is;
}
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}
```
- **入力 (`>>`)**: `p.first` と `p.second` を順番に読み込みます。`vecin` と組み合わせることで、座標列や辺集合の入力が1行で書けます。
- **出力 (`<<`)**: `(first, second)` の形式で出力します（`vector<pair<ll, ll>>` を `cout` に流すと `{(1, 2),(3, 4)}` のように出力されます）。

**使用例**
```cpp
pair<ll, ll> p;
cin >> p;                        // 2つの値を直接 p に読み込む
cout << p << el;                 // "(x, y)"

vector<pair<ll, ll>> P(n);
vecin(P);                        // (x_i, y_i) を n 個まとめて一括入力
```
<br>
<br>

### `pair` 同士の加減算 `operator+`, `operator-`
```cpp
template <typename T, typename U> pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) {
    return {a.first + b.first, a.second + b.second};
}
template <typename T, typename U> pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) {
    return {a.first - b.first, a.second - b.second};
}
```
成分ごとに足し算・引き算した新しい `pair` を返します。グリッド上の座標移動や、2点間の相対ベクトルを求めるときに便利です。

**使用例**
```cpp
pair<ll, ll> cur = {2, 3}, dir = {-1, 0};
auto nxt = cur + dir; // (1, 3)
```
<br>
<br>

### 距離の2乗 `sqabs(a)`
```cpp
template <typename T, typename U> auto sqabs(const pair<T, U>& a) {
    return square(a.first) + square(a.second);
}
```
原点から `a` までのユークリッド距離の2乗 $x^2 + y^2$ を返します。先述の `operator-` と組み合わせることで2点間距離の2乗が1行で求まります。

**使用例**
```cpp
pair<ll, ll> p1 = {3, 5}, p2 = {1, 2};
ll d2 = sqabs(p1 - p2); // (3-1)^2 + (5-2)^2 = 13
if (sqabs(p1 - p2) <= square(r)) { ... }
```

<br>
<br>

### 直線の傾きの正規化ベクトル `dirvec(a, b)`
```cpp
pair<ll, ll> dirvec(pair<ll, ll> a, pair<ll, ll> b) {
    ll dx = a.first - b.first, dy = a.second - b.second;
    if (dx == 0 && dy == 0) return pair(0, 0);
    else if (dx == 0) return pair(0, 1);
    else if (dy == 0) return pair(1, 0);
    if (dx < 0) { dx = -dx; dy = -dy; }
    ll g = gcd(dx, abs(dy));
    dx /= g, dy /= g;
    return pair(dx, dy);
}
```
2点 `a`, `b` を結ぶ直線の方向ベクトル $(dx, dy)$ を、最大公約数で割り、かつ符号を揃えて一意な形に正規化します。直線の傾きが関係する問題で便利です。
- `a == b` のとき：`(0, 0)`
- 縦の直線（$dx = 0$）のとき：`(0, 1)`
- 横の直線（$dy = 0$）のとき：`(1, 0)`
- それ以外：**`dx > 0`** かつ **$\gcd(dx, |dy|) = 1$** となる `(dx, dy)`

**使用例**
```cpp
// 点 a, b, c が同一直線上にあるかの判定（a != b, a != c）
if (dirvec(a, b) == dirvec(a, c)) { ... }

// 直線の傾きごとに個数を集計する
map<pair<ll, ll>, ll> slope_cnt;
slope_cnt[dirvec({0, 0}, {x, y})]++;
```
