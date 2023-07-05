/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/43262673
 * Submitted at: 2023-07-05 12:47:07
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_z
 * Result: AC
 * Execution Time: 34 ms
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
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

// ~~~ 追加する直線の傾きが単調減少と仮定 ~~~ //
class ConvexHullTrick{
public:
    ConvexHullTrick(){}

    class Line {
    public:
        long long a, b;
        explicit Line(long long _a, long long _b){
            a = _a;
            b = _b;
        }
    };

    void addLine(long long a, long long b){
        // 傾きが単調減少の場合
        // → 直線はその場で必ず追加
        // → 判定すべきは既存の直線の削除のみ ( 均しO(1)で直線追加可能 )
        Line now_line = Line(a, b);
        while( lines.size() >= 2 && lineCheck(lines[lines.size()-2], lines.back(), now_line) ){
            lines.pop_back();
        }
        
        lines.push_back(Line(a, b));
    }

    long long query(long long x){
        // クエリ最小値が単調減少
        // → 一回最小値が更新されたらもうそれは使わない
        // → deque で古い順から消していく
        while( lines.size() >= 2 && f(lines[0], x) >= f(lines[1], x) ){
            lines.pop_front();
        }
        return f(lines[0], x);
    }

    inline bool lineCheck(Line &l1, Line &l2, Line &l3){
        // l2 が l3 によって不要な直線になってるかを確認
        // → l1 と l3 の交点が l1 と l2 の交点より 小さい ⇔ l2が不要
        return (l3.a-l2.a)*(l3.b-l1.b) <= (l2.b-l3.b)*(l1.a-l3.a);
    }

    inline long long f(Line &l, long long x){
        // xでの直線のy座標
        return l.a*x + l.b;
    }

private:
    deque<Line> lines;

};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    // 解説AC (Convex Hull Trick)
    // あるxでの、直線群の最小値を 1クエリ当たり O(logN) で求める algorithm を用いる。
    // → 普通の frog 同様に遷移を書くと O(N^2) で間に合わない
    // → 式変形すると、過去の j と i に依存する項 と j のみに依存する項が出現
    // → これって i における過去の dp を用いた直線群 の最小値であると気付く
    // → 傾きが 単調減少 & 初手から傾きが負 故にクエリ最小値も単調減少 → 簡単な CHT で O(N) で求まる！！！

    ll n,c; input(n,c);
    vector<ll> h(n);
    rep(i,n)input(h[i]);

    vector<ll> dp(n,1e16);
    dp[0] = 0;
    ConvexHullTrick cht;
    cht.addLine(-2*h[0],h[0]*h[0]);

    for(ll i=1;i<n;i++){
        ll cand = cht.query(h[i]);
        dp[i] = cand + h[i]*h[i] + c;
        cht.addLine(-2*h[i],dp[i] + h[i]*h[i]);
    }
    print(dp[n-1]);
    
    return 0;
}