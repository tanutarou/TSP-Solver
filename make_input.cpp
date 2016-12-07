#include <iostream>
#include <cstdio>
#include <vector>
#include <random>

int main(void) {
	std::random_device rnd;
	
	int n;
	double w[100][100];
	std::cin >> n;

	std::vector<double> x;
	std::vector<double> y;

	for(int i=0; i<n; i++){
		x.push_back((rnd() % 50) - 25.0);
		y.push_back((rnd() % 50) - 25.0);
	}

	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			if(i == j) w[i][j] = 0;
			else{
				w[i][j] = w[j][i] = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
			}
		}
	}

	printf("%d\n", n);
	printf("dp\n");

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%.3f ", w[i][j]);
		}
		puts("");
	}

	for(int i=0; i<n; i++){
		printf("%.3f %.3f\n", x[i], y[i]);
	}

	return 0;
}
