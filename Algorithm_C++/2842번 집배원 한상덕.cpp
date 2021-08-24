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
// 피로도
int fatigue = 987654321;
// 우체국 (x,y) / 고도의 값 
pair<pair<int, int>, int> postOffice;
// p / x / . 
vector<vector<char>> map;
// 고도값 저장.
vector<vector<int>> elevation;
vector<int> sortElevation;
// 작은 고도값 , 큰 고도값
int leftHeight, rightHeight;
// 방문 여부 확인
vector<vector<bool>> visited;
// 모든 집에 배달 가능한지 확인
bool deliver = false;
// bfs
void deliverToHouse();
// 가장 작은 고도 차 찾기 
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
	// 우체국의 고도
	postOffice.second = elevation[postOffice.first.first][postOffice.first.second];

	// 각 고도들 정렬 및 중복 삭제 
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
			// 범위에 들어오고 방문하지 않은 경우.
			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N && visited[nextX][nextY] == false)
			{
				// 고도 값이되는지 확인.
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
	// 왼쪽 고도 값과 오른쪽 고도 값으로 모든 집에 배달 가능한지 체크
	while (1)
	{
		// 범위 넘어가면 break;
		if (rightHeight >= sortElevation.size())break;

		// 모든집에 배달 가능 한지 확인
		while (1)
		{
			bool chk = false;
			// 처음 시작부터 되는지 확인해야한다.
			if (postOffice.second >= sortElevation[leftHeight] &&
				postOffice.second <= sortElevation[rightHeight])
			{
				// bfs 시작
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
		// 안되면 rightHeight ++; 
		rightHeight++;
	}
}
