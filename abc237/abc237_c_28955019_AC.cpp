/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc237/submissions/28955019
 * Submitted at: 2022-01-30 22:39:44
 * Problem URL: https://atcoder.jp/contests/abc237/tasks/abc237_c
 * Result: AC
 * Execution Time: 29 ms
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
    string s,tmp; cin >> s;
    int a1 = 0,a2 = 0;
    while(s[s.size()-1] == 'a'){
        s.erase(s.size()-1,1); a1++;
    }
    while(s[a2] == 'a')a2++;
    if(a2 > a1)return cout << "No" << endl,0;
    else{
        rep(i,a2)s += "a";
    }
    int left = 0,right = s.size()-1;
    while(right > left){
        if(s[left] != s[right])return cout << "No" << endl,0;
        left++; right--;
    }
    cout << "Yes" << endl;
    return 0;
}