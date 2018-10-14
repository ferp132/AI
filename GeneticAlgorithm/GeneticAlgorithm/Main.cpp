#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

#include "Population.h"

using namespace std;

int main(void)
{
	Population pop(10, 1, "Hello There General Kenobi");

	pop.Init();
	pop.ProcessGenAlg();



	cin.get();
	return 0;
}