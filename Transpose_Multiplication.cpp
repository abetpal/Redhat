// Time Complexity : O(n^3)
#include <bits/stdc++.h>
#define ll long long
#define lli long long int
using namespace std;
// function to find transpose ofa given matrix
void transpose(vector<vector<int>> &A)
{
    int N = A.size();
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            swap(A[i][j], A[j][i]);
}

// function to multiply to matrices
vector<vector<int>> matrixMultiplication(vector<vector<int>> &A, vector<vector<int>> &B)
{
    int N = A.size();
    vector<vector<int>> result(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

// main function
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // input of number of rows and column
    int N;
    cin >> N;

    vector<vector<int>> A(N, vector<int>(N, 0)), B(N, vector<int>(N, 0));
    // input of matrix A
    for (auto &i : A)
    {
        for (int &j : i)
            cin >> j;
    }
    // Input of matrix B
    for (auto &i : B)
    {
        for (int &j : i)
            cin >> j;
    }

    // (B*A)' = A' * B'
    vector<vector<int>> ans = matrixMultiplication(B, A);
    transpose(ans);

    // Printing answer matrix
    for (auto &i : ans)
    {
        for (int &j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}