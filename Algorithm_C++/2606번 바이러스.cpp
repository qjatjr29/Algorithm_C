#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int result;
vector<vector<int>> path;
vector<bool> visited;
void virus(int curindex);
int main()
{
	cin >> N >> M;
	path = vector<vector<int>>(N + 1, vector<int>());
	visited = vector<bool>(N + 1, false);
	for (int i = 0; i < M; i++)
	{
		int first, second;
		cin >> first >> second;
		path[first].push_back(second);
		path[second].push_back(first);
	}
	virus(1);
	cout << result - 1 << "\n";


	return 0;
}

void virus(int curindex)
{
	if (visited[curindex])return;
	if (path[curindex].size() == 0)return;
	result++;
	visited[curindex] = true;
	for (int i = 0; i < path[curindex].size(); i++)
	{
		virus(path[curindex][i]);
	}

}
