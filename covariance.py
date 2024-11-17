def calculate_covariance_matrix(vectors: list[list[float]]) -> list[list[float]]:
	covariance_matrix = [[0 for _ in range(len(vectors))] for _ in range(len(vectors))]
	for i in range(len(vectors)):
		for j in range(len(vectors)):
			covariance_matrix[i][j] = covar(vectors[i], vectors[j])
			covariance_matrix[j][i] = covar(vectors[i], vectors[j])
	return covariance_matrix

def covar(vector1, vector2):
	ret = 0
	n = len(vector1)
	vector1 = [vector1[i] - (sum(vector1)/n) for i in range(n)]
	vector2 = [vector2[i] - (sum(vector2)/n) for i in range(n)]
	for i in range(n):
		ret +=	vector1[i]*vector2[i]
	return ret/(n-1)


if __name__ == "__main__":
	vectors = [[1, 2, 3], [1, 2, 3], [1, 2, 3]]
	print(calculate_covariance_matrix(vectors))

