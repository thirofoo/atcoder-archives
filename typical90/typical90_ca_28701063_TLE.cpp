/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28701063
 * Submitted at: 2022-01-23 01:42:23
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_ca
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
    int h,w,count = 0; cin >> h >> w;
    vector<vector<int>> field_a(h,vector<int>(w)),field_b(h,vector<int>(w));
    rep(i,h)rep(j,w)cin >> field_a[i][j];
    rep(i,h)rep(j,w)cin >> field_b[i][j];
    rep(i,h-1){
        rep(j,w-1){
            while(field_a[i][j] != field_b[i][j]){
                if(field_a[i][j] > field_b[i][j]){
                    field_a[i][j]--;
                    field_a[i+1][j]--;
                    field_a[i][j+1]--;
                    field_a[i+1][j+1]--;
                    count++;
                }
                else{
                    field_a[i][j]++;
                    field_a[i+1][j]++;
                    field_a[i][j+1]++;
                    field_a[i+1][j+1]++;
                    count++;
                }
            }
        }
    }
    if(field_a[h-2][w-1] != field_b[h-2][w-1])return cout << "No" << endl,0;
    rep(i,w)if(field_a[h-1][i] != field_b[h-1][i])return cout << "No" << endl,0;
    cout << "Yes" << endl << count << endl;
    return 0;
}