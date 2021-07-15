#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int N;
int result;
vector<vector<int>> map;
vector<pair<int, pair<int, int>>> feed;
vector<vector<bool>> visited;
pair<int, int> babyShark;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int babySize = 2;
int babySizeCount = 0;
// ���� �� �ִ� ������ ��ġ ����
priority_queue<pair<int, pair<int, int>>> canEat;
//vector<pair<int, int>> canEat;

// ���� ������ �ּ� �Ÿ� ���ϱ�
int calcDisFeed(int startX, int startY, int endX, int endY);

// ������ ���� �� �ִ� �� ã��
bool ManyFeed = false;
void CanEatFeed();

// �Դ� �Լ�
void EatFeed();

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;
	map = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int fish;
			cin >> fish;
			map[i][j] = fish;
			if (fish == 9)
			{
				babyShark = make_pair(i, j);
			}
			else if (fish != 0)
			{
				feed.push_back(make_pair(fish, make_pair(i, j)));
			}
		}
	}
	while (1)
	{
		CanEatFeed();
		if (canEat.size() == 1)break;
		else
		{
			EatFeed();
		}
	}
	cout << result << "\n";

	return 0;
}

void CanEatFeed()
{

	while (1)
	{
		if (canEat.empty())break;
		canEat.pop();
	}
	canEat.push(make_pair(-987654321, make_pair(-1, -1)));
	for (int i = 0; i < feed.size(); i++)
	{
		int fishSize = feed[i].first;
		int fishX = feed[i].second.first;
		int fishY = feed[i].second.second;
		// ���� ũ�Ⱑ ���� ������� ���� �� �ִ�.
		if (fishSize < babySize)
		{
			int distance = calcDisFeed(babyShark.first, babyShark.second, fishX, fishY);
			if (-canEat.top().first >= distance && distance != 987654321)
			{
				if (-canEat.top().first == distance)
				{
					ManyFeed = true;
				}
				else ManyFeed = false;
				canEat.push(make_pair(-distance, make_pair(-fishX, -fishY)));
			}

			//canEat.push_back(make_pair(fishX, fishY));
		}
	}
}

int calcDisFeed(int startX, int startY, int endX, int endY)
{

	int dist = 987654321;
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push(make_pair(0, make_pair(startX, startY)));

	visited = vector<vector<bool>>(N + 1, vector<bool>(N + 1, false));
	visited[startX][startY] = true;
	while (1)
	{
		if (pq.empty()) break;
		int curCount = -pq.top().first;
		int curX = pq.top().second.first;
		int curY = pq.top().second.second;
		pq.pop();
		// ������ ���
		if (curX == endX && curY == endY)
		{
			dist = min(dist, curCount);
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int _x = curX + dx[i];
			int _y = curY + dy[i];
			// ���� �´� ���
			if (_x >= 0 && _x < N && _y >= 0 && _y < N && visited[_x][_y] == false)
			{
				// �� �� �ִ� ���
				if (babySize >= map[_x][_y])
				{
					visited[_x][_y] = true;
					pq.push(make_pair(-(curCount + 1), make_pair(_x, _y)));
				}
			}
		}
	}

	return dist;
}

void EatFeed()
{

	int feedX = -canEat.top().second.first;
	int feedY = -canEat.top().second.second;
	int moveDistance = -canEat.top().first;
	result += moveDistance;
	babySizeCount++;
	if (babySize == babySizeCount)
	{
		babySize++;
		babySizeCount = 0;
	}
	map[babyShark.first][babyShark.second] = 0;
	map[feedX][feedY] = 0;
	for (int i = 0; i < feed.size(); i++)
	{
		if (feed[i].second.first == feedX && feed[i].second.second == feedY)
		{
			feed.erase(feed.begin() + i, feed.begin() + i + 1);
		}
	}
	babyShark.first = feedX;
	babyShark.second = feedY;

}
