/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc150/submissions/28236616
 * Submitted at: 2021-12-30 18:48:27
 * Problem URL: https://atcoder.jp/contests/abc150/tasks/abc150_c
 * Result: AC
 * Execution Time: 10 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
  #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,count = 1,p_place,q_place; cin >> n;
    vector<int> p(n),q(n);
    rep(i,n)cin >> p[i];
    rep(i,n)cin >> q[i];
    vector<int> ex(n);
    iota(ex.begin(),ex.end(),1);
    do{
        bool frag_p = true,frag_q = true;
        rep(i,n){
            if(p[i] != ex[i])frag_p = false;
            if(q[i] != ex[i])frag_q = false;
        }
        if(frag_p)p_place = count;
        if(frag_q)q_place = count;
        count++;
    }while(next_permutation(ex.begin(),ex.end()));
    cout << abs(p_place-q_place) << endl;
    return 0;
}