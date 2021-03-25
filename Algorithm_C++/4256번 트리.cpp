#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> preorder;
vector<int> inorder;
vector<int> postorder;
void result(int leftpreorder, int rightpreorder, int leftinorder, int rightinorder);
int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		preorder.clear();
		inorder.clear();
		for (int j = 0; j < n; j++)
		{
			int number;
			cin >> number;
			preorder.push_back(number);
		}
		for (int j = 0; j < n; j++)
		{
			int number;
			cin >> number;
			inorder.push_back(number);
		}
		result(0, n, 0, n);
		cout << "\n";
	}


	return 0;
}

void result(int leftpreorder, int rightpreorder, int leftinorder, int rightinorder)
{
	if (rightpreorder == leftpreorder)return;
	if (leftpreorder >= n)return;
	if (leftinorder >= n)return;
	// 루트 값은 전위순회의 첫번째 인덱스.
	int root = preorder[leftpreorder];

	int index = 0;
	for (int i = leftinorder; i <= rightinorder; i++)
	{
		if (inorder[i] == root)break;
		index++;
	}
	result(leftpreorder + 1, leftpreorder + index + 1, leftinorder, leftinorder + index);
	result(leftpreorder + index + 1, rightpreorder, leftinorder + index + 1, rightinorder);
	cout << root << " ";
}
