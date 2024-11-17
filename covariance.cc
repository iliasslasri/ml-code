#include <vector>
#include <iostream>

using namespace std;

double covar(vector<double>, vector<double>);
vector<vector<double>> compute_covariance_matrix(vector<vector<double>> v)
{
	vector<vector<double>> cov_matrix = vector<vector<double>>(v.size(), vector<double>(v.size(), 0));
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			cov_matrix[i][j] = covar(v[i], v[j]);
			cov_matrix[j][i] = covar(v[i], v[j]);
		}
	}
	return cov_matrix;
}

double covar(vector<double> v1, vector<double> v2)
{
	double ret = 0;
	int n = v1.size();
	double mean_v1 = 0;
	double mean_v2 = 0;
	for (int i = 0; i < n; i++)
	{
		mean_v1 += v1[i];
		mean_v2 += v2[i];
	}
	mean_v1 /= n;
	mean_v2 /= n;

	for (int i = 0; i < n; i++)
	{
		ret += (v1[i] - mean_v1) * (v2[i] - mean_v2);
	}
	return ret / (n - 1);
}

int main()
{
	vector<vector<double>> vectors;
	vector<double> v;
	double in;
	// size of vector
	int n;
	// number of vectors
	int v_n;
	cin >> n;
	cin >> v_n;

	while (v_n--)
	{
		v.clear();
		for (int i = 0; i < n; i++)
		{
			cin >> in;
			v.push_back(in);
		}
		vectors.push_back(v);
	}
	vector<vector<double>> cov_matrix = compute_covariance_matrix(vectors);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << cov_matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}