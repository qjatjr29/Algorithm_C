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
	// 가장 빨리 시작하는 강의가 끝나는 시간 추가
	pq.push(-classRoom[0].second);
	for (int i = 1; i < classRoom.size(); i++)
	{
		// 돌면서 각 강의의 시작시간이 pq(끝나는시간들) 보다 작으면
		// 강의실 하나 더 필요 하다 => 그냥 while문 나가고 추가

		// 시작시간이 끝나는 시간보다 크면
		// 강의실 필요 없다 => 삭제하고 추가
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


