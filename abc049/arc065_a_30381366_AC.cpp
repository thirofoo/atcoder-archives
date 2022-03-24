/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc049/submissions/30381366
 * Submitted at: 2022-03-24 16:49:34
 * Problem URL: https://atcoder.jp/contests/abc049/tasks/arc065_a
 * Result: AC
 * Execution Time: 11 ms
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
    string s; cin >> s;

    string tmp = "";
    while(!s.empty()){
        tmp = s.back() + tmp; s.pop_back();
        if(tmp.size() == 5){
            if(tmp == "erase" || tmp == "dream")tmp = "";
        }
        else if(tmp.size() == 6){
            if(tmp == "eraser")tmp = "";
        }
        else if(tmp.size() == 7){
            if(tmp == "dreamer")tmp = "";
            else return cout << "NO" << endl,0;
        }
    }
    cout << (tmp == "" ? "YES" : "NO") << endl;
    return 0;
}