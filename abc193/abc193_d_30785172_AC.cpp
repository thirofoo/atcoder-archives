/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc193/submissions/30785172
 * Submitted at: 2022-04-08 14:10:08
 * Problem URL: https://atcoder.jp/contests/abc193/tasks/abc193_d
 * Result: AC
 * Execution Time: 13 ms
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

ll k;
map<ll,ll> ta,ao,all;
vector<vector<int>> win_takahashi(10,vector<int>(10,0));
void decide_winner(){
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            ta[i]++; ao[j]++;

            if(ta[i]+ao[i] > k || ta[j]+ao[j] > k){
                win_takahashi[i][j] = -1;
            }
            else{
                int t = 0,a = 0;
                for(int k=1;k<=9;k++)t += k*(pow(10,ta[k]));
                for(int k=1;k<=9;k++)a += k*(pow(10,ao[k]));
                if(t > a)win_takahashi[i][j] = 1;
            }

            ta[i]--; ao[j]--;
        }
    }
}

int main() {
    cout << fixed << setprecision(10);
    string s,t; cin >> k >> s >> t;
    rep(i,9)all[i+1] = k;
    rep(i,4){
        ta[s[i]-'0']++,all[s[i]-'0']--;
        ao[t[i]-'0']++,all[t[i]-'0']--;
    }
    decide_winner();

    ll win = 0,total = (9*k-8)*(9*k-9);
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            if(win_takahashi[i][j] != 1)continue;
            win += all[i]*(all[j]+(i == j ? -1 : 0));
        }
    }
    
    cout << (double)win/(double)total << endl;
    return 0;
}