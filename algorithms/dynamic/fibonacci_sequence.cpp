#include <iostream>

int fib(int n) {
	if (n <= 1) return n;
	return fib(n - 1) + fib(n - 2);
}


#include <vector>
int better_fib(int n) {
	static std::vector<int> ans(n + 1, 0);
	if (n <= 1) return n;
	if (ans[n] == 0) ans[n] = better_fib(n - 1) + better_fib(n - 2);
    return ans[n];
}

int bottom_up_fib(int n) {
	std::vector<int> ans(n + 1, 0);
	ans[0] = 0; ans[1] = 1;
	for (int i = 2; i <= n; ++i) {
		ans[i] = ans[i - 1] + ans[i - 2];
	}
	return ans[n];
}

int main() {
    std::cout << bottom_up_fib(40);
}
