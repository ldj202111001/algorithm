#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int get_gcd(int min, int max) {		// 최대공약수 구하기 (유클리드 호제법)
	int remainder = 1;
	while (remainder != 0) {
		remainder = max % min;
		max = min;
		min = remainder;
	}
	return max;
}

int get_lcm(int min, int max) {		// 최소공배수 구하기  (최소공배수를 이용해 구한다.)
	return min * max / get_gcd(min, max);
}

int main()
{
	int a, b, min, max;
	printf("정수 2개입력: ");
	scanf("%d %d", &a, &b);

	if (a > b) {
		max = a;
		min = b;
	}
	else {
		max = b;
		min = a;
	}

	printf("최대공약수: %d\n", get_gcd(min, max));
	printf("최소공배수: %d", get_lcm(min, max));
}
