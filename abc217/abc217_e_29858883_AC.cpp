/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc217/submissions/29858883
 * Submitted at: 2022-03-05 17:45:13
 * Problem URL: https://atcoder.jp/contests/abc217/tasks/abc217_e
 * Result: AC
 * Execution Time: 220 ms
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
    int q; cin >> q;
    queue<int> now;
    priority_queue<int,vector<int>,greater<int>> after_sort;
    rep(i,q){
        int t; cin >> t;
        if(t == 1){
            int x; cin >> x;
            now.push(x);
        }
        else if(t == 2){
            if(!after_sort.empty()){
                cout << after_sort.top() << '\n';
                after_sort.pop();
            }
            else{
                cout << now.front() << '\n';
                now.pop();
            }
        }
        else{
            while(!now.empty()){
                int tmp = now.front(); now.pop();
                after_sort.push(tmp);
            }
        }
    }
    return 0;
}