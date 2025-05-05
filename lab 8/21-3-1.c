#include <stdio.h>
#include <limits.h>
void solve() {
    int n;
    scanf("%d", &n);

    int sum = 0, minBlocks = INT_MAX, num;

    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        sum += num;
        if (num < minBlocks) {
            minBlocks = num;
        }
    }

    printf("%d\n", sum - minBlocks);
}
int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}
