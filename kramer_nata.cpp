#include <stdio.h> 
#include <math.h>
#include <windows.h>
#define ARR_SIZE 11

void PrintMatrXY(double mas[5][4]) {
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 5; j++)
			printf("%10.4lf ", mas[j][i]);
		printf("\n");
	}
}

void PrintMatr(double **mas, int m) {
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++)
			printf("%10.4lf ", mas[j][i]);
		printf("\n");
	}
}

void GetMatr(double **mas, double **p, int a, int b, int m) {

	for (int k = 0; k < m - 1; k++)
		for (int d = 0; d < m - 1; d++)
			p[k][d] = 0;
	int di = 0, dj = 0;
	for (int i = 0; i < m - 1; i++)
	{
		if (i == a)di = 1;
		for (int j = 0; j < m - 1; j++)
		{
			if (j == b)dj = 1;
			p[i][j] = mas[i + di][j + dj];
		}
	}
}

double Determinant(double **mas, int  m)
{
	if (m < 1) printf("ERROR");
	if (m == 1) return mas[0][0];
	if (m == 2)	return mas[0][0] * mas[1][1] - mas[1][0] * mas[0][1];
	if (m > 2) {
		int i, j = 0, k = 1;
		double d = 0;

		double **p = new double* [m - 1];
		for (int i = 0; i < 4; i++) p[i] = new double[m - 1];
		for (i = 0; i < m; i++) {
			GetMatr(mas, p, i, 0, m);
			d = d + k * mas[i][0] * Determinant(p, m - 1);
			k = -k;
		}
		return(d);
	}
	return -1;
}

int main(void)
{
	double ARR[2][ARR_SIZE];
	double MAINMATRIX[5][4] = { 0 };
	double **MATRIX = new double*[4];

	double xsumm = 0;
	double ysumm = 0;
	double x2summ = 0;
	double x3summ = 0;
	double x4summ = 0;
	double x5summ = 0;
	double x6summ = 0;
	double xysumm = 0;
	double x2ysumm = 0;
	double x3ysumm = 0;
	
	ARR[0][0] = -2.00;
	ARR[0][1] = -2.50;
	ARR[0][2] = -3.00;
	ARR[0][3] = -3.50;
	ARR[0][4] = -4.00;
	ARR[0][5] = -4.50;
	ARR[0][6] = -5.00;
	ARR[0][7] = -5.50;
	ARR[0][8] = -6.00;
	ARR[0][9] = -6.50;
	ARR[0][10] = -7.00;

	ARR[1][0] = -1.25;
	ARR[1][1] = -2.77;
	ARR[1][2] = -3.72;
	ARR[1][3] = -4.31;
	ARR[1][4] = -5.47;
	ARR[1][5] = -6.34;
	ARR[1][6] = -7.22;
	ARR[1][7] = -8.43;
	ARR[1][8] = -9.67;
	ARR[1][9] = -10.50;
	ARR[1][10] = -11.40;

	for (int i = 0; i < ARR_SIZE; i++)
		printf("x: %10lf y: %10lf \n", ARR[0][i], ARR[1][i]);
	printf("\n");

	for (int i = 0; i < ARR_SIZE; i++)
	{
		xsumm += ARR[0][i];
		ysumm += ARR[1][i];

		x2summ += ARR[0][i] * ARR[0][i];
		x3summ += ARR[0][i] * ARR[0][i] * ARR[0][i];
		x4summ += ARR[0][i] * ARR[0][i] * ARR[0][i] * ARR[0][i];
		x5summ += ARR[0][i] * ARR[0][i] * ARR[0][i] * ARR[0][i] * ARR[0][i];
		x6summ += ARR[0][i] * ARR[0][i] * ARR[0][i] * ARR[0][i] * ARR[0][i] * ARR[0][i];

		xysumm += ARR[0][i] * ARR[1][i];
		x2ysumm += ARR[0][i] * ARR[0][i] * ARR[1][i];
		x3ysumm += ARR[0][i] * ARR[0][i] * ARR[0][i] * ARR[1][i];
	}

	MAINMATRIX[0][0] = ARR_SIZE;
	MAINMATRIX[0][1] = xsumm;
	MAINMATRIX[0][2] = x2summ;
	MAINMATRIX[0][3] = x3summ;

	MAINMATRIX[1][0] = xsumm;
	MAINMATRIX[1][1] = x2summ;
	MAINMATRIX[1][2] = x3summ;
	MAINMATRIX[1][3] = x4summ;

	MAINMATRIX[2][0] = x2summ;
	MAINMATRIX[2][1] = x3summ;
	MAINMATRIX[2][2] = x4summ;
	MAINMATRIX[2][3] = x5summ;

	MAINMATRIX[3][0] = x3summ;
	MAINMATRIX[3][1] = x4summ;
	MAINMATRIX[3][2] = x5summ;
	MAINMATRIX[3][3] = x6summ;

	MAINMATRIX[4][0] = ysumm;
	MAINMATRIX[4][1] = xysumm;
	MAINMATRIX[4][2] = x2ysumm;
	MAINMATRIX[4][3] = x3ysumm;

	PrintMatrXY(MAINMATRIX);
	printf("\n");

	for (int i = 0; i < 4; i++)
	{
		MATRIX[i] = new double[4];
		for (int j = 0; j < 4; j++)
			MATRIX[i][j] = MAINMATRIX[i][j];
	}

	PrintMatr(MATRIX, 4);
	double alfa = Determinant(MATRIX, 4);
	printf("Det: %lf\n\n", alfa);

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			MATRIX[i][j] = MAINMATRIX[i][j];
	for (int j = 0; j < 4; j++)
		MATRIX[0][j] = MAINMATRIX[4][j];
	double d = Determinant(MATRIX, 4) / alfa;
	PrintMatr(MATRIX, 4);
	printf("D: %lf\n\n", d);

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			MATRIX[i][j] = MAINMATRIX[i][j];
	for (int j = 0; j < 4; j++)
		MATRIX[1][j] = MAINMATRIX[4][j];
	double c = Determinant(MATRIX, 4) / alfa;
	PrintMatr(MATRIX, 4);
	printf("C: %lf\n\n", c);

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			MATRIX[i][j] = MAINMATRIX[i][j];
	for (int j = 0; j < 4; j++)
		MATRIX[2][j] = MAINMATRIX[4][j];
	double b = Determinant(MATRIX, 4) / alfa;
	PrintMatr(MATRIX, 4);
	printf("B: %lf\n\n", b);

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			MATRIX[i][j] = MAINMATRIX[i][j];
	for (int j = 0; j < 4; j++)
		MATRIX[3][j] = MAINMATRIX[4][j];
	double a = Determinant(MATRIX, 4) / alfa;
	PrintMatr(MATRIX, 4);
	printf("A: %lf\n\n", a);

	double summ = 0;
	for (int i = 0; i < ARR_SIZE; i++)
	{
		double temp = a * ARR[0][i] * ARR[0][i] * ARR[0][i] + b * ARR[0][i] * ARR[0][i] + c * ARR[0][i] + d;
		printf("|x: %10lf| |y: %10lf| |temp_y: %10lf|\n", ARR[0][i], ARR[1][i], temp);
		summ += (ARR[1][i] - temp)*(ARR[1][i] - temp);
	}

	printf("Delta: %5.3lf%% \n\n", sqrt(summ)*100 / (ARR_SIZE + 1));

	system("pause");
	delete [] MATRIX;
	return 1;
}