/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc130/submissions/27698520
 * Submitted at: 2021-12-05 02:05:14
 * Problem URL: https://atcoder.jp/contests/arc130/tasks/arc130_a
 * Result: WA
 * Execution Time: 19 ms
 */

#include <bits/stdc++.h>
#include <cmath> //abs関数で絶対値を使える。
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < n; ++i)

int main(){
    int n;
    string s;
    int count = 1;
    ll ans = 0;
    cin >> n >> s;
    for(int i=0;i<n-1;i++){
        if(s[i] == s[i+1]){
            count++;
            if(i==n-2)ans += count*(count-1)/2;
        }
        else{
            ans += count*(count-1)/2;
            count = 1;
        }
    }
    cout << ans << endl;
    return 0;
}