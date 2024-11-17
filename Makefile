covar_matrix: covariance.cc
	g++ -o covar_matrix covariance.cc

test: covar_matrix
	./covar_matrix < test.in