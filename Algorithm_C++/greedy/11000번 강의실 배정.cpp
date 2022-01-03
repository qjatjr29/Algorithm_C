#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;
vector<pair<int, int>> classRoom;
priority_queue<int> pq;
int result = 1;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int start, end;
		cin >> start >> end;
		classRoom.push_back(make_pair(start, end));
	}
	sort(classRoom.begin(), classRoom.end());
	// ���� ���� �����ϴ� ���ǰ� ������ �ð� �߰�
	pq.push(-classRoom[0].second);
	for (int i = 1; i < classRoom.size(); i++)
	{
		// ���鼭 �� ������ ���۽ð��� pq(�����½ð���) ���� ������
		// ���ǽ� �ϳ� �� �ʿ� �ϴ� => �׳� while�� ������ �߰�

		// ���۽ð��� ������ �ð����� ũ��
		// ���ǽ� �ʿ� ���� => �����ϰ� �߰�
		while (1)
		{
			if (pq.empty())break;
			if (-pq.top() > classRoom[i].first) break;
			pq.pop();
		}
		pq.push(-classRoom[i].second);
		result = max(result, int(pq.size()));
	}
	cout << result << "\n";
	return 0;
}


