#include <bits/stdc++.h>
#define ll long long
#define lli long long int
using namespace std;

vector<vector<int>> ans;
// Function to create all possible combination
void solve(int i, string &s, int sum, vector<int> &dum)
{
    if (i >= s.size())
    {
        // Checking if the formed combination adds upto 100
        if (sum == 100)
            ans.emplace_back(dum);
        return;
    }
    // Taking one digit numbers at a time
    int one = s[i] - '0';
    // Adding the number taken
    dum.push_back(one);
    solve(i + 1, s, sum + one, dum);
    dum.pop_back();
    // Subtracting the number taken
    if (sum != 0)
    {
        dum.push_back(-one);
        solve(i + 1, s, sum - one, dum);
        dum.pop_back();
    }
    // Taking 2 digit numbers at a time
    if (i < s.size() - 1)
    {
        int two = (s[i] - '0') * 10 + (s[i + 1] - '0');
        // Adding the number taken
        dum.push_back(two);
        solve(i + 2, s, sum + two, dum);
        dum.pop_back();
        // Subtracting the number taken
        dum.push_back(-two);
        solve(i + 2, s, sum - two, dum);
        dum.pop_back();
    }
    // Taking 3 digit numbers at a time
    if (i < s.size() - 2)
    {
        int three = (s[i] - '0') * 100 + (s[i + 1] - '0') * 10 + (s[i + 2] - '0');
        // Adding the number taken
        dum.push_back(three);
        solve(i + 3, s, sum + three, dum);
        dum.pop_back();
        // Subtracting the number taken
        dum.push_back(-three);
        solve(i + 3, s, sum - three, dum);
        dum.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string input = "123456789";
    vector<int> dum;
    solve(0, input, 0, dum);
    // print all possible combination except the first one
    for (int i = 1; i < ans.size(); i++)
    {
        cout << ans[i][0];
        for (int j = 1; j < ans[i].size(); j++)
            cout << ((ans[i][j] > 0) ? "+" : "") << ans[i][j];
        cout << "\n";
    }
    return 0;
}