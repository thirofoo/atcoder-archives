/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc137/submissions/30400267
 * Submitted at: 2022-03-25 19:14:45
 * Problem URL: https://atcoder.jp/contests/arc137/tasks/arc137_c
 * Result: AC
 * Execution Time: 90 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n)cin >> a[i];

    //勝ち負けを付けるゲームの判定 => 必ず先手or後手必勝
    // → とある盤面がどちらかは操作後が先手必勝or後手必勝かを議論する。


    //帰納法：
    //A(n-1)+2 <= A(n)の時で、
    //①A(n)を左辺より小さくしたときに後手必勝盤面の時
    // => 仮定より勿論このゲームにおける先手必勝。
    //②A(n)を左辺より小さくしたときに先手必勝盤面と仮定すると、
    //A(n) = A(n-1)+1にすると、相手に①の状況を渡せる。 => 相手の手番で後手必勝が決まる
    // => このゲームにおいて先手必勝。
    // 上記よりいかなる場合でも先手必勝。
    if(a[a.size()-1] >= a[a.size()-2]+2)return cout << "Alice" << endl,0;

    //上記より、自分の操作でA(n-1)+2 <= A(n)を作り出したら即負け。
    // => A(n) = A(n-1)-1とするしかない。
    // => この操作を続けると階段みたいになる。(0,1,2,3,...)(これ以上操作不可の状態)
    // => 山を完成させるまでにかかる手数は、a(n)-n+1 回。

    //よってnが偶数の時、
    // a(n)が偶数なら先手必勝、奇数なら後手必勝。
    //nが奇数の時、
    // a(n)が偶数なら後手必勝、奇数なら先手必勝。

    // => a(n)とnの偶奇が一致すれば先手必勝。

    if((a.back()-n)%2 == 0)cout << "Alice" << endl;
    else cout << "Bob" << endl;

    return 0;
}