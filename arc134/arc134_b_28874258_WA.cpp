/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc134/submissions/28874258
 * Submitted at: 2022-01-29 22:36:35
 * Problem URL: https://atcoder.jp/contests/arc134/tasks/arc134_b
 * Result: WA
 * Execution Time: 29 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<char,int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n; string s; cin >> n >> s;
    bool frag = true;
    priority_queue<P,vector<P>,greater<P>> vary;
    P tmp;  char tmp2;
    rep(i,s.size()) vary.push(P(s[i],s.size()-i));
    int left = 0,right = n-1;
    tmp = vary.top(); vary.pop();
    tmp2 = tmp.first;
    // cout << tmp.first << endl;
    while(right > left){
        // cout << s[right] << " " << s;
        if(s[right] == tmp.first){
            swap(s[left],s[right]);
            do{left++;}while(s[left] == tmp2);
            do{
                tmp = vary.top(); vary.pop();
                if(s.size()-tmp.second <= left)break;
                frag = false;
                // cout << " Yeah!";
            }while(!vary.empty() && frag);
        }
        // cout << " " << tmp.first << " " << tmp.second << " " << left << endl;
        frag = false;
        right--;
    }
    cout << s << endl;
    return 0;
}