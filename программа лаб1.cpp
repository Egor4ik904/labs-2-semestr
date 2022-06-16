#include <stdlib.h>
#include <stdio.h>

#define ABS(num) ((num) > 0 ? (num) : -(num))

double cosine(double x, double eps) {
	double sum;
	double an, sq_x;
	int n;

	sq_x = x * x;

	sum = 0.0;
	n = 0;
	an = 1.0;

	while (ABS(an) >= eps) {
		sum += (n % 2 == 0 ? an : -an);

		n += 1;
		an = an * sq_x / ((2 * n - 1) * 2 * n);
	}

	return sum;
}

int main(void) {
	double x = 0.0, eps = 0.001;

	printf("Input x: ");
	fflush(stdout);
	scanf_s("%lf", &x);

	printf("Input EPS: ");
	fflush(stdout);
	scanf_s("%lf", &eps);

	eps = ABS(eps);
	printf("cos(%lg) = %lg [+- %lg]\n", x, cosine(x, eps), eps);

	return 0;
}