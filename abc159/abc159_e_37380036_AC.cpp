/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc159/submissions/37380036
 * Submitted at: 2022-12-18 22:11:54
 * Problem URL: https://atcoder.jp/contests/abc159/tasks/abc159_e
 * Result: AC
 * Execution Time: 8 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
template<class T, class... Ts> void print(const T& a, const Ts&... b){cout << a;(cout << ... << (cout << ' ', b));cout << '\n';}
template<class... T> void input(T&... a){(cin >> ... >> a);}
void print(){cout << '\n';}
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int h,w,k; input(h,w,k);
    vector<string> choco(h);
    rep(i,h)input(choco[i]);
    vector<vector<int>> rui(h+1,vector<int>(w+1,0));
    rep(i,h){
        rep(j,w){
            if(choco[i][j] == '1')rui[i+1][j+1]++;
            rui[i+1][j+1] += rui[i+1][j]; 
            rui[i+1][j+1] += rui[i][j+1]; 
            rui[i+1][j+1] -= rui[i][j]; 
        }
    }

    int ans = INT_MAX;
    // 縦はbit全探索 横は貪欲
    for(int i=0;i<(1 << h-1);i++){
        // cut位置
        vector<int> cut;
        rep(j,h)if(i & (1 << j))cut.push_back(j+1);
        cut.push_back(h);

        // cnt  : 今の区間内のwhite
        // time : 縦cut回数
        int cnt = 0,time = 0,pre_x = 0,pre_y = 0,tmp;
        while(true){
            int left = pre_y+1,right = w+1;
            while(right-left > 1){
                int mid = (right+left)/2;
                // 各範囲内のwhiteが題意を満たすかで二分探索
                tmp = 0;
                pre_x = 0;
                for(auto c:cut){
                   tmp = max(tmp,rui[c][mid] - rui[c][pre_y] - rui[pre_x][mid] + rui[pre_x][pre_y]);
                   pre_x = c;
                }
                if(tmp <= k)left = mid;
                else right = mid;
            }
            if(left == pre_y+1){
                int tmp = 0;
                pre_x = 0;
                for(auto c:cut){
                   tmp = max(tmp,rui[c][left] - rui[c][left-1] - rui[pre_x][left] + rui[pre_x][left-1]);
                   pre_x = c;
                }
                if(tmp > k){
                    cnt = 1e8;
                    // print("tmp : ",tmp);
                    break;
                }
            }
            // print(left);
            pre_y = left;
            if(pre_y == w)break;
            cnt++;
        }
        ans = min(ans,cnt + (int)cut.size()-1);
        // print(cnt,(int)cut.size()-1);
        // print();
    }
    print(ans);
    
    return 0;
}