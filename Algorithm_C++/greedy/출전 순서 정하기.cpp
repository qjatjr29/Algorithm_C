#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> enemy;
vector<int> korea;
int main()

{
	int c;
	cin >> c;
	for (int i = 0; i < c; i++)
	{
		enemy.clear();
		korea.clear();
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			int enemyrating;
			cin >> enemyrating;
			enemy.push_back(enemyrating);
		}
		for (int j = 0; j < n; j++)
		{
			int rating;
			cin >> rating;
			korea.push_back(rating);
		}
		sort(enemy.begin(), enemy.end());
		sort(korea.begin(), korea.end());
		int count = 0;
		int cmp = 0;
		//int index;
		// 상대 가장 작은 레이팅보다 우리선수 레이팅이 큰 첫 index 구하기.
		for (int j = 0; j < n; j++)
		{
			if (enemy[cmp] <= korea[j])
			{
				cmp++;
				//index == j;
				count++;
			}
		}
		cout << count << "\n";
	}


	return 0;
}