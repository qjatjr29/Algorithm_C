#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int t, N;
bool consistence;

struct Trie {
	bool finish;
	Trie* nextNode[10];

	~Trie() {
		for (int i = 0; i < 10; i++)
		{
			if (nextNode[i])delete nextNode[i];
		}
	}
	void insert(const char* str)
	{
		if (*str == '\0')finish = true;
		else
		{
			int index = *str - '0';
			if (nextNode[index] == NULL)
			{
				nextNode[index] = new Trie();
			}
			nextNode[index]->insert(str + 1);
		}
		return;
	}

	bool find(const char* str)
	{
		if (*str == '\0') return true;
		if (finish)return false;
		int index = *str - '0';
		return nextNode[index]->find(str + 1);
	}

};

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> t;
	for (int testcase = 0; testcase < t; testcase++)
	{
		cin >> N;
		consistence = true;
		Trie* trie = new Trie();
		char number[10001][11];
		for (int i = 0; i < N; i++)
		{
			cin >> number[i];
			trie->insert(number[i]);
		}

		for (int i = 0; i < N; i++)
		{
			// 老包己捞 绝绰 版快.
			if (!trie->find(number[i]))
			{
				consistence = false;
				break;
			}
		}
		if (consistence)
		{
			cout << "YES" << "\n";
		}
		else cout << "NO" << "\n";
		delete trie;
	}

	return 0;
}

