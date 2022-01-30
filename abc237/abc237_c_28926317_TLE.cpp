/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc237/submissions/28926317
 * Submitted at: 2022-01-30 21:30:54
 * Problem URL: https://atcoder.jp/contests/abc237/tasks/abc237_c
 * Result: TLE
 * Execution Time: 2205 ms
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
        if(s[0] == 'a')s.erase(0,1);
    }
    if(s[0] == 'a')return cout << "No" << endl,0;
    int left = 0,right = s.size()-1;
    while(right > left){
        if(s[left] != s[right])return cout << "No" << endl,0;
        left++; right--;
    }
    cout << "Yes" << endl;
    return 0;
}