#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

string Word;
string bomb;
int bombSize;
vector<char> store;
char result[1000001];
bool checkAlpha(int curindex);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> Word >> bomb;
	/*for (int i = 0; i < firstWord.size(); i++)
	{
		store.push_back(firstWord[i]);
	}*/
	// ���� ��ʴ� ���� ���ڿ��� ���°��
	// ���̻� bomb string�� ���� ���
	// �ݺ��� ����.
	bombSize = bomb.size();

	int Curindex = 0;
	for (int i = 0; i < Word.size(); i++)
	{
		//Curindex++;
		result[Curindex++] = Word[i];

		int tempBombSize = bomb.size();
		if (Word[i] == bomb[--tempBombSize])
		{
			bool checkBomb = false;
			for (int j = Curindex - 1; j >= Curindex - bombSize; j--)
			{
				if (result[j] != bomb[tempBombSize--])
				{
					// ���� �Ұ� ����.
					checkBomb = true;
					break;
				}
			}
			// ������ �� ����.
			if (!checkBomb)
			{
				Curindex -= bombSize;
			}
		}

	}
	if (Curindex == 0)cout << "FRULA" << "\n";
	else
	{
		for (int i = 0; i < Curindex; i++)
		{
			cout << result[i] << "";
		}
		cout << "\n";
	}



	//while (1)
	//{
	//	int vectorSize = store.size();
	//	if (vectorSize == 0)
	//	{
	//		cout << "FRULA" << "\n";
	//		return 0;
	//	}
	//	bool checkBomb = false;
	//	int bombIndex;
	//	for (int i = 0; i < vectorSize; i++)
	//	{
	//		// bomb string �� ù �ε������� ���� ��� �Լ� ����.
	//		if (store[i] == bomb[bomb.size()-1])
	//		{
	//			// ���� bomb string ã����  true�� �Ǿ��ִ�.
	//			bombIndex = i;
	//			checkBomb=checkAlpha(i);
	//		}
	//		if (checkBomb)break;
	//	}
	//	// �߶����.
	//	if (checkBomb)
	//	{
	//		store.erase(store.begin() + bombIndex, store.begin() + bombIndex + bombSize);
	//	}
	//	// �ڸ����� ����.
	//	else
	//	{
	//		for (int i = 0; i < store.size(); i++)
	//		{
	//			cout << store[i] << "";
	//		}
	//		cout << "\n";
	//		return 0;
	//	}

	//}



	return 0;
}

//bool checkAlpha(int curindex)
//{
//	int bombIndex = 1;
//	for (int i = curindex-1; i>=curindex-bombSize; i--)
//	{	
//		if (i >= store.size()) return false;
//		if (store[i] != bomb[bombIndex])
//		{
//			return false;
//		}
//		bombIndex++;
//	}
//	return false;
//}
