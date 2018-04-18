#include <stdio.h>

int n; // 컴퓨터 개수
int map[101][101], visit[101]; // 100 아니고 101이다. 조심하자 
static int count = 0;
void DFS(int v) {
	int i;
	visit[v] = 1; // 방문 표시
				  //static int count = 0;
	for (i = 1; i <= n; i++) {
		if (map[v][i] == 1 && !visit[i]) {  // 두 컴퓨터가 연결되어있고 방문하지 않은 컴퓨터라면
			count++;	
			DFS(i);
		}
	}
}

int main() {
	int start = 1;
	int v1, v2;
	int net;

	scanf("%d", &n);
	scanf("%d", &net);

	for (int i = 0; i < net; i++) {
		scanf("%d %d", &v1, &v2);
		map[v1][v2] = map[v2][v1] = 1;
	}
	DFS(start);
	printf("%d\n", count);
	return 0;
}
