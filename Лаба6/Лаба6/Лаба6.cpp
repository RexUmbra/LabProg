#include <iostream>
#include <vector>
using namespace std;

void print(vector <vector<double>> vec)
{
	int n = vec.size();
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
			cout << vec[i][j] << ' ';
		cout << '\n';
	}
}
void print(vector<double> vec)
{
	int n = vec.size();
	for (int i = 1; i < n; i++)
		cout << vec[i] << ' ';
	cout << '\n';
}
void writeVec(vector<vector<double>> a, vector<double> b)
{
	int n = a.size();
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
			cin >> a[i][j];
		cin >> b[i];
	}
}
void t(vector<vector<double>> a, vector<double> b)
{
	int n = a.size();
	vector<double> x(n);
	vector<double> d(n);
	vector<vector<double>> s(n, vector<double>(n));
	d[1] = (a[1][1] > 0) - (a[1][1] < 0);
}
int main()
{
	int n;
	cin >> n;

	vector<vector<double>> a(n, vector<double>(n));
	vector<double> b(n);
	
}
