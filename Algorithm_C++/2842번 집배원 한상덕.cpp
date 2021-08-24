#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int N;
int dx[8] = { -1,-1,-1,0,0,1,1,1, };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };
int houseCount;
// �Ƿε�
int fatigue = 987654321;
// ��ü�� (x,y) / ���� �� 
pair<pair<int, int>, int> postOffice;
// p / x / . 
vector<vector<char>> map;
// ���� ����.
vector<vector<int>> elevation;
vector<int> sortElevation;
// ���� ���� , ū ����
int leftHeight, rightHeight;
// �湮 ���� Ȯ��
vector<vector<bool>> visited;
// ��� ���� ��� �������� Ȯ��
bool deliver = false;
// bfs
void deliverToHouse();
// ���� ���� �� �� ã�� 
void hansangduk();
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;
	map = vector<vector<char>>(N + 1, vector<char>(N + 1, ' '));
	elevation = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			map[i][j] = s[j];
			if (s[j] == 'P')
			{
				postOffice.first.first = i;
				postOffice.first.second = j;
			}
			if (s[j] == 'K')
			{
				houseCount++;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int elev;
			cin >> elev;
			elevation[i][j] = elev;
			sortElevation.push_back(elev);
		}
	}
	// ��ü���� ��
	postOffice.second = elevation[postOffice.first.first][postOffice.first.second];

	// �� ���� ���� �� �ߺ� ���� 
	sort(sortElevation.begin(), sortElevation.end());
	sortElevation.erase(unique(sortElevation.begin(), sortElevation.end()), sortElevation.end());

	hansangduk();
	cout << fatigue << "\n";


	return 0;
}

void deliverToHouse()
{
	queue<pair<int, int>> q;
	q.push(make_pair(postOffice.first.first, postOffice.first.second));
	visited[postOffice.first.first][postOffice.first.second] = true;
	int tempCount = 0;

	while (1)
	{
		if (q.empty())break;
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		if (map[curX][curY] == 'K')
		{
			tempCount++;
			if (tempCount == houseCount)
			{
				deliver = true;
				return;
			}
		}
		for (int i = 0; i < 8; i++)
		{
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			// ������ ������ �湮���� ���� ���.
			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N && visited[nextX][nextY] == false)
			{
				// �� ���̵Ǵ��� Ȯ��.
				if (sortElevation[leftHeight] <= elevation[nextX][nextY] &&
					sortElevation[rightHeight] >= elevation[nextX][nextY])
				{
					visited[nextX][nextY] = true;
					q.push(make_pair(nextX, nextY));
				}
			}
		}


	}

}

void hansangduk()
{
	// ���� �� ���� ������ �� ������ ��� ���� ��� �������� üũ
	while (1)
	{
		// ���� �Ѿ�� break;
		if (rightHeight >= sortElevation.size())break;

		// ������� ��� ���� ���� Ȯ��
		while (1)
		{
			bool chk = false;
			// ó�� ���ۺ��� �Ǵ��� Ȯ���ؾ��Ѵ�.
			if (postOffice.second >= sortElevation[leftHeight] &&
				postOffice.second <= sortElevation[rightHeight])
			{
				// bfs ����
				deliver = false;
				visited = vector<vector<bool>>(N + 1, vector<bool>(N + 1, false));
				deliverToHouse();
				if (deliver == true)
				{
					fatigue = min(fatigue, sortElevation[rightHeight] - sortElevation[leftHeight]);
					leftHeight++;
				}
				else break;
			}
			else break;
		}
		// �ȵǸ� rightHeight ++; 
		rightHeight++;
	}
}
