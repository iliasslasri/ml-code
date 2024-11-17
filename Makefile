covar_matrix: covariance.cc
	g++ -o covar_matrix covariance.cc

test: covar_matrix
	./covar_matrix < test.in

shuflle: shuflle_data.cc
	g++ -o shuflle shuflle_data.cc
	./shuflle
