/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc134/submissions/30224423
 * Submitted at: 2022-03-19 18:07:04
 * Problem URL: https://atcoder.jp/contests/arc134/tasks/arc134_b
 * Result: WA
 * Execution Time: 28 ms
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
    int n; string s; cin >> n >> s;
    int size = s.size(),l = 0, r = size-1;
    priority_queue<char,vector<char>,greater<char>> todo;
    rep(i,size)todo.push(s[i]);

    while(l < r){
        char tmp = todo.top();
        if(s[l] == tmp){
            todo.pop(); l++;
            continue;
        }
        if(s[r] == tmp){
            todo.pop();
            swap(s[l],s[r]);
            l++; r--;
            continue;
        }
        r--;
    }
    cout << s << endl;
    return 0;
}