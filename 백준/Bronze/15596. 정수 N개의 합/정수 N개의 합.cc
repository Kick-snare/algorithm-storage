#include <vector>
long long sum(std::vector<int> &a) {
	long long ans = 0;
    for(auto &w : a) ans+=w;
	return ans;
}
