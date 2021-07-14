#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> friends;
vector<int> order;
vector<vector<int>> map;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
priority_queue < pair<int, pair<int, int>>> firstCondition;
bool firstCheck;
int checkEmpty(int x, int y);
void checkFriend(int x, int y, int student);
int result;
void calcResult();
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N;
	int n = N * N;
	friends = vector<vector<int>>(n + 1, vector<int>(4, 0));
	order = vector<int>(n + 1, 0);
	map = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	for (int i = 0; i < n; i++)
	{
		int student;
		cin >> student;
		order[i] = student;
		//friends[i][0] = student;
		for (int j = 0; j < 4; j++)
		{
			int friendNum;
			cin >> friendNum;
			friends[student][j] = friendNum;
		}
	}

	for (int i = 0; i < n; i++)
	{
		int curindex = order[i];

		int firstConditionSize = firstCondition.size();
		for (int i = 0; i < firstConditionSize; i++)
		{
			firstCondition.pop();
		}
		firstCheck = false;
		firstCondition.push(make_pair(-1, make_pair(-1, -1)));
		for (int j = 0; j < N; j++)
		{
			for (int z = 0; z < N; z++)
			{
				// 비어 있을 경우 
				if (map[j][z] == 0)
				{
					checkFriend(j, z, curindex);
				}
			}
		}

		if (firstCheck == false)
		{
			int curX = firstCondition.top().second.first;
			int curY = firstCondition.top().second.second;
			map[curX][curY] = curindex;
		}
		else
		{
			// 두번 째 조건
			int maxNum = firstCondition.top().first;
			priority_queue<pair<int, pair<int, int>>> secondCondition;
			secondCondition.push(make_pair(-1, make_pair(-1, -1)));
			bool secondCheck = false;
			while (1)
			{
				if (maxNum != firstCondition.top().first)break;
				if (firstCondition.empty())break;
				int curX = firstCondition.top().second.first;
				int curY = firstCondition.top().second.second;
				int countNum = checkEmpty(curX, curY);

				firstCondition.pop();
				if (secondCondition.top().first <= countNum && secondCondition.top().first == countNum)
				{
					secondCheck = true;
				}

				secondCondition.push(make_pair(countNum, make_pair(-curX, -curY)));
			}
			/*int secondX = -secondCondition.top().second.first;
			int secondY = -secondCondition.top().second.second;
			map[secondX][secondY] = curindex;*/
			if (secondCheck == false)
			{
				int secondX = -secondCondition.top().second.first;
				int secondY = -secondCondition.top().second.second;
				map[secondX][secondY] = curindex;
			}
			else
			{
				priority_queue<pair<int, pair<int, int>>> finalCondition;
				bool finalCheck = false;
				int emptyCount = secondCondition.top().first;
				while (1)
				{
					if (emptyCount != secondCondition.top().first)break;
					if (secondCondition.empty())break;
					int currentX = -secondCondition.top().second.first;
					int currentY = -secondCondition.top().second.second;
					int countNumber = checkEmpty(currentX, currentY);
					secondCondition.pop();
					finalCondition.push(make_pair(countNumber, make_pair(-currentX, -currentY)));
				}
				int finalX = -finalCondition.top().second.first;
				int finalY = -finalCondition.top().second.second;
				map[finalX][finalY] = curindex;
			}
		}

	}

	calcResult();
	cout << result << "\n";

	return 0;
}

int checkEmpty(int x, int y)
{
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		int checkX = x + dx[i];
		int checkY = y + dy[i];
		if (checkX >= 0 && checkX < N && checkY >= 0 && checkY < N)
		{
			if (map[checkX][checkY] == 0)count++;

		}
	}
	return count;
}

void checkFriend(int x, int y, int student)
{
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		// 찾아야 하는 친구의 번호
		int friendNumber = friends[student][i];
		for (int j = 0; j < 4; j++)
		{
			int _x = x + dx[j];
			int _y = y + dy[j];
			if (_x >= 0 && _x < N && _y >= 0 && _y < N)
			{
				if (map[_x][_y] == friendNumber)
				{
					count++;
					break;
				}
			}
		}
	}
	if (firstCondition.top().first <= count && firstCondition.top().first == count)
	{
		firstCheck = true;
	}
	//else firstCheck = false;
	firstCondition.push(make_pair(count, make_pair(x, y)));

}

void calcResult()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int student = map[i][j];
			int count = 0;
			for (int z = 0; z < 4; z++)
			{
				int favfriend = friends[student][z];
				for (int n = 0; n < 4; n++)
				{
					int _x = i + dx[n];
					int _y = j + dy[n];
					if (_x >= 0 && _x < N && _y >= 0 && _y < N)
					{
						if (map[_x][_y] == favfriend)count++;
					}
				}
			}
			switch (count)
			{
			case 0:
				result += 0;
				break;
			case 1:
				result += 1;
				break;
			case 2:
				result += 10;
				break;
			case 3:
				result += 100;
				break;
			case 4:
				result += 1000;
				break;
			default:
				break;
			}
		}
	}
}



