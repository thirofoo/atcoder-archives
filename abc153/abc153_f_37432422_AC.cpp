/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc153/submissions/37432422
 * Submitted at: 2022-12-22 02:11:31
 * Problem URL: https://atcoder.jp/contests/abc153/tasks/abc153_f
 * Result: AC
 * Execution Time: 61 ms
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 別解答：尺取り & imos (遅延セグ木の方が直感的)
    // 今回の貪欲でやる場合、imosの区間更新はそれより前方に無影響
    // => 尺取りと同時にimosを進める感じでやれば、同時並行で累積和作成可能！
    ll n,d,a; input(n,d,a);
    vector<P> enemy;
    rep(i,n){
        ll x,h; input(x,h);
        enemy.push_back(P(x,h));
    }
    sort(enemy.begin(),enemy.end());

    vector<ll> cum(n+2,0);
    // l : 操作now , r : 行けない区間外最左端idx (1-indexed)
    ll l = 1, r = 1,ans = 0;
    while(l <= n){
        auto [lp,lhp] = enemy[l-1];
        auto [rp,rhp] = enemy[r-1];

        if(r == n+1 || rp > lp+2*d){
            // rep(i,n+2)cout << cum[i] << " ";
            // print();
            if(lhp > cum[l]){
                ll atack_time = (lhp - cum[l] -1) / a + 1;
                ans += atack_time;
                cum[l] += atack_time*a;
                cum[r] -= atack_time*a;
            }
            cum[l+1] += cum[l];
            ++l;
        }
        else ++r;
    }
    print(ans);
    
    return 0;
}