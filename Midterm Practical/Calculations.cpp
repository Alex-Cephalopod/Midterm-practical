#include "Calculations.h"

int Calculations::result(int corrects)
{
	double result = (double)corrects / 4.0;

	if (result == 0.25)
		return 25;
	else if (result == 0.5)
		return 50;
	else if (result == 0.75)
		return 75;
	else
		return 100;
}
