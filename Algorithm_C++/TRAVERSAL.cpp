#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> preorder;
vector<int> inorder;
vector<int> postorder;
void settree();
void post_order(vector<int>& preorder, vector<int>& inorder);

int main()
{
	int c;
	cin >> c;

	for (int i = 0; i < c; i++)
	{
		preorder.clear();
		inorder.clear();
		cin >> N;
		settree();
		post_order(preorder, inorder);
		cout << "\n";
	}


	return 0;
}

// ����, ���� ��ȸ Ʈ�� �� ����.
void settree()
{
	for (int i = 0; i < N; i++)
	{
		int number;
		cin >> number;
		preorder.push_back(number);
	}
	for (int i = 0; i < N; i++)
	{
		int number;
		cin >> number;
		inorder.push_back(number);
	}

}

// ���� ��ȸ �̹Ƿ� ���� ��� -> ������ ��� -> ��Ʈ �� ������ ���.

void post_order(vector<int>& preorder, vector<int>& inorder)
{
	// ���� �ƹ��͵� ������ �ٽ� ���´�.
	if (preorder.empty())return;

	// ���� Ʈ���� ��Ʈ��. (������ȸ Ʈ���� ù��° �ε����� ������ ��Ʈ)
	int root = preorder[0];

	// ��Ʈ���� inorder ���Ϳ��� ���° index���� ã�ƾ���.

	int index = 0;
	for (int i = 0; i < inorder.size(); i++)
	{
		if (inorder[i] == root)break;
		index++;
	}

	// Ʈ�� ������ ��Ʈ���� �����ؾ���.

	// ��Ʈ�� ���� ���� Ʈ����.
	// ������ȸ Ʈ���� 0��°�� ��Ʈ ������ 1��°���� index+1 ��ŭ �ڸ���.
	// ������ȸ Ʈ���� 0��° ���� index ũ�⸸ŭ �ڸ���.
	vector<int> left_preorder = vector<int>(preorder.begin() + 1, preorder.begin() + index + 1);
	vector<int> left_inorder = vector<int>(inorder.begin(), inorder.begin() + index);

	// ��Ʈ�� ������ ���� Ʈ����
	// ������ȸ Ʈ���� index+1��°�� ��Ʈ�� ������ ���� 
	// ���� ��ȸ Ʈ���� index�� ��Ʈ ���̹Ƿ� �� ������ ���� �������̴�.
	vector<int> right_preorder = vector<int>(preorder.begin() + index + 1, preorder.end());
	vector<int> right_inorder = vector<int>(inorder.begin() + index + 1, inorder.end());

	post_order(left_preorder, left_inorder);

	post_order(right_preorder, right_inorder);

	cout << root << " ";

}
