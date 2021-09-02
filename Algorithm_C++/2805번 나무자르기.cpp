#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;


long long N, M;
vector<long long> tree;
long long maxHeight;
long long result;
void cut(long long left, long long right);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		long long treeHeight;
		cin >> treeHeight;
		if (maxHeight < treeHeight)
		{
			maxHeight = treeHeight;
		}
		tree.push_back(treeHeight);
	}

	cut(0, maxHeight);
	cout << result << "\n";

	return 0;
}

void cut(long long left, long long right)
{
	while (1)
	{
		if (left > right)break;
		long long mid = (left + right) / 2;
		long long temp = 0;
		for (int i = 0; i < N; i++)
		{
			if (mid < tree[i])
			{
				temp += (tree[i] - mid);
			}
		}
		if (temp < M)
		{
			right = mid - 1;
		}
		else
		{
			result = max(result, mid);
			left = mid + 1;
		}
	}
}
