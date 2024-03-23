// SoftwareTesting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static void manipulateVector(vector<int>& vec) {
	// Check if the vector is empty
	if (vec.empty()) {
		cout << "Vector is empty. Nothing to manipulate." << endl;
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
	cout << "Modified vector: ";
	for (int num : vec) {
		cout << num << " ";
	}
	cout << endl;

	// Calculate the sum of the elements
	int sum = 0;
	for (int num : vec) {
		sum += num;
	}
	cout << "Sum of the elements: " << sum << endl;

	// Find the maximum element
	int maxElement = *max_element(vec.begin(), vec.end());
	cout << "Maximum element: " << maxElement << endl;

	// Find the minimum element
	int minElement = *min_element(vec.begin(), vec.end());
	cout << "Minimum element: " << minElement << endl;

	// Calculate the average
	double average = static_cast<double>(sum) / vec.size();
	cout << "Average of the elements: " << average << endl;

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
	cout << "Number of even numbers: " << numEven << endl;
	cout << "Number of odd numbers: " << numOdd << endl;
}


int main()
{
	//example use:
	vector<int> v;
	v.push_back(27363627);
	manipulateVector(v);
}