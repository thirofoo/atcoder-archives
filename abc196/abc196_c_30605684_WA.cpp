/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc196/submissions/30605684
 * Submitted at: 2022-04-01 18:41:22
 * Problem URL: https://atcoder.jp/contests/abc196/tasks/abc196_c
 * Result: WA
 * Execution Time: 9 ms
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
    ll n; cin >> n;
    ll digit = 0,tmp = n;
    while(tmp){
        tmp /= 10;
        digit++;
    }
    if(digit%2){
        tmp = (digit-1)/2 - 1;
        cout << 9+10*tmp << endl;
    }
    else{
        int a = 0,b = 0;
        string s = to_string(n);
        for(int i=0;i<digit/2;i++)a *= 10,a += s[i]-'0';
        for(int i=digit/2;i<digit;i++)b *= 10,b += s[i]-'0';
        int c = min(a,b);
        cout << (c == 0 ? pow(10,digit/2-1)-1 : c) << endl;
    }

    return 0;
}