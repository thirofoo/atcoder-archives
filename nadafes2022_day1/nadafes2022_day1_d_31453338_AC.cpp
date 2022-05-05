/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/nadafes2022_day1/submissions/31453338
 * Submitted at: 2022-05-05 20:10:55
 * Problem URL: https://atcoder.jp/contests/nadafes2022_day1/tasks/nadafes2022_day1_d
 * Result: AC
 * Execution Time: 27 ms
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
    if(n == 1)cout << 0 << endl;
    else if(n%2)cout << -1 << endl;
    else{
        int cnt = 0;
        deque<int> ans;
        vector<int> a;
        rep(i,n)ans.push_back(i);
        while(!ans.empty()){
            int tmp = (cnt%2 == 0 ? ans.front() : ans.back());
            a.push_back(tmp);
            if(cnt%2 == 0)ans.pop_front();
            else ans.pop_back();
            cnt++;
        }
        cout << 0 << " ";
        rep(i,n-1)cout << (a[i+1]-a[i]+n)%n << " ";
        cout << endl; 
    }
    return 0;
}