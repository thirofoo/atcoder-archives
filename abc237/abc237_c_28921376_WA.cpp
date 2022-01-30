/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc237/submissions/28921376
 * Submitted at: 2022-01-30 21:23:52
 * Problem URL: https://atcoder.jp/contests/abc237/tasks/abc237_c
 * Result: WA
 * Execution Time: 28 ms
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
    string s; cin >> s;
    while(s[s.size()-1] == 'a'){
        s.erase(s.size()-1,1);
    }
    int left = 0,right = s.size()-1;
    while(right > left){
        if(s[left] != s[right])return cout << "No" << endl,0;
        left++; right--;
    }
    cout << "Yes" << endl;
    return 0;
}