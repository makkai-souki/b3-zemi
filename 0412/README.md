# 4月12日 課題
- 提出は4月19日(月)のB3ゼミ開始前まで
- 提出方法：main.cppをLINEもしくはwasedaメールで送ってください。

# 必須課題
## 問題1：演習2の拡張
1. 5人分のテストの点数を整数で入力
2. 5人のテストの平均・分散・標準偏差を計算
  - 累乗・平方根の計算は自分で調べてみましょう。
3. 5人の偏差値を計算して表示
  - 偏差値の計算式は各自調べてください。

# 任意課題
- 次回の内容も含んでいるので、提出は任意とします。
  - 提出してくれれば出来に応じて加点します。
- 現状のプログラミングスキルの参考にしたいので、途中でも書いた分だけ提出してくれると嬉しいです。
## 問題2：Luhnアルゴリズム
### Luhnアルゴリズムとは？
- クレジットカード番号などで用いられているチェックサムを計算するためのアルゴリズム
### 実装内容
1. クレジットカード番号を想定した14〜16桁の数字を入力
> 例：2149181640611618
2. 下から偶数番目の桁（10の位，1000の位...）の数をそれぞれ2倍して足し合わせる
- ※2倍して2桁の数字になった場合はそれぞれの桁を別々の数字として加える。
> 1×2 + 1×2 + (1 + 2) + 4×2 + 1×2 + 1×2 + 4×2 + 2×2 = 31
3. 下から奇数版目の桁の数を2.の値に足す
> 31 + 8 + 6 + 1 + 0 + 6 + 8 + 9 + 1 = 70
4. 3.の結果を10で割り、余りが0ならば正常、あまりがでるならば異常を出力する
> 70 % 10 = 0 ----> 正常
