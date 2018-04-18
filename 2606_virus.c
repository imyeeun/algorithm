#include <stdio.h>

int n; // ��ǻ�� ����
int map[101][101], visit[101]; // 100 �ƴϰ� 101�̴�. �������� 
static int count = 0;
void DFS(int v) {
	int i;
	visit[v] = 1; // �湮 ǥ��
				  //static int count = 0;
	for (i = 1; i <= n; i++) {
		if (map[v][i] == 1 && !visit[i]) {  // �� ��ǻ�Ͱ� ����Ǿ��ְ� �湮���� ���� ��ǻ�Ͷ��
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
