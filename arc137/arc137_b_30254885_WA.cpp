/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc137/submissions/30254885
 * Submitted at: 2022-03-20 10:50:23
 * Problem URL: https://atcoder.jp/contests/arc137/tasks/arc137_b
 * Result: WA
 * Execution Time: 48 ms
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
    vector<int> a(n),s(1,0);
    rep(i,n)cin >> a[i];
    int tmp = 0,ans = 0;
    rep(i,n){
        if(tmp == 0)tmp += (a[i] == 0 ? -1 : 1);
        else if(tmp < 0){
            if(a[i] == 0)tmp--;
            else{
                s.push_back(tmp);
                tmp = 1;
            }
        }
        else{
            if(a[i] == 1)tmp++;
            else{
                s.push_back(tmp);
                tmp = -1;
            }
        }
    }
    s.push_back(tmp);
    s.push_back(0);

    rep(i,s.size()-1){
        ans = max(ans,abs(s[i+1]-s[i])+1);
    }
 
    cout << ans << endl;
    return 0;
}