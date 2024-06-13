/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/past17-open/submissions/54502933
 * Submitted at: 2024-06-13 20:04:43
 * Problem URL: https://atcoder.jp/contests/past17-open/tasks/past17_k
 * Result: AC
 * Execution Time: 2 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; string s; cin >> n >> s;
    vector possible(9, vector<ll>(10, -1));
    rep(i, 9) rep(j, 10) possible[i][(i+1)*j%10] = j;

    vector<ll> hatena(9, -1);
    ll sum = 0;
    rep(i, 9) {
        ll add = 0;
        for(ll j=i; j<n; j+=10) {
            if(s[j] == '?') {
                if(hatena[i] == -1) hatena[i] = j;
                else s[j] = '0';
            }
            else add += s[j]-'0';
        }
        sum += ((i+1)*add) % 10;
        sum %= 10;
    }
    sum = (10-sum) % 10;
    
    // 5 以外の奇数桁目に？がある場合 ⇒ OK
    // 5 と偶数桁目に？がある場合 ⇒ OK
    // 偶数桁目のみに？がある場合 ⇒ sum が偶数なら OK
    // 5 のみに？がある場合 ⇒ sum が 5 の倍数なら OK
    // 何も無し ⇒ sum が 0 なら OK

    ll odd = -1;
    for(ll i=0; i<10; i+=2) if(hatena[i] != -1 && i != 5-1) odd = i;
    if(odd != -1) {
        cout << "Yes" << endl;
        s[hatena[odd]] = possible[odd][sum] + '0';
        rep(i, n) if(s[i] == '?') s[i] = '0';
        cout << s << endl;
        return 0;
    }

    ll five = (hatena[5-1] != -1 ? 5-1 : -1);
    ll even = -1;
    for(ll i=1; i<9; i+=2) if(hatena[i] != -1) even = i;

    if(five != -1 && even != -1) {
        cout << "Yes" << endl;
        s[hatena[five]] = possible[five][(sum%2 == 0 ? 0 : 5)] + '0';
        if(sum%2 == 1) sum = (sum+5) % 10;
        s[hatena[even]] = possible[even][sum] + '0';
        rep(i, n) if(s[i] == '?') s[i] = '0';
        cout << s << endl;
        return 0;
    }

    if(even != -1 && sum%2 == 0) {
        cout << "Yes" << endl;
        s[hatena[even]] = possible[even][sum] + '0';
        rep(i, n) if(s[i] == '?') s[i] = '0';
        cout << s << endl;
        return 0;
    }

    if(five != -1 && sum%5 == 0) {
        cout << "Yes" << endl;
        s[hatena[five]] = possible[five][sum] + '0';
        rep(i, n) if(s[i] == '?') s[i] = '0';
        cout << s << endl;
        return 0;
    }

    if(sum == 0) {
        cout << "Yes" << endl;
        rep(i, n) if(s[i] == '?') s[i] = '0';
        cout << s << endl;
        return 0;
    }

    cout << "No" << endl;
    return 0;
}