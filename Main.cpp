#include<iostream>
#include<vector>
#include<string>

float round2(float var)
{
	float value = (int)(var * 100 + .5);
	return (float)value / 100;
}

float sturgesApproxForm(int n) {
	return 1 + 3.322 * log10(n);
}

int range(int min, int max) {
	return max - min;
}

int main() {
	int n;

	std::cout << "FTD GENERATOR\n\nEnter Data Size:  ";
	std::cin >> n;


	//Gets data size from user
	std::cout << "Your Data Size is " << n << std::endl << "Enter your Raw Data:\n";

	std::vector<int> data(n);


	//Gets raw data from user
	for (int i = 0; i < n; i++) {
		std::cin >> data[i];
	}


	//Initializes minimum value
	int min = data[0];

	for (int i = 1; i < n; i++) {
		if (data[i] < min ) {
			min = data[i];
		}
	}


	//Initializes maximum value
	int max = data[0];

	for (int i = 1; i < n; i++) {
		if (data[i] > max) {
			max = data[i];
		}
	}
	

	std::cout << "Maximum data is " << max << " and minimum data is " << min << std::endl;

	int R = range(min, max);
	std::cout << "The range of your data is: " << R << std::endl;

	float K = round2(sturgesApproxForm(n));
	std::cout << "The number of classes is: " << K << std::endl;
	
	//Calculates Class Size
	float C = R / K;
	C = std::round(C);

	std::cout << "Approximate class size: " << C << std::endl;


	//Intervals counter
	int intervalCounter = min + (C-1);
	while (intervalCounter < max) {
		intervalCounter += C;
	}

	std::cout << "Interval Counter: " << intervalCounter << std::endl;

	int intervalMultiplier = (intervalCounter - (min - 1)) / C;

	std::cout << "Interval Multiplier: " << intervalMultiplier << std::endl;


	//TALLYING MWAHAHAHA, FUCK GIVING YOU MY 100 AND, MORE IMPORTANTLY, MY PRIDE
	std::vector<int> tally(intervalMultiplier);
	for (int i = 0; i < n; i++) {
		for (int j = 0, k = 1; j < intervalMultiplier + 0; j++, k++) {
			if (data[i] >= (j * C + min) && data[i] < (k * C + min)) {
				tally[j]++;
			}
		}
	}
	for (int i = 0, j=1; i < intervalMultiplier; i++, j++) {
		std::cout << i * C + min << " - " << (j * C + min) - 1 << "   -   " << tally[i] << std::endl;
	}

	return 0;
}
