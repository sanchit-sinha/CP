#include <stdio.h>

#define N	2000
#define L	4000000

int main() {
	int t;

	scanf("%d", &t);
	while (t--) {
		static char cc[N + 1], cc_[L + 1];
		static int bb[N], dd[N];
		int n, k, h, i, j, cnt, l;
		long long x;

		scanf("%d%d%lld%s", &n, &k, &x, cc), x--;
		cnt = 0;
		for (i = -1, j = 0; j <= n; j++)
			if (j == n || cc[j] == 'a')
				bb[cnt++] = (j - i - 1) * k + 1, i = j;
		for (h = cnt - 1; h >= 0; h--)
			dd[h] = x % bb[h], x /= bb[h];
		l = 0;
		for (h = 0; h < cnt; h++) {
			while (dd[h]--)
				cc_[l++] = 'b';
			if (h + 1 < cnt)
				cc_[l++] = 'a';
		}
		cc_[l] = 0;
		printf("%s\n", cc_);
	}
	return 0;
}
