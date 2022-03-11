/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc200/submissions/30002831
 * Submitted at: 2022-03-11 17:25:44
 * Problem URL: https://atcoder.jp/contests/abc200/tasks/abc200_d
 * Result: AC
 * Execution Time: 4 ms
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
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    vector<vector<vector<int>>> ans(200);
    if(n < 9){
        for(int i=1;i<(1 << n);i++){
            vector<int> tmp;
            ll cnt = 0;
            rep(j,n){
                if(i & (1 << j)){
                    tmp.push_back(j+1);
                    cnt += a[j];
                    cnt %= 200;
                }
            }
            ans[cnt].push_back(tmp);
            if(ans[cnt].size() >= 2){
                cout << "Yes" << '\n';
                for(auto k:ans[cnt]){
                    cout << k.size() << " ";
                    for(auto l:k){
                        cout << l << " ";
                    }
                    cout << '\n';
                }
                return 0;
            }
        }
        cout << "No" << '\n';
    }
    else{
        for(int i=1;i<(1 << 9);i++){
            vector<int> tmp;
            ll cnt = 0;
            rep(j,9){
                if(i & (1 << j)){
                    tmp.push_back(j+1);
                    cnt += a[j];
                    cnt %= 200;
                }
            }
            ans[cnt].push_back(tmp);
            if(ans[cnt].size() >= 2){
                cout << "Yes" << '\n';
                for(auto k:ans[cnt]){
                    cout << k.size() << " ";
                    for(auto l:k){
                        cout << l << " ";
                    }
                    cout << '\n';
                }
                return 0;
            }
        }
        cout << "No" << '\n';
    }
    return 0;
}