/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc207/submissions/29821636
 * Submitted at: 2022-03-03 16:06:12
 * Problem URL: https://atcoder.jp/contests/abc207/tasks/abc207_c
 * Result: AC
 * Execution Time: 20 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<double, double> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n; cin >> n;
    vector<P> section;
    rep(i,n){
        double t,l,r; cin >> t >> l >> r;
        if(t == 1)section.push_back(P(l,r));
        else if(t == 2)section.push_back(P(l,r-0.5));
        else if(t == 3)section.push_back(P(l+0.5,r));
        else section.push_back(P(l+0.5,r-0.5));
    }
    int ans = 0;
    rep(i,n){
        for(int j=i+1;j<n;j++){
            if(section[i].second <= section[j].second){
                if(section[i].second >= section[j].first)ans++;
                // cout << section[i].first << " " << section[i].second << " " << section[j].first << " " << section[j].second << '\n';
            }
            else{
                if(section[j].second >= section[i].first)ans++;
                // cout << section[i].first << " " << section[i].second << " " << section[j].first << " " << section[j].second << '\n';
            }
        }
    }
    cout << ans << '\n';
    return 0;
}