#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

string skill;
vector<string> skill_trees;
int solution(string skill, vector<string>skill_trees);
int main()
{
	skill = "CBD";
	skill_trees.push_back("CED");


	//skill_tree.push_back("AECB");
	//skill_tree.push_back("BDA");

	cout << solution(skill, skill_trees) << "\n";

	return 0;
}

int solution(string skill, vector<string> skill_trees)
{
	int answer = 0;
	answer = skill_trees.size();
	vector<char> store;
	for (int i = 0; i < skill.size(); i++)
	{
		store.push_back(skill[i]);
	}
	bool check = true;
	for (int i = 0; i < skill_trees.size(); i++)
	{
		check = true;
		vector<char> temp;
		for (int j = 0; j < skill_trees[i].size(); j++)
		{
			for (int z = 0; z < store.size(); z++)
			{
				if (store[z] == skill_trees[i][j])
				{
					temp.push_back(store[z]);
				}
			}
		}
		for (int n = 0; n < temp.size(); n++)
		{
			// 안되는 경우.
			if (store[n] != temp[n])
			{
				answer--;
				break;
			}
		}
	}

	return answer;
}
