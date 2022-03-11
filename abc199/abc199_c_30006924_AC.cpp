/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc199/submissions/30006924
 * Submitted at: 2022-03-11 21:35:50
 * Problem URL: https://atcoder.jp/contests/abc199/tasks/abc199_c
 * Result: AC
 * Execution Time: 173 ms
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
    int n,q; cin >> n;
    string a = "",b = "";
    rep(i,n){
        char tmp; cin >> tmp;
        a += tmp;
    }
    rep(i,n){
        char tmp; cin >> tmp;
        b += tmp;
    }
    cin >> q;

    int cnt = 0;
    rep(i,q){
        int t,x,y; cin >> t >> x >> y;
        x--; y--;
        if(t == 1){
            if(cnt%2 == 0){
                if(x <= n-1 && n-1 < y)swap(a[x],b[y-n]);
                else if(y <= n-1)swap(a[x],a[y]);
                else swap(b[x-n],b[y-n]);
            }
            else{
                if(x <= n-1 && n-1 < y)swap(b[x],a[y-n]);
                else if(y <= n-1)swap(b[x],b[y]);
                else swap(a[x-n],a[y-n]);
            }
        }
        else cnt++;
    }
    cout << (cnt%2 == 0 ? a+b : b+a) << endl;
    return 0;
}