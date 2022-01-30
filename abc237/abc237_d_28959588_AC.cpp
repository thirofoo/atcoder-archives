/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc237/submissions/28959588
 * Submitted at: 2022-01-30 23:33:16
 * Problem URL: https://atcoder.jp/contests/abc237/tasks/abc237_d
 * Result: AC
 * Execution Time: 63 ms
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
    int n; string s; cin >> n >> s;
    deque<int> ans; ans.push_front(n);
    for(int i=n-1;i>=0;i--){
        if(s[i] == 'L'){
            ans.push_back(i);
        }
        else{
            ans.push_front(i);
        }
    }
    while(!ans.empty()){
        int a = ans.front(); ans.pop_front();
        cout << a << " ";
    }
    cout << endl;
    return 0;
}