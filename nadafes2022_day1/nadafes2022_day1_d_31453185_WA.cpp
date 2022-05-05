/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/nadafes2022_day1/submissions/31453185
 * Submitted at: 2022-05-05 20:00:06
 * Problem URL: https://atcoder.jp/contests/nadafes2022_day1/tasks/nadafes2022_day1_d
 * Result: WA
 * Execution Time: 25 ms
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
    if(n%2)cout << -1 << endl;
    else{
        int cnt = 0;
        deque<int> ans;
        rep(i,n)ans.push_back(i);
        while(!ans.empty()){
            int tmp = (cnt%2 == 0 ? ans.front() : ans.back());
            cout << tmp << " ";
            if(cnt%2 == 0)ans.pop_front();
            else ans.pop_back();
            cnt++;
        }
        cout << endl;
    }
    return 0;
}