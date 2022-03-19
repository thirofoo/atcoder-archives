/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc134/submissions/30224684
 * Submitted at: 2022-03-19 18:19:42
 * Problem URL: https://atcoder.jp/contests/arc134/tasks/arc134_b
 * Result: WA
 * Execution Time: 30 ms
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
    int l = 0,r = n-1;
    priority_queue<char,vector<char>,greater<char>> todo;
    map<char,int> num;
    rep(i,n){
        todo.push(s[i]);
        num[s[i]]++;
    }

    while(l < r){
        char tmp = todo.top();
        //過ぎ去っている場合を排除
        if(num[tmp] == 0){
            todo.pop();
            continue;
        }

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
        num[s[r]]--;
        r--;
    }
    cout << s << endl;
    return 0;
}