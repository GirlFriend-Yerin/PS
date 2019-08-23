#include "stdio.h"
#include <algorithm>
using namespace std;
#define MAXN 3000
#define max(x, y) ((x)>(y)?(x):(y))
int N, M;
int r[MAXN + 1];
int cnt[MAXN + 1];
struct Line {
	int x1, y1, x2, y2;
} L[MAXN + 1];
int idx = 0;

int getParent(int a) {
	if (r[a] == a) return a;
	return r[a] = getParent(r[a]);
}
void join(int a, int b) {
	r[getParent(a)] = getParent(b);
}
int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int val = (x1*y2 + x2 * y3 + x3 * y1) - (y1*x2 + y2 * x3 + y3 * x1);
	return val > 0 ? 1 : (val < 0 ? -1 : 0);
}
bool isCross(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	if (ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4) <= 0 &&
		ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2) <= 0) {
		if ((x1 > x3 && x1 > x4 && x2 > x3 && x2 > x4) ||
			(x1 < x3 && x1 < x4 && x2 < x3 && x2 < x4)) return false;
		if ((y1 > y3 && y1 > y4 && y2 > y3 && y2 > y4) ||
			(y1 < y3 && y1 < y4 && y2 < y3 && y2 < y4)) return false;
		return true;
	}
	return false;
}
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) r[i] = i;
	for (int i = 1; i <= N; i++) {
		scanf("%d%d%d%d", &L[i].x1, &L[i].y1, &L[i].x2, &L[i].y2);
		for (int j = 1; j < i; j++)
			if (isCross(L[i].x1, L[i].y1, L[i].x2, L[i].y2, L[j].x1, L[j].y1, L[j].x2, L[j].y2))
				join(i, j);
	}
	for (int i = 1; i <= N; i++) cnt[getParent(i)]++;
	int group_count = 0, max_member = 0;
	for (int i = 1; i <= N; i++) {
		if (cnt[i]) group_count++;
		max_member = max(max_member, cnt[i]);
	}
	printf("%d\n%d\n", group_count, max_member);
}