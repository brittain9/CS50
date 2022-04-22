#include <iostream>

int main(void)
{
	//n llamas
	int n = 36;
	printf("There exists a population of %i llamas.\n", n);
	//n/3 llamas are born
	const double BIRTH_RATE = n / 3;
	//n/4 llamas die
	const double DEATH_RATE = n / 4;

	printf("The llama birth rate is %.2f.\nThe llama death rate is %.2f\n", BIRTH_RATE, DEATH_RATE);
	//time it takes to have x llamas.
	double delta{ BIRTH_RATE - DEATH_RATE };
	printf("Delta: %.2f\n", delta);


	int desiredPop{ 0 };
	
	do
	{
		printf("Enter the amount of llamas to compute the time required: ");
		std::cin >> desiredPop;
	}
	while (desiredPop < n);

	int difference{ desiredPop - n };

	double days{ (double)difference / delta };
	printf("The amount of days required to grow from population %i to %i is %.2f.", n, desiredPop, days);

}