#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> tip;
//int maxtip;

//void starbox(int curindex,int count);

int main()
{
	int N;
	cin >> N;
	long long max_tip = 0;
	for (int i = 0; i < N; i++)
	{
		int _tip;
		cin >> _tip;
		tip.push_back(_tip);
	}
	sort(tip.begin(), tip.end());
	int turn = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		if (tip[i] - turn > 0)
		{
			max_tip += (tip[i] - turn);
			turn++;
		}
		else break;
	}
	//starbox(N-1,0);
	cout << max_tip << "\n";
	//cout << maxtip << "\n";

	return 0;
}

//void starbox(int curindex,int count)
//{
//	if (curindex < 0 )return;
//	if (tip[curindex] - count > 0)
//	{
//		maxtip += (tip[curindex] - count );
//	}
//	else return;
//	return starbox(curindex - 1,count+1);
//}
