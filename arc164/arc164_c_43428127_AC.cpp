/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc164/submissions/43428127
 * Submitted at: 2023-07-09 22:01:04
 * Problem URL: https://atcoder.jp/contests/arc164/tasks/arc164_c
 * Result: AC
 * Execution Time: 49 ms
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

    // a > b のペアが偶数 → Bobは全部いい方が取れる
    // 奇数の時 → 1回だけ良くないやつを選ばなきゃいけない
    ll n; input(n);
    ll cnt = 0, total = 0, min_ab = LLONG_MAX, idx = 0;
    vector<P> card;
    rep(i,n){
        ll a,b; input(a,b);
        if( a > b ) cnt++;
        card.push_back(P(a,b));
        total += max(a,b);
        if( min_ab > max(a,b)-min(a,b) ){
            min_ab = max(a,b)-min(a,b);
            idx = i;
        }
    }
    if( cnt%2 == 0 ){
        print(total);
        return 0;
    }
    ll ans = 0;
    rep(i,n){
        if(i == idx)ans += min(card[i].first,card[i].second);
        else ans += max(card[i].first,card[i].second);
    }
    print(ans);
    
    return 0;
}