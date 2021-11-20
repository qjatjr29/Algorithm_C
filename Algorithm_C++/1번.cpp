#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;


vector<string> monsters;
string solution(string character, vector<string> monsters);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	monsters.push_back("Knight 3 10 10 3");
	monsters.push_back("Wizard 5 10 15 1");
	monsters.push_back("Beginner 1 1 15 1");

	string ans = solution("10 5 2", monsters);
	cout << ans << "\n";

	return 0;
}
string solution(string character, vector<string> monsters) {
	string answer = "";
	pair<double,int> result = make_pair(0,0);
	int pIndex = character.find(' ');
	int player_hp = stoi(character.substr(0, pIndex));
	int temp = player_hp;
	
	character = character.substr(pIndex + 1);
	pIndex = character.find(' ');
	int player_attack = stoi(character.substr(0, pIndex));
	int player_defense = stoi(character.substr(pIndex + 1));
	

	for (int i = 0; i < monsters.size(); i++)
	{
		int mIndex = monsters[i].find(' ');
		string monsters_name = monsters[i].substr(0, mIndex);
		monsters[i] = monsters[i].substr(mIndex + 1);
		mIndex = monsters[i].find(' ');
		int monsters_exp = stoi(monsters[i].substr(0, mIndex));
		monsters[i] = monsters[i].substr(mIndex + 1);
		mIndex = monsters[i].find(' ');
		int monsters_hp = stoi(monsters[i].substr(0, mIndex));
		monsters[i] = monsters[i].substr(mIndex + 1);
		mIndex = monsters[i].find(' ');
		int monsters_attack = stoi(monsters[i].substr(0, mIndex));
		int monsters_defense = stoi(monsters[i].substr(mIndex + 1));
		
		int count = 0;
		bool chk = true;
		if (player_attack > monsters_defense)
		{
			while (1)
			{
				count++;
				monsters_hp -= (player_attack - monsters_defense);
				if (monsters_hp <= 0)break;
				player_hp -= (monsters_attack - player_defense);
				if (player_hp <= 0)
				{
					chk = false;
					break;
				}
				player_hp = temp;
			}
			if (chk)
			{
				double _result = double(monsters_exp) / count;
				
				if (result.first < _result)
				{
					result.first = _result;
					result.second = monsters_exp;
					answer = monsters_name;
				}
				else if (result.first == _result)
				{
					if (result.second < monsters_exp)
					{
						result.first = _result;
						result.second = monsters_exp;
						answer = monsters_name;
					}
				}
			}
		}
		
		player_hp = temp;
		
	}

	

	return answer;
}