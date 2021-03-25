#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> preorder; // ����ؾ��ϴ� ��.
vector<int> inorder;
vector<int> postorder;

void setpreorder(int instart, int inend, int poststart, int postend);
//void setpreorder(vector<int>& postorder, vector<int>& inorder);
int main()
{
	cin >> n;
	// ���� ��ȸ  ��->��Ʈ->��
	for (int i = 0; i < n; i++)
	{
		int number;
		cin >> number;
		inorder.push_back(number);
	}
	// ���� ��ȸ   ��->��->��Ʈ
	for (int i = 0; i < n; i++)
	{
		int number;
		cin >> number;
		postorder.push_back(number);
	}
	setpreorder(0, inorder.size() - 1, 0, postorder.size() - 1);
	cout << "\n";

	return 0;
}

/*  �޸��ʰ�
void setpreorder(vector<int>& postorder, vector<int>& inorder)
{
	int size = postorder.size();
	if (size <= 0)return;

	// ��Ʈ ���� ����Ʈ������ ������ ��.
	int root = postorder[size - 1];

	// �ο��� ���� ��Ʈ���� ���� �� ã�Ƽ� �ε��� ����.
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		if (root == inorder[i]) break;
		index++;

	}


	vector<int> leftinorder = vector<int>(inorder.begin(), inorder.begin() + index);
	vector<int> leftpostorder = vector<int>(postorder.begin(), postorder.begin() + index);

	vector<int> rightinorder = vector<int>(inorder.begin()+index+1, inorder.end());
	vector<int> rightpostorder = vector<int>(postorder.begin() + index, postorder.end()-1);

	cout << root << " ";
	setpreorder(leftpostorder, leftinorder);
	setpreorder(rightpostorder, rightinorder);
}
*/

void setpreorder(int instart, int inend, int poststart, int postend)
{
	int size = postend - poststart + 1;

	if (size == 0)return;
	int root = postorder[postend];
	int index = 0;
	for (int i = instart; i <= inend; i++)
	{
		if (root == inorder[i]) break;
		index++;

	}
	cout << root << " ";
	setpreorder(instart, instart + index - 1, poststart, poststart + index - 1);
	setpreorder(instart + index + 1, inend, poststart + index, postend - 1);

}
