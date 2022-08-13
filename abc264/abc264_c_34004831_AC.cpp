/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc264/submissions/34004831
 * Submitted at: 2022-08-13 21:37:41
 * Problem URL: https://atcoder.jp/contests/abc264/tasks/abc264_c
 * Result: AC
 * Execution Time: 25 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll h1,w1,h2,w2; cin >> h1 >> w1;
    vector<vector<int>> a(h1,vector<int>(w1));
    rep(i,h1)rep(j,w1)cin >> a[i][j];
    cin >> h2 >> w2;
    vector<vector<int>> b(h2,vector<int>(w2));
    rep(i,h2)rep(j,w2)cin >> b[i][j];

    if(h1 >= h2 && w1 >= w2){
        rep(i,1LL << (h1+1)-1){
            //行数があってるか
            int c1 = 0;
            rep(j,h1)if(i & (1LL << j))c1++;
            if(c1 != h2)continue;

            rep(j,1LL << (w1+1)-1){
                //列数があってるか
                int c2 = 0;
                rep(k,w1)if(j & (1LL << k))c2++;
                if(c2 != w2)continue;

                bool f = true;
                int th = 0,tw = 0;
                rep(k,h1){
                    if( !(i & (1LL << k)) )continue;
                    rep(l,w1){
                        if( !(j & (1LL << l)) )continue;

                        if(a[k][l] != b[th][tw]){
                            f = false;
                            break;
                        }

                        tw++;
                    }
                    if(!f)break;
                    th++;
                    tw = 0;
                }
                if(f)return cout << "Yes" << endl,0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}