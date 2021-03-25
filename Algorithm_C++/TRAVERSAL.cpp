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

// 전위, 중위 순회 트리 값 저장.
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

// 후위 순회 이므로 왼쪽 노드 -> 오른쪽 노드 -> 루트 값 순으로 출력.

void post_order(vector<int>& preorder, vector<int>& inorder)
{
	// 만약 아무것도 없으면 다시 나온다.
	if (preorder.empty())return;

	// 서브 트리의 루트값. (전위순회 트리의 첫번째 인덱스가 무조건 루트)
	int root = preorder[0];

	// 루트값을 inorder 벡터에서 몇번째 index인지 찾아야함.

	int index = 0;
	for (int i = 0; i < inorder.size(); i++)
	{
		if (inorder[i] == root)break;
		index++;
	}

	// 트리 나눌때 루트값은 제외해야함.

	// 루트의 왼쪽 서브 트리들.
	// 전위순회 트리는 0번째가 루트 임으로 1번째부터 index+1 만큼 자른다.
	// 중위순회 트리는 0번째 부터 index 크기만큼 자른다.
	vector<int> left_preorder = vector<int>(preorder.begin() + 1, preorder.begin() + index + 1);
	vector<int> left_inorder = vector<int>(inorder.begin(), inorder.begin() + index);

	// 루트의 오른쪽 서브 트리들
	// 전위순회 트리는 index+1번째가 루트의 오른쪽 시작 
	// 중위 순회 트리는 index가 루트 값이므로 그 오른쪽 부터 오른쪽이다.
	vector<int> right_preorder = vector<int>(preorder.begin() + index + 1, preorder.end());
	vector<int> right_inorder = vector<int>(inorder.begin() + index + 1, inorder.end());

	post_order(left_preorder, left_inorder);

	post_order(right_preorder, right_inorder);

	cout << root << " ";

}
