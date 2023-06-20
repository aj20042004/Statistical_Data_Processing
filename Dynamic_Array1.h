#ifndef Dynamic_Array1_H
#define Dynamic_Array1_H

#include <iostream>

using namespace std;


// Dynamic array of integers
class Dynamic_Array {

public:
	// Constructors 
	Dynamic_Array();                        // Default constructor 

	Dynamic_Array(const Dynamic_Array&);    // Copy constructor

	//Destructor 
	~Dynamic_Array();

	// Operators 
	const Dynamic_Array& operator =(const Dynamic_Array&);  // Deep copy assignment operator

	double& operator[] (size_t);                               // Subscript opeartor ( lvalue ) 

	const double& operator[] (size_t) const;                   // Subscript operator ( rvalue ) 


	// Class-member functions 
	size_t size() const;        // Returns the size of the array

	bool empty() const;         // Checks whether the array is empty or not

	void push_back(double);        // Inserts an element of the rear end of the array

	// Average function 

	double Avg(const Dynamic_Array&);                                           // Calculating the averages of x and y 

	// Standard deviation function 

	double Standard_Deviation(const Dynamic_Array&);                            // Calculating the Standard deviation 

	// Correlation coefficient function 

	double Corr_Coeff(const Dynamic_Array&, const Dynamic_Array&);              // Calculating Correlation coefficient

	// Best fitting line function 

    void Best_Fit_Line(const Dynamic_Array&, const Dynamic_Array& , double& , double&);         


private:
	// Data fields 
	static const size_t DEFAULT_CAPACITY;   // Default capacity when an empty array is created
	size_t capacity;                        // Stores the maximum capacity of the array
	size_t num_of_items;                    // Stores the number of elements in the array
	double* data;                           // Stores the element in the array 

	// class-member function
	void resize();                          // Doubles the capacity of the array
};


#endif 