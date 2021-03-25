#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;


string boggle[5];
int N;  // 우리가 찾아야 하는 단어들 개수 
vector<string> check; // 찾아야 하는 단어들 저장 
vector<string> result; // 결과 저장
string s;

int fun(int x, int y, int count, int sizenum);
int main()
{
	int C;  // 테스트 케이스
	cin >> C;

	for (int i = 0; i < C; i++)
	{

		for (int j = 0; j < 5; j++)
		{
			cin >> boggle[j];
		}
		cin >> N;
		for (int z = 0; z < N; z++)
		{

			cin >> s;   // 찾아야하는 단어 한줄씩 입력받음
			int size = s.size();
			check.push_back(s);
			int checknum = 0;
			for (int n = 0; n < 5; n++)
			{
				for (int m = 0; m < 5; m++)
				{
					if (fun(n, m, 0, size) == 1)
					{
						checknum = 1;
						break;
					}
				}
				if (checknum == 1)
				{
					break;
				}
			}
			if (checknum == 1)
			{
				result.push_back("YES");
			}
			else result.push_back("NO");

		}
		for (int v = 0; v < N; v++)
		{
			cout << check[v] << " " << result[v] << "\n";
		}

	}
	return 0;
}

int fun(int x, int y, int count, int sizenum)
{
	if (x < 0 || x >= 5 || y < 0 || y >= 5) return 0;  // 범위 넘어간 경우
	if (count == sizenum - 1)return 1; // 다 찾은 경우
	if (boggle[x][y] != s[count]) return 0; // 찾는거랑 다른 경우 

	if (fun(x - 1, y - 1, count + 1, sizenum))return 1;
	else if (fun(x - 1, y, count + 1, sizenum))return 1;
	else if (fun(x - 1, y + 1, count + 1, sizenum))return 1;
	else if (fun(x, y - 1, count + 1, sizenum))return 1;
	else if (fun(x, y + 1, count + 1, sizenum))return 1;
	else if (fun(x + 1, y - 1, count + 1, sizenum))return 1;
	else if (fun(x + 1, y, count + 1, sizenum))return 1;
	else if (fun(x + 1, y + 1, count + 1, sizenum))return 1;

	return 0;
}
