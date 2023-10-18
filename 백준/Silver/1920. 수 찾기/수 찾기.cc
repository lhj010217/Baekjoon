#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[100000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n1;
	int n2;
	scanf("%ld", &n1);
	for (int i = 0; i < n1; i++) {
		scanf("%ld", &arr[i]);
	}
	sort(arr, arr+n1);
	scanf("%ld", &n2);
	for (int i = 0; i < n2; i++) {
		int target = 0;
		scanf("%ld", &target);
		if (binary_search(arr, arr + n1, target)) printf("1\n");
		else printf("0\n");
	}
}