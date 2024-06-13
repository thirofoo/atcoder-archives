/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/past17-open/submissions/54508656
 * Submitted at: 2024-06-13 23:49:31
 * Problem URL: https://atcoder.jp/contests/past17-open/tasks/past17_k
 * Result: AC
 * Execution Time: 2 ms
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    char s[200001];
    scanf("%d %s", &n, s);

    int possible[9][10];
    memset(possible, -1, sizeof(possible));
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 10; j++) {
            possible[i][(i+1)*j % 10] = j;
        }
    }

    int hatena[9];
    memset(hatena, -1, sizeof(hatena));
    int sum = 0, add = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '?') {
            if(hatena[i % 10] == -1) hatena[i % 10] = i;
            s[i] = '0';
        }
        else sum += (s[i] - '0') * (i % 10 + 1);
    }
    sum %= 10;
    sum = (10 - sum) % 10;

    int odd = -1;
    for(int i = 0; i < 10; i += 2) {
        if(hatena[i] != -1 && i != 4) odd = i;
    }
    if(odd != -1) {
        s[hatena[odd]] = possible[odd][sum] + '0';
        return printf("Yes\n%s\n", s), 0;
    }

    int five = (hatena[4] != -1 ? 4 : -1);
    int even = -1;
    for(int i = 1; i < 9; i += 2) {
        if(hatena[i] != -1) even = i;
    }

    if(five != -1 && even != -1) {
        s[hatena[five]] = possible[five][(sum % 2 == 0 ? 0 : 5)] + '0';
        if(sum % 2 == 1) sum = (sum + 5) % 10;
        s[hatena[even]] = possible[even][sum] + '0';
        return printf("Yes\n%s\n", s), 0;
    }

    if(even != -1 && sum % 2 == 0) {
        s[hatena[even]] = possible[even][sum] + '0';
        return printf("Yes\n%s\n", s), 0;
    }

    if(five != -1 && sum % 5 == 0) {
        s[hatena[five]] = possible[five][sum] + '0';
        return printf("Yes\n%s\n", s), 0;
    }

    if(sum == 0) return printf("Yes\n%s\n", s), 0;

    printf("No\n");
    return 0;
}
