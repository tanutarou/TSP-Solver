#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <bits/stdc++.h>

const long long INF = 1000000000ll;

std::pair<double, std::vector<int>> memo[20][1<<20];

class TSP{
	public:
		int n;
		double w[1000][1000];
		std::vector<int> ans;
		double opt;

		TSP(int N){
			n = N;	
			opt = INF;
			for(int i=0; i<N; i++){
				for(int j=0; j<N; j++){
					double t;
					std::cin >> t;
					w[i][j] = t;
				}
			}

			for(int i=0; i<N; i++){
				for(int j=0; j<(1<<N);j++){
					memo[i][j].first = -1;
				}
			}
		}

		void brute(){
			std::vector<int> v;
			for(int i=0; i<n; i++){
				v.push_back(i);
			}
			do{
				double c = cost(v);
				if(opt > c){
					opt = c;
					ans = v;
				}
			}while(next_permutation(v.begin(), v.end()));
		}

		void dp(){
			auto ret = dp_core(0, 1);
			opt = ret.first;
			ans = ret.second;
			ans.push_back(0);
			reverse(ans.begin(), ans.end());
		}

		std::pair<double, std::vector<int>> dp_core(int now, int mask){
			if(memo[now][mask].first != -1){
				return memo[now][mask];
			}
			if(mask == (1 << n) - 1){
				std::vector<int> v;
				return make_pair(w[now][0], v);
			}

			double ret = INF;
			int idx;
			std::vector<int> v;
			for(int i = 0; i < n; i++){
				if(mask & (1 << i)){
					continue;
				}else{
					auto p = dp_core(i, mask | (1 << i));
					double c = w[now][i] + p.first;
					if(ret > c){
						ret = c;
						idx = i;
						v = p.second;
					}
				}
			}
			v.push_back(idx);

			return memo[now][mask] = make_pair(ret, v);
		}

		void solve(std::string method){
			if(method == "brute"){
				brute();
			}else if(method == "dp"){
				dp();
			}

			return;
		}

		double cost(std::vector<int> v){
			double ret = 0;
			for(int i=0; i<v.size(); i++){
				if(i == v.size()-1) ret += w[v[i]][v[0]];
				else ret += w[v[i]][v[i+1]];
			}
			return ret;
		}

		void output(){
			for(int i=0; i<ans.size(); i++){
				printf("%d ", ans[i]);
			}
			puts("");

			printf("min cost = %.5f\n", opt);
		}
};

int main(void) {
	int n;
	std::string method;
	std::cin >> n;
	std::cin >> method;
	TSP tsp = TSP(n);

	tsp.solve(method);
	tsp.output();

	return 0;
}

