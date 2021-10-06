#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int parentNode[500001];
int result;
int getNode(int idx);
bool findParent(int num1, int num2);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		parentNode[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int sn, dn;
		cin >> sn >> dn;
		if (findParent(sn, dn))
		{
			if (result == 0)result = i + 1;
		}
	}
	cout << result << "\n";
	return 0;
}

int getNode(int idx)
{
	if (parentNode[idx] == idx)return idx;
	else
	{
		return parentNode[idx] = getNode(parentNode[idx]);
	}
}

bool findParent(int num1, int num2)
{
	int pNum1 = getNode(num1);
	int pNum2 = getNode(num2);

	if (pNum1 == pNum2)return true;
	parentNode[pNum2] = pNum1;
	return false;
}
