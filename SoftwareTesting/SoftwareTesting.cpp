#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

static void manipulateVector(vector<int>& vec, ostream& output = std::cout) {
	// Check if the vector is empty
	if (vec.empty()) {
		output << "Vector is empty. Nothing to manipulate." << endl;
		return;
	}

	// Add 10 to each element of the vector
	for (int& num : vec) {
		num += 10;
	}

	// Remove duplicates
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	// Reverse the vector
	reverse(vec.begin(), vec.end());

	// Print the modified vector
	output << "Modified vector: ";
	for (int num : vec) {
		output << num << " ";
	}
	output << endl;

	// Calculate the sum of the elements
	int sum = 0;
	for (int num : vec) {
		sum += num;
	}
	output << "Sum of the elements: " << sum << endl;

	// Find the maximum element
	int maxElement = *max_element(vec.begin(), vec.end());
	output << "Maximum element: " << maxElement << endl;

	// Find the minimum element
	int minElement = *min_element(vec.begin(), vec.end());
	output << "Minimum element: " << minElement << endl;

	// Calculate the average
	double average = static_cast<double>(sum) / vec.size();
	output << "Average of the elements: " << average << endl;

	// Count the number of even and odd numbers
	int numEven = 0, numOdd = 0;
	for (int num : vec) {
		if (num % 2 == 0) {
			numEven++;
		}
		else {
			numOdd++;
		}
	}
	output << "Number of even numbers: " << numEven << endl;
	output << "Number of odd numbers: " << numOdd << endl;
}


int main()
{
	//example use:
	vector<int> v{ 1, 1, -35544, -846, 8, 8, 43689214, 0, 8, -245667, 0 };
	//manipulateVector(v);
	// 
	//example use to store "console" output as a string
	stringstream storage;
	manipulateVector(v, storage);
	cout << storage.str();
}