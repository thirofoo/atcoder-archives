/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc268/submissions/34773210
 * Submitted at: 2022-09-11 12:18:26
 * Problem URL: https://atcoder.jp/contests/abc268/tasks/abc268_e
 * Result: AC
 * Execution Time: 46 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
template<class T, class... Ts> void print(const T& a, const Ts&... b){cout << a;(cout << ... << (cout << ' ', b));cout << '\n';}
template<class... T> void input(T&... a){(cin >> ... >> a);}
void print(){cout << '\n';}
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll,string> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説AC。imos法に等差数列をねじ込む方針。
    ll n; input(n);
    // imos1 に基準となる回数を入れて、imos2 に回転による増加(減少)分を入れる。
    // 1次関数をimosに入れるのは無理 => forを回すときのidxを用いて線形を表す。(imos自体には定数しか入ってない)
    vector<ll> p(n),imos1(n*2),imos2(n*2);
    rep(i,n){
        input(p[i]);
        p[i] = ((p[i]-i)%n+n)%n;

        //注意：境目はn/2でなくn/2+1にimosを入れないとnが奇数の場合に飛ぶ。

        // 傾き正の直線のbase (p[i]番目に直線の切片を入れる感じ)
        imos1[p[i]] += -p[i];
        imos1[p[i]+n/2+1] += p[i];

        // 傾き正の直線の増加分
        imos2[p[i]] += 1;
        imos2[p[i]+n/2+1] += -1;

        // 傾き負の直線のbase (p[i]番目に直線の切片を入れる感じ)
        imos1[p[i]+n/2+1] += n+p[i];
        imos1[p[i]+n] += -(n+p[i]);

        // 傾き負の直線の減少分
        imos2[p[i]+n/2+1] += -1;
        imos2[p[i]+n] += 1;
    }

    rep(i,n*2-1){
        imos1[i+1] += imos1[i];
        imos2[i+1] += imos2[i];
    }

    ll ans = LLONG_MAX;
    rep(i,n){
        // imosの配列は円を考慮して2周期分用意してるが、各工程で実際に埋めたのは1周期分
        // => 1周期目 + 2周期目 をすることでimosの値がget出来る。
        ans = min(ans,imos1[i]+imos2[i]*i + imos1[i+n]+imos2[i+n]*(n+i));
    }
    print(ans);
    
    return 0;
}