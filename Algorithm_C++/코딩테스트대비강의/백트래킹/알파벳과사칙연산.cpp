#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

int n;
// a b c d e f
string s;
vector<int> mapper;
int ans = INT_MIN;
int calc(char oper, int result, int num)
{
    if (oper == '+')
        return result + num;
    else if (oper == '-')
        return result - num;
    else
        return result * num;
}
int chk()
{
    int result = mapper[s[0] - 'a'];
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == '+')
            result = calc('+', result, mapper[s[i + 1] - 'a' ]);
        else if (s[i] == '-')
            result = calc('-', result, mapper[s[i + 1] - 'a' ]);
        else if (s[i] == '*')
            result = calc('*', result, mapper[s[i + 1] - 'a' ]);
    }
    return result;
}
void Comb(int count)
{
    if (count == 6)
    {
        ans = max(ans, chk());
        return;
    }
    for (int i = 1; i <= 4; i++)
    {
        mapper.push_back(i);
        Comb(count + 1);
        mapper.pop_back();
    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin >> s;
    Comb(0);
    cout << ans << "\n";
    return 0;
}