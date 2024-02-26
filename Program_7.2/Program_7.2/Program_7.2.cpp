#include <iostream>

using namespace std;

double fun_len(double x, ...);
double square(double x, ...);
double squaren(int n, double x, ...);

int main()
{
	double pos[10][2] = { 
		{1.0, 1.0}, 
		{4.0, 3.0}, 
		{4.0, 1.0}, 
		{1.0, 6.0}, 
		{0.0, 0.0}, 
		{0.0, 0.0}, 
		{0.0, 0.0}, 
		{0.0, 0.0}, 
		{0.0, 0.0}, 
		{0.0, 0.0}};

	cout << "Square of the polygon: " << (double)squaren(4, pos[0][0], pos[0][1], pos[1][0], pos[1][1], pos[2][0], pos[2][1], pos[3][0], pos[3][1]) << endl;
	system("pause");
	return 0;
}

double fun_len(double x, ...)
{
	double len;
	double* nav = &x;

	double x1 = *(nav++);
	double y1 = *(nav++);
	double x2 = *(nav++);
	double y2 = *(nav);

	len = pow(pow(x1 - x2, 2) + pow(y1 - y2, 2), 0.5);

	return len;
}

double square(double x, ...)
{
	double* nav = &x;
	double x1, y1, sq;
	double l1, l2, l3;

	x1 = *(nav++);
	y1 = *(nav++);

	l1 = fun_len(x1, y1, *nav, *(nav + 1));
	l2 = fun_len(x1, y1, *(nav + 2), *(nav + 3));
	l3 = fun_len(*nav, *(nav + 1), *(nav + 2), *(nav + 3));

	double p = (l1 + l2 + l3) * 0.5;

	sq = pow(p * (p - l1) * (p - l2) * (p - l3), 0.5);

	return sq;
}

double squaren(int n, double x, ...)
{
	double* nav = &x;
	double x1, y1, sq = 0;

	x1 = *(nav++);
	y1 = *(nav++);

	for (int i = 1; i <= n - 2; ++i)
	{
		sq += square(x1, y1, *nav, *(nav + 1), *(nav + 2), *(nav + 3));
		nav += 2;
	}

	return sq;
}