#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<bool>> visited;
string map[51];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int result;
void miro(int startx, int starty);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> n;
	visited = vector<vector<bool>>(51, vector<bool>(51, false));
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		map[i] = s;
	}
	miro(0, 0);
	cout << result << "\n";

	return 0;
}

void miro(int startx, int starty)
{
	priority_queue < pair<int, pair<int, int>>> pq;

	pq.push(make_pair(0, make_pair(startx, starty)));

	visited[startx][starty] = true;

	while (1)
	{
		if (pq.empty())break;
		int cx = pq.top().second.first;
		int cy = pq.top().second.second;
		int cs = -pq.top().first;
		pq.pop();
		if (cx == n - 1 && cy == n - 1)
		{
			result = cs;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && visited[nx][ny] == false)
			{
				if (map[nx][ny] == '0')
				{
					pq.push(make_pair(-(cs + 1), make_pair(nx, ny)));
				}
				else pq.push(make_pair(-cs, make_pair(nx, ny)));
				visited[nx][ny] = true;
			}
		}


	}
}
