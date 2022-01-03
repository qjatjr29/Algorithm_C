#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

vector<deque<int>> gear;
int K;
void turnGear(int index, int direction);
int result;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	gear = vector<deque<int>>(5, deque<int>());
	for (int i = 1; i <= 4; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			int number = s[j] - '0';

			gear[i].push_back(number);
		}
	}

	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int turnIndex, dir;
		cin >> turnIndex >> dir;
		turnGear(turnIndex, dir);
	}
	for (int i = 1; i <= 4; i++)
	{
		if (gear[i][0] == 1)
		{
			switch (i)
			{
			case 1:
				result += 1;
				break;
			case 2:
				result += 2;
				break;
			case 3:
				result += 4;
				break;
			case 4:
				result += 8;
				break;
			default:
				break;
			}
		}
	}
	cout << result << "\n";
	return 0;
}

void turnGear(int index, int direction)
{
	int count = 0;
	priority_queue < pair<pair<int, int>, pair<int, int>>> pq;
	pq.push(make_pair(make_pair(count, 0), make_pair(index, direction)));

	while (1)
	{
		if (pq.empty())break;

		// Åé´Ï¹ÙÄû ÀÌµ¿
		int curCount = -pq.top().first.first;
		int curIndex = pq.top().second.first;
		int dir = pq.top().second.second;
		int preindex = pq.top().first.second;
		pq.pop();
		int leftState = gear[curIndex][6];
		int rightState = gear[curIndex][2];

		// ¿ÞÂÊ Åé´Ï ¹ÙÄû ÀÖ´Â °æ¿ì
		if (curIndex - 1 > 0)
		{
			// ¿ÞÂÊ Åé´Ï ¹ÙÄû¶û ±ØÀÌ ´Ù¸¥ °æ¿ì --> queue¿¡ ³Ö±â
			if (preindex != curIndex - 1 && leftState != gear[curIndex - 1][2])
			{
				int nextDir;
				if (dir == 1)
				{
					nextDir = -1;
				}
				else {
					nextDir = 1;
				}
				pq.push(make_pair(make_pair(-(curCount + 1), curIndex), make_pair(curIndex - 1, nextDir)));
			}
		}
		// ¿À¸¥ÂÊ Åé´Ï ¹ÙÄû ÀÖ´Â °æ¿ì
		if (curIndex + 1 < 5)
		{
			// ¿À¸¥ÂÊ Åé´Ï ¹ÙÄû¶û ±ØÀÌ ´Ù¸¥ °æ¿ì --> queue¿¡ ³Ö±â

			if (preindex != curIndex + 1 && rightState != gear[curIndex + 1][6])
			{
				int nextDir;
				if (dir == 1)
				{
					nextDir = -1;
				}
				else {
					nextDir = 1;
				}
				pq.push(make_pair(make_pair(-(curCount + 1), curIndex), make_pair(curIndex + 1, nextDir)));
			}
		}

		//ÀÌµ¿
		// ½Ã°è ¹æÇâ
		if (dir == 1)
		{
			int temp = gear[curIndex].back();
			gear[curIndex].pop_back();
			gear[curIndex].push_front(temp);
		}
		// ¹Ý½Ã°è ¹æÇâ
		if (dir == -1)
		{
			int temp = gear[curIndex].front();
			gear[curIndex].pop_front();
			gear[curIndex].push_back(temp);
		}
	}

}

