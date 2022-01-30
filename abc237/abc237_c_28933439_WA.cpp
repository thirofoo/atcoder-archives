/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc237/submissions/28933439
 * Submitted at: 2022-01-30 21:43:22
 * Problem URL: https://atcoder.jp/contests/abc237/tasks/abc237_c
 * Result: WA
 * Execution Time: 32 ms
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
    int tmp = 0; bool frag = true;
    while(s[s.size()-1] == 'a'){
        s.erase(s.size()-1,1); tmp++;
    }
    if(tmp+1 <= s.size()){
        rep(i,tmp+1){
            if(s[i] == 'a')continue;
            frag = false;
            break;
        }
    }
    if(frag)return cout << "No" << endl,0;
    int left = 0,right = s.size()-1;
    while(right > left){
        if(s[left] != s[right])return cout << "No" << endl,0;
        left++; right--;
    }
    cout << "Yes" << endl;
    return 0;
}