#include <iostream>

using namespace std;

void Swap(int Array[], int a, int b)
{
	int Temp = Array[a];
	Array[a] = Array[b];
	Array[b] = Temp;
}

int main(void)
{
	int wait;
	const int ArrSize = 5;
	int Vals[ArrSize] = { 0, 1, 2, 3 , 4};

	int LargestI = 0;
	int LargestJ = 0;
	int It = 0;

	while (LargestI != -1)
	{
		It++;
		//STEP 1:
		LargestI = -1;
		LargestJ = -1;

		for (int i = 0; i < ArrSize; i++)
		{
			cout << Vals[i] << " ";
		}
		cout << " - " << It << endl;

		for (int i = 0; i < ArrSize - 1; i++)
		{
			if (Vals[i] < Vals[i + 1]) LargestI = i;
		}

		if (LargestI == -1)
		{
			cout << "Finished";
			break;
		}

		//STEP 2:
		for (int j = 0; j < ArrSize; j++)
		{
			if (Vals[LargestI] < Vals[j]) LargestJ = j;
		}

		//STEP 3:
		Swap(Vals, LargestI, LargestJ);

		//STEP 4:

		reverse(&Vals[LargestI + 1], end(Vals));
	}


	cin >> wait;
	return 0;
}