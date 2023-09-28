#include <iostream>

#include "Array.h"

double calculateAvg(Array arr)
{
	double avg = 0;
	for (int i = 0; i < arr.size(); ++i) {
		avg += arr[i];
	}
	avg /= arr.size();
	return avg;
}

int main()
{
	Array arr(10, 0);
	int a = arr[3];
	std::cout << arr[3] << ' ' << arr[9] << std::endl;
	arr[3] = 16;
	arr[5] = arr[3];
	std::cout << "Среднее значение: " << calculateAvg(arr) << '\n';
	arr.print();

	getchar();
	return 0;
}
