#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int ingredient[27];
int solution(vector<string> ings, vector<string> menu, vector<string> sell) {
    int answer = 0;

    pair<string, int> menuCost[101];

    for (int i = 0; i < ings.size(); i++)
    {
        string ing = ings[i].substr(0, 1);
        int cost = stoi(ings[i].substr(2, ings[i].size()));
        ingredient[ing[0] - '0' - 49] = cost;
    }
    for (int i = 0; i < menu.size(); i++)
    {
        int index = menu[i].find(" ");
        string name = menu[i].substr(0, index);
        string temp = menu[i].substr(index + 1, menu[i].size());
        index = temp.find(" ");
        string ing = temp.substr(0, index);
        int price = stoi(temp.substr(index + 1, temp.size()));
        for (int j = 0; j < ing.size(); j++)
        {
            char in = ing[j];
            price -= ingredient[in - '0' - 49];
        }
        menuCost[i] = make_pair(name, price);
    }
    for (int i = 0; i < sell.size(); i++)
    {
        int index = sell[i].find(" ");
        string name = sell[i].substr(0, index);
        int count = stoi(sell[i].substr(index + 1, sell[i].size()));
        for (int j = 0; j < menu.size(); j++)
        {
            if (menuCost[j].first == name)
            {
                answer += (menuCost[j].second) * count;
                break;
            }
        }
    }


    return answer;
}

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    vector<string> ings, menu, sell;

    ings.push_back("r 10");
    ings.push_back("a 23");
    ings.push_back("t 124");
    ings.push_back("k 9");

    menu.push_back("PIZZA arraak 145");
    menu.push_back("HAMBURGER tkar 180");
    menu.push_back("BREAD kkk 30");
    menu.push_back("ICECREAM rar 50");
    menu.push_back("SHAVEDICE rar 45");
    menu.push_back("JUICE rra 55");
    menu.push_back("WATER a 20");

    sell.push_back("BREAD 5");
    sell.push_back("ICECREAM 100");
    sell.push_back("PIZZA 7");
    sell.push_back("JUICE 10");
    sell.push_back("WATER 1");

    cout << solution(ings, menu, sell) << "\n";
    return 0;
}