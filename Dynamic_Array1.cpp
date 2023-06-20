// Defining modules
#include "Dynamic_Array1.h"
#include <cmath>
#include <iostream>

using namespace std;

// Default capacity 
const size_t Dynamic_Array::DEFAULT_CAPACITY = 10;


// Default Constructor 
Dynamic_Array::Dynamic_Array() {

	capacity = DEFAULT_CAPACITY;
	num_of_items = 0;
	data = new double[capacity];

}

// Copy constructor 
Dynamic_Array::Dynamic_Array(const Dynamic_Array& other) {

	data = NULL;
	*this = other;

}

// Destructor 
Dynamic_Array::~Dynamic_Array() {

	if (data) { delete[] data; }

}


// Deep-copy assignment operator
const Dynamic_Array& Dynamic_Array::operator = (const Dynamic_Array& other) {

	// Step 1: avoid self-assignment.
	if (this != &other) {

		// Step 2: delete current dynamic memory.
		if (data) {

			delete[] data;
			data = NULL;         // Setting pointer to the safe value "NULL" after deleting.

		}

		// Step 3: copy static data fields.
		capacity = other.capacity;
		num_of_items = other.num_of_items;

		// Step 4: copy dynamic data fields.
		if (num_of_items <= capacity) {
			data = new double[capacity];
			for (size_t i = 0; i < num_of_items; i++) { data[i] = other.data[i]; }
		}
	}

	// Step 5: return.
	return *this;

}


// Subscript operator (lvalue) 
double& Dynamic_Array::operator [] (size_t index) { return data[index]; }


// Subscript opearator (rvalue ) 
const double& Dynamic_Array::operator[] (size_t index) const { return data[index]; }


/** Returns the size of the array.
	@return: size of the array
*/

size_t Dynamic_Array::size() const { return num_of_items; }



/** Tests whether the array is empty.
	@return: {true} if the array is empty; {false} otherwise
*/

bool Dynamic_Array::empty() const {

	return !size();

}


// Doubles the capacity of the array.
void Dynamic_Array::resize() {

	capacity *= 2;
	double* new_data = new double[capacity];
	for (size_t i = 0; i < size(); i++) { new_data[i] = data[i]; } 
	delete[] data;
	data = new_data;

	
}


/** Inserts a new element to the rear end of the array.
	@param value: new element to append to the array
*/

void Dynamic_Array::push_back(double other_value) {

	if (size() == capacity) { resize(); }

	data[num_of_items++] = other_value;


}


/*
    Avg Function to find average 
	@param value: array of x or y values
*/

double Dynamic_Array::Avg(const Dynamic_Array& other) {

	double sum = 0.0;
	for (int i = 0; i < other.size(); i++) {

		sum += other[i];
	}

	return sum / other.size();

}


/*
	Standard_Deviation Function to find standard deviation for x and y values
	@param value: array of x or y values
*/

double Dynamic_Array::Standard_Deviation(const Dynamic_Array& array) {

	double avg = Avg(array);
	double sum = 0;
	for (int i = 0; i < array.size(); i++) {
		sum += (array[i] - avg) * (array[i] - avg);
	}

	return sqrt(sum / array.size());
}


/*
	Corr_Coeff Function to find Correlation coefficient for x and y values
	@param value: array of x and array of y values
*/

double Dynamic_Array::Corr_Coeff(const Dynamic_Array& array1 , const Dynamic_Array& array2) {

	double x_avg = Avg(array1);
	double y_avg = Avg(array2);
	double x_dev = Standard_Deviation(array1);
	double y_dev = Standard_Deviation(array2);
	double sum = 0;
	for (int i = 0; i < array1.size(); i++) {

		sum += (array1[i] - x_avg) * (array2[i] - y_avg);

	}

	return sum / (array1.size() * x_dev * y_dev);

}


/*
	 Best_Fit_Line Function for best fitting slope and intercept in y = mx + b form
	@param value: array of x , array of y values , slope variable , intercept variable
*/

void Dynamic_Array::Best_Fit_Line(const Dynamic_Array& arr_1 , const Dynamic_Array& arr_2 , double& slope, double& intercept) {


	double x_avg_val = Avg(arr_1);
	double y_avg_val = Avg(arr_2);

	double numerator = 0;
	double denominator = 0;

	for (int i = 0; i < arr_1.size(); i++) {

		numerator += (arr_1[i] - x_avg_val) * (arr_2[i] - y_avg_val);
		denominator += (arr_1[i] - x_avg_val) * (arr_1[i] - x_avg_val);

	}

	slope = numerator / denominator;
	intercept = y_avg_val - slope * x_avg_val;

}

