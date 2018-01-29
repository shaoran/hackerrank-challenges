#include <stdio.h>

int main(void)
{
	int i,n;

	scanf("%d", &n);

	for(i = 0; i < n; ++i)
	{
		int px,py,qx,qy,rx,ry;
		scanf("%d %d", &px, &py);
		scanf("%d %d", &qx, &qy);

		rx = qx + (qx - px);
		ry = qy + (qy - py);
		printf("%d %d\n", rx, ry);
	}

	return 0;
}
