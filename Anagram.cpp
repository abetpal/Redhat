// Check Anagram
// Time Complexity : O(n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
#define ll long long
#define lli long long int
using namespace std;

// function to check if two strings are Anagram of each other
bool checkAnagram(string a, string b)
{
    if (a.length() != b.length())
    {
        return false;
    }
    // check if strings are same
    if (a == b)
    {
        return false;
    }
    // Hashmap to store frequency of characters
    unordered_map<char, int> Map;
    // Loop to store frequency of character in string a
    for (int i = 0; i < a.length(); i++)
    {
        Map[a[i]]++;
    }
    // Now loop over String b
    for (int i = 0; i < b.length(); i++)
    {
        // Check if current character already exists in the frequency map of string a
        if (Map.find(b[i]) != Map.end())
        {
            // If the character is present reduce the frequency count of that character by 1
            Map[b[i]] -= 1;
        }
        else
        {
            return false;
        }
    }
    // check in he map if aal key have value 0, if so strings are anagram
    for (auto items : Map)
    {
        if (items.second != 0)
        {
            return false;
        }
    }
    // true if all key are 0
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Taking input of 2 strings
    string a, b;
    cin >> a >> b;
    // check if anagram
    bool ans = checkAnagram(a, b);
    cout << ((ans) ? "True" : "False");
    return 0;
}