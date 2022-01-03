#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> people;
int main()
{
	int c;
	cin >> c;

	for (int i = 0; i < c; i++)
	{
		cin >> N >> K;
		people.clear();
		for (int j = 0; j < N; j++)
		{
			people.push_back(j + 1);
		}
		while (1)
		{
			if (people.size() == 2)break;
			people.erase(people.begin(), people.begin() + 1);
			/*for (int i = 0; i < people.size(); i++)
			{
				cout << people[i] << " ";
			}
			cout << "\n";*/

			for (int j = 1; j < K; j++)
			{
				int temp = people[0];
				people.erase(people.begin(), people.begin() + 1);
				people.push_back(temp);
			}
			//
			//	vector<int> temp;
			//	int count = 0;
			//	
			//	// K번째 값 보다 앞에 있는 값들 저장
			//	

			//	for (int n = 0; n < K-1 ; n++)
			//	{
			//		if (n == people.size())
			//			count = 0;
			//		count++;
			//	}
			//	for (int n = 0; n < count; n++)
			//	{
			//		temp.push_back(people[n]);
			//	}

			//	// people 벡터에 temp 벡터 값들 다시 넣고 처음~K 번째 까지 값들 다 삭제
			//	if (people.size() != 2)
			//	{

			//		for (int n = 0; n < temp.size(); n++)
			//		{
			//			people.push_back(temp[n]);
			//		}
			//		people.erase(people.begin(), people.begin() + K);
			//	}
			//}
		}
		sort(people.begin(), people.end());
		cout << people[0] << " " << people[1] << "\n";

	}


	return 0;
}




/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int N, K;
int main()
{
	int c;
	cin >> c;
	for (int i = 0; i < c; i++)
	{
		cin >> N >> K;
		queue<int> people;
		for (int j = 1; j <= N; j++)
		{
			people.push(j);
		}
		while (1)
		{
			if (people.size() == 2)break;
			people.pop();
			for (int j = 1; j < K; j++)
			{
				int temp = people.front();
				people.pop();
				people.push(temp);
			}
		}
		int _min = min(people.front(), people.back());
		int _max = max(people.front(), people.back());
		cout << _min << " " << _max << "\n";
	}



	return 0;
}
*/
