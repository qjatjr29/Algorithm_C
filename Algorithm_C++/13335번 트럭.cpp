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
			// ���� �ִ� Ʈ������ �� �̵��� �� ����  
			if (q.size() == w)
			{
				sumWeight -= q.front();
				q.pop();
			}

			//  ������ Ʈ�� + ���� �ٸ����� Ʈ�� ���԰� L���� ������ ������.
			if (sumWeight + truckList[i] <= L)
			{
				break;
			}
			// ���԰� ũ�� ��� ���� �ִ� Ʈ���� ���� ������ �̵�.
			q.push(0);
			crossTime++;
		}
		// �ڿ� �ִ� Ʈ�� �ٸ� ���� �ö��
		q.push(truckList[i]);
		// ���� ����
		sumWeight += truckList[i];
		crossTime++;
	}
	crossTime += w;



	cout << crossTime << "\n";


	return 0;
}
