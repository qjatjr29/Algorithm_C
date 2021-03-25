#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int n; // ��Ÿ�� ����
int area; // ���簢���� �ִ� ����
int cal(vector<int> fence, int leftindex, int rightindex);
int main()
{
	int c;
	cin >> c;

	for (int i = 0; i < c; i++)
	{
		int n;
		cin >> n;
		vector<int> fence;
		for (int i = 0; i < n; i++)
		{
			int number;
			cin >> number;
			fence.push_back(number);
		}
		//int width = 0;
		area = 0;
		cout << cal(fence, 0, fence.size() - 1) << "\n";

	}



	return 0;
}

// �߰����� ����, ������ �ִ���� �� ���� ������ �� ��ġ�� �κ� �ִ���� ��
int cal(vector<int> fence, int leftindex, int rightindex)
{
	if (leftindex == rightindex) // ���������� ��������.
	{
		return fence[leftindex];
	}
	int mid = (leftindex + rightindex) / 2;  // �߰���

	// ����, ������ ������ �ִ����
	int LRmax = max(cal(fence, leftindex, mid), cal(fence, mid + 1, rightindex));

	// ������� ��ġ�� �κ� mid,mid+1 ->�ʺ� 2 ���̴� mid�� mid+1�� ������ �ּҰ�
	int mid_height = min(fence[mid], fence[mid + 1]); // �߰� �ΰ��� ������ ������.
	int temp_height = mid_height;
	int L_index = mid;
	int R_index = mid + 1;

	int midmax = 2 * mid_height; // �߰� �ΰ� ��Ÿ�� ����

	// �ΰ� �� �ִ� ����
	int maxarea = max(LRmax, midmax);

	// ��� ��ġ�ºκ��� �ϳ��� �÷�����.(���� ������ �� ���̰� ū ������)
	int height;
	while (1)
	{
		if (L_index <= leftindex && R_index >= rightindex)break;

		// �� �Ʒ� if���� ���Դٴ°� �����̵� �������̵� �� �� �� �ִٴ� ��.

		// ������ ��Ÿ���� �� �涧. ( �ε����� ���� �Ѿ�� �ȉ�.)
		//L_index �� 0�̸� L_index-1 �� �����Ƿ� ����� ����.
		if (R_index < rightindex && (L_index == leftindex || fence[L_index - 1] <= fence[R_index + 1]))
		{
			mid_height = min(temp_height, fence[R_index + 1]);
			R_index++;
			temp_height = mid_height;
		}
		// ���� ��Ÿ���� �� �涧 

		else if (L_index > leftindex && (R_index == rightindex || fence[L_index - 1] >= fence[R_index + 1]))
		{
			mid_height = min(temp_height, fence[L_index - 1]);
			L_index--;
			temp_height = mid_height;
		}
		maxarea = max(maxarea, (mid_height * (R_index - L_index + 1)));
	}

	/*
	// ����
	int count = 2;
	for (int i = mid-1; i >= leftindex; i--)
	{
		// �������� ���鼭 ���̴� ���� �ͷ�.
		int height = min(temp_height1, fence[i]);
		temp_height1 = height;
		count++;
		maxarea = max(maxarea, height * count);
	}
	// ���������� �ϳ��� �ø��鼭
	count = 2;
	for (int i = mid + 2; i <= rightindex; i++)
	{
		count++;
		int height = min(temp_height2, fence[i]);
		temp_height2 = height;
		maxarea = max(maxarea, height * count);
	}
	*/

	return maxarea;
}
