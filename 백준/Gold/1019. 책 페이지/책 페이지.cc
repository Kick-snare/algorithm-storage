#include<iostream>
#include<string>
using namespace std;

int arr[10] = { 0, };
int start = 1;
long long temp = 1;

void Cal_count(int num) {
	while (num != 0) {
		arr[num % 10] += temp;
		num /= 10;
	}
}

int main() {
	int final;
	cin >> final;

	while (start <= final) {
		while (start % 10 != 0 && start <= final) 
			Cal_count(start++);

		if (start > final) break;

		while (final % 10 != 9 && start <= final)
			Cal_count(final--);

		start /= 10;
		final /= 10;
		
		for (int i = 0; i < 10; i++)
			arr[i] += (final - start + 1) * temp;
		temp *= 10;
	}

	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	return 0;
}