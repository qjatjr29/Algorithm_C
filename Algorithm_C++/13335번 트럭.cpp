#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, w, L;
vector<int> truckList;
int crossTime;

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> n >> w >> L;

	for (int i = 0; i < n; i++)
	{
		int weight;
		cin >> weight;
		truckList.push_back(weight);
	}
	int sumWeight = 0;
	queue<int> q;
	for (int i = 0; i < n; i++)
	{
		while (1)
		{
			// 원래 있던 트럭들이 다 이동할 때 까지  
			if (q.size() == w)
			{
				sumWeight -= q.front();
				q.pop();
			}

			//  들어오는 트럭 + 원래 다리위의 트록 무게가 L보다 작을때 나간다.
			if (sumWeight + truckList[i] <= L)
			{
				break;
			}
			// 무게가 크면 계속 원래 있던 트럭이 나갈 때까지 이동.
			q.push(0);
			crossTime++;
		}
		// 뒤에 있던 트럭 다리 위로 올라옴
		q.push(truckList[i]);
		// 무게 증가
		sumWeight += truckList[i];
		crossTime++;
	}
	crossTime += w;



	cout << crossTime << "\n";


	return 0;
}
