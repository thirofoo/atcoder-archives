/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc038/submissions/27584737
 * Submitted at: 2021-11-29 12:36:53
 * Problem URL: https://atcoder.jp/contests/abc038/tasks/abc038_c
 * Result: TLE
 * Execution Time: 2205 ms
 */

#include <bits/stdc++.h>
#include <cmath> //abs関数で絶対値を使える。
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < n; ++i)

// ABC038 C 「単調増加」　※尺取り法
int main(){
    int N;
    int right = 0;
    int ans = 0;
    int count = 0;
    cin >> N;
    vector<int> a(N);
    rep(i,N)cin >> a[i];
    for(int left=0;left+1<N;left++){
        rep(i,N){
            if(a[left+i]>=a[left+i+1] || left+i+1==N)break;
            count++;
        }
    }
    count += N;
    cout << count << endl;
    return 0;
}