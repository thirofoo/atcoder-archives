/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/past17-open/submissions/54509221
 * Submitted at: 2024-06-14 00:16:12
 * Problem URL: https://atcoder.jp/contests/past17-open/tasks/past17_e
 * Result: AC
 * Execution Time: 11 ms
 */

#pragma GCC target("arch=skylake-avx512")
#pragma GCC optimize("O3")
#include <stdio.h>
#include <string.h>

int main() {
    char s[200001];
    scanf("%s", s);

    char pre = s[0];
    int cnt = 1;
    int n = strlen(s);

    for (int i = 1; i < n; i++) {
        if (pre == s[i]) {
            cnt++;
        } else {
            printf("%c %d ", pre, cnt);
            pre = s[i];
            cnt = 1;
        }
    }
    printf("%c %d\n", pre, cnt);
}
