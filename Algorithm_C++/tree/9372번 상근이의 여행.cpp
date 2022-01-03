#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> preorder;

int number;
void solve(int firstindex, int endindex);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (cin >> number)
	{
		preorder.push_back(number);
	}

	solve(0, preorder.size());

	return 0;
}

void solve(int firstindex, int endindex)
{
	int size = endindex - firstindex;


	if (firstindex == endindex) return;
	if (firstindex >= preorder.size())return;
	int root = preorder[firstindex];


	// 루트 값보다 작은값 찾는 작업.
	int index = -1;
	bool check = false;
	for (int i = firstindex; i < endindex; i++)
	{
		if (root < preorder[i])
		{
			check = true;
			break;
		}
		index++;
	}
	if (check)
	{
		solve(firstindex + 1, firstindex + index + 1);
		solve(firstindex + index + 1, endindex);
		cout << root << "\n";
	}
	else
	{
		solve(firstindex + 1, endindex);
		cout << root << "\n";
	}

}
