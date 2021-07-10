#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> A;
int B, C;
long long result;
void checkPeople();
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int people;
		cin >> people;
		A.push_back(people);
	}
	cin >> B >> C;
	checkPeople();
	cout << result << "\n";


	return 0;
}

void checkPeople()
{
	for (int i = 0; i < A.size(); i++)
	{
		int gap = A[i] - B;
		result++;
		if (gap <= 0)continue;
		else
		{
			long long count;
			//if (gap < C)count = 1;
			if (gap % C == 0)
			{
				count = gap / C;
			}
			else count = gap / C + 1;

			result += count;
		}
	}
}
