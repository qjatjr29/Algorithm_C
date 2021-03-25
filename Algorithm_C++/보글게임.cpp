#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;


string boggle[5];
int N;  // �츮�� ã�ƾ� �ϴ� �ܾ�� ���� 
vector<string> check; // ã�ƾ� �ϴ� �ܾ�� ���� 
vector<string> result; // ��� ����
string s;

int fun(int x, int y, int count, int sizenum);
int main()
{
	int C;  // �׽�Ʈ ���̽�
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

			cin >> s;   // ã�ƾ��ϴ� �ܾ� ���پ� �Է¹���
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
	if (x < 0 || x >= 5 || y < 0 || y >= 5) return 0;  // ���� �Ѿ ���
	if (count == sizenum - 1)return 1; // �� ã�� ���
	if (boggle[x][y] != s[count]) return 0; // ã�°Ŷ� �ٸ� ��� 

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
