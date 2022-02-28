/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc136/submissions/29771333
 * Submitted at: 2022-02-28 18:29:01
 * Problem URL: https://atcoder.jp/contests/arc136/tasks/arc136_b
 * Result: AC
 * Execution Time: 10 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n; cin >> n;
    vector<int> a(n),b(n),a_cnt(5005,0),b_cnt(5005,0);
    bool frag = false;
    rep(i,n){
        cin >> a[i];
        if(a_cnt[a[i]])frag = true;
        a_cnt[a[i]]++;
    }
    rep(i,n){
        cin >> b[i];
        if(b_cnt[b[i]])frag = true;
        b_cnt[b[i]]++;
    }
    if(a_cnt != b_cnt)return cout << "No" << endl,0;
    if(frag)return cout << "Yes" << endl,0;
    fenwick_tree<int> a_BIT(5005),b_BIT(5005);
    int a_tento = 0,b_tento = 0;
    rep(i,n){
        a_tento += i-a_BIT.sum(1,a[i]);
        a_BIT.add(a[i],1);
        b_tento += i-b_BIT.sum(1,b[i]);
        b_BIT.add(b[i],1);
    }
    if(a_tento%2 == b_tento%2)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}