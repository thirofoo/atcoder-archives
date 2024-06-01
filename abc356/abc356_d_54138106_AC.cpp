/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc356/submissions/54138106
 * Submitted at: 2024-06-02 00:16:18
 * Problem URL: https://atcoder.jp/contests/abc356/tasks/abc356_d
 * Result: AC
 * Execution Time: 1 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
    using namespace atcoder;
#endif
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); ++i)

int main() {
    ll n, m; cin >> n >> m;
    ll nn = n, mm = m;
    // mを10進数から2進数になおす
    string s2;
    while(m > 0){
        s2 += to_string(m % 2);
        m /= 2;
    }
    // s2[i]=='1'のとき、0からnnまでの数の中で、2進数で考えたときのi桁目が1であるものの個数を数える
    ll num = 2;
    unsigned long long cnt = 0;
    rep(i, s2.size()){
        if(s2[i] == '1'){
            // cnt+=(nn+1)/num*(num/2);
            // cnt%=998244353;
            // if(((nn+1)/2)%2!=0) cnt+=(nn+1)%num;
            // //cntはmod998244353になるように
            // cnt%=998244353;
            cnt += n / num * (num / 2);
            cnt += max(0LL, n % num - num / 2 + 1);
            cnt %= 998244353;
        }
        num *= 2;
    }
    cout << cnt << endl;
}