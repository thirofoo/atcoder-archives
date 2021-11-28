/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc032/submissions/27581191
 * Submitted at: 2021-11-29 01:49:18
 * Problem URL: https://atcoder.jp/contests/abc032/tasks/abc032_c
 * Result: CE
 * Execution Time: None ms
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
int N,K;int length = 0;int right = 0;int scale = 0;long long multi = 1;cin >> N >> K;vector<int> Q(N);
for(ll i = 0; i < N; ++i){cin >> Q[i];if(Q[i] == 0)return cout << N << endl,0;}
for(int left=0;left<N;left++){
for(right;right < N;right++){
if(multi*Q[right] <= K ){
multi*=Q[right];
scale++;
continue;
}
break;
}
length = max(length,scale);
scale--;
if(multi % Q[left] == 0)multi/=Q[left];
}
cout << length << endl;
return 0;
}