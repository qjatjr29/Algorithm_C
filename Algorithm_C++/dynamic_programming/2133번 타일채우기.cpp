#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N;
vector<int> Tile;
int main()
{
	cin >> N;
	Tile = vector<int>(N + 1, 0);
	Tile[2] = 3;

	//¦���ϋ��� ����
	// 4�̻� �϶� ���� ��ȭ��
	for (int i = 4; i < N + 1; i += 2)
	{
		// ���� ���̽� * 3 
		Tile[i] = Tile[i - 2] * 3;
		// �̻��ϰ� ���� ��� 4ĭ �̻� ���� ����
		// 4ĭ �̻��̸� �̻��ϰ� ���� ����� ������ 2��
		// 4ĭ ���� �� ���� ĭ���� ����� �ִ� ��� �� * 2 ���ָ� �ɵ�.
		for (int j = 2; j <= i - 4; j += 2)
		{
			Tile[i] += Tile[j] * 2;
		}
		// i�� 4�̻��̴ϱ� �ڱ⵵ �̻��� ��� �ϳ� ����.
		Tile[i] += 2;
	}

	cout << Tile[N] << "\n";
	return 0;
}