#include <cstdio>
#include <map>
#include <iostream>

using namespace std;

map<string, int> g;
int main() {
	int n;
	char str[100];
	while (scanf("%d", &n) != EOF)
	{
		g.clear();
		int ans = 0;
		char clor[100];
		for (int i = 0; i < n; i++)
		{
			scanf("%s", str);
			g[str] = g[str] + 1;
			if (g[str] > ans)
			{
				ans = g[str];
				strcpy(clor, str);
			}
		}
		//printf("%d\n",ans);
		printf("%s\n", clor);
	}
	return 0;
}