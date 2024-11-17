#include <vector>
#include <random>
#include <iostream>

using namespace std;

void shuffle_data(vector<vector<double>> &data, vector<double> &label, double seed)
{
	srand(seed);
	int n = label.size();
	for (int i = 0; i < n; i++)
	{
		int j = rand() % n;
		swap(data[i], data[j]);
		swap(label[i], label[j]);
	}
	return;
}

int main()
{
	vector<vector<double>> data = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	vector<double> label = {1, 2, 3};
	// cout
	cout << "Before shuffle:" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << data[i][j] << " ";
		cout << label[i] << endl;
	}

	shuffle_data(data, label, 0);
	// cout
	cout << "After shuffle:" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << data[i][j] << " ";
		cout << label[i] << endl;
	}
	return 0;
}