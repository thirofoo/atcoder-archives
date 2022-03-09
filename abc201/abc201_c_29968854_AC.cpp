/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc201/submissions/29968854
 * Submitted at: 2022-03-09 16:45:40
 * Problem URL: https://atcoder.jp/contests/abc201/tasks/abc201_c
 * Result: AC
 * Execution Time: 6 ms
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
    string s; cin >> s;
    int a = 0,b = 0,c = 0;
    set<int> v;
    rep(i,10){
        if(s[i] == 'o'){
            a++;
            v.insert(i);
        }
        else if(s[i] == 'x')b++;
        else c++;
    }
    if(a >= 5)return cout << 0 << endl,0;
    int ans = 0;
    rep(i,10){
        if(s[i] == 'x')continue;
        rep(j,10){
            if(s[j] == 'x')continue;
            rep(k,10){
                if(s[k] == 'x')continue;
                rep(l,10){
                    if(s[l] == 'x')continue;
                    set<int> w;
                    if(s[i] == 'o')w.insert(i);
                    if(s[j] == 'o')w.insert(j);
                    if(s[k] == 'o')w.insert(k);
                    if(s[l] == 'o')w.insert(l);
                    if(v == w)ans++;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}