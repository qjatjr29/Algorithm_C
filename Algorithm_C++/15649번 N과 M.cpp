#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> result;
vector<int> temparr;
bool visited[9];
void permutation(int r);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N >> M;

	permutation(0);

	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size() - 1; j++)
		{
			cout << result[i][j] << " ";
		}
		cout << result[i][result[i].size() - 1] << "\n";
	}


	return 0;
}

void permutation(int r)
{
	if (M == r)
	{
		result.push_back(temparr);
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		if (visited[i])continue;
		temparr.push_back(i);
		visited[i] = true;
		permutation(r + 1);
		visited[i] = false;
		temparr.pop_back();
	}
}
