#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int n; // 울타리 갯수
int area; // 직사각형의 최대 넓이
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

// 중간에서 왼쪽, 오른쪽 최대넓이 랑 왼쪽 오른쪽 다 겹치는 부분 최대넓이 비교
int cal(vector<int> fence, int leftindex, int rightindex)
{
	if (leftindex == rightindex) // 끝까지가서 겹쳤을때.
	{
		return fence[leftindex];
	}
	int mid = (leftindex + rightindex) / 2;  // 중간값

	// 왼쪽, 오른쪽 넓이중 최대넓이
	int LRmax = max(cal(fence, leftindex, mid), cal(fence, mid + 1, rightindex));

	// 가운데에서 겹치는 부분 mid,mid+1 ->너비 2 높이는 mid와 mid+1의 높이중 최소값
	int mid_height = min(fence[mid], fence[mid + 1]); // 중간 두개의 높이중 낮은것.
	int temp_height = mid_height;
	int L_index = mid;
	int R_index = mid + 1;

	int midmax = 2 * mid_height; // 중간 두개 울타리 넓이

	// 두개 중 최대 넓이
	int maxarea = max(LRmax, midmax);

	// 가운데 겹치는부분을 하나씩 늘려야함.(왼쪽 오른쪽 중 높이가 큰 것으로)
	int height;
	while (1)
	{
		if (L_index <= leftindex && R_index >= rightindex)break;

		// 이 아래 if으로 들어왔다는건 왼쪽이든 오른쪽이든 갈 곳 이 있다는 것.

		// 오른쪽 울타리가 더 길때. ( 인덱스가 범위 넘어가면 안됌.)
		//L_index 가 0이면 L_index-1 가 없으므로 여기로 들어옴.
		if (R_index < rightindex && (L_index == leftindex || fence[L_index - 1] <= fence[R_index + 1]))
		{
			mid_height = min(temp_height, fence[R_index + 1]);
			R_index++;
			temp_height = mid_height;
		}
		// 왼쪽 울타리가 더 길때 

		else if (L_index > leftindex && (R_index == rightindex || fence[L_index - 1] >= fence[R_index + 1]))
		{
			mid_height = min(temp_height, fence[L_index - 1]);
			L_index--;
			temp_height = mid_height;
		}
		maxarea = max(maxarea, (mid_height * (R_index - L_index + 1)));
	}

	/*
	// 왼쪽
	int count = 2;
	for (int i = mid-1; i >= leftindex; i--)
	{
		// 왼쪽으로 가면서 높이는 낮은 것로.
		int height = min(temp_height1, fence[i]);
		temp_height1 = height;
		count++;
		maxarea = max(maxarea, height * count);
	}
	// 오른쪽으로 하나씩 늘리면서
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
