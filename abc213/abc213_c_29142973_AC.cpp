/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc213/submissions/29142973
 * Submitted at: 2022-02-07 16:54:18
 * Problem URL: https://atcoder.jp/contests/abc213/tasks/abc213_c
 * Result: AC
 * Execution Time: 243 ms
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
    int h,w,n; cin >> h >> w >> n;
    vector<int> height,width,s,t;
    rep(i,n){
        int a,b; cin >> a >> b;
        height.push_back(a);
        width.push_back(b);
    }
    s = height;
    t = width;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    for(int i=n-1;i>=0;i--)if(s[i] == s[i-1])s.erase(s.begin()+i);
    for(int i=n-1;i>=0;i--)if(t[i] == t[i-1])t.erase(t.begin()+i);
    rep(i,n)height[i] = lower_bound(s.begin(),s.end(),height[i])-s.begin()+1;
    rep(i,n)width[i] = lower_bound(t.begin(),t.end(),width[i])-t.begin()+1;
    rep(i,n)cout << height[i] << " " << width[i] << endl;
    return 0;
}