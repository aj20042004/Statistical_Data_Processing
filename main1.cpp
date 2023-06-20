// Defining Modules
#include <iostream>
#include "Dynamic_Array1.h"
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>


using namespace std;


// Creating main function
int main() {

	// Creating input and output variables
	ifstream fin("data.txt");
	ofstream fout("results.txt");

	// Checking Whether the file is opening or not 
	if (!fin) {

		cout << "Sorry! Cannot open the file" << endl;
		system("pause");
		return -1;
	}

	// Defining class object here 
	Dynamic_Array array_x , array_y;

	// Defining variables with appropriate data type 
	string line;
	double x_val, y_val;   
	int count = 0;

	// Reading the entire line 
	while (getline(fin, line)) {

		// Checking whether line is empty or not
		if ( !line.empty()) {

			istringstream iss(line);
			if (iss >> x_val >> y_val) {

				// Adding x and y values in array
				array_x.push_back(x_val);
				array_y.push_back(y_val);
				count++;
			}
		
		}	
	
	}

	// Writing the data to output file 
	fout << "Number of x-y pairs read: " << count << endl;                                               // Displaying the total pair counts
	fout << " " << endl;
	fout << "Algebraic average of x: " << fixed << setprecision(4) << array_x.Avg(array_x) << endl;     // Displaying averages of x values
	fout << "Algebraic average of y: " << fixed << setprecision(4) << array_y.Avg(array_y) << endl;     // Displaying averages of y values 
	fout << "Standard deviation of x: " << array_x.Standard_Deviation(array_x) << endl;                  // Displaying standard deviation of x values
	fout << "Standard deviation of y: " << array_y.Standard_Deviation(array_y) << endl;                  // Displaying standard deviation of x values

	fout << " " << endl;

	fout << "Correlation coefficient: " << array_x.Corr_Coeff(array_x, array_y) << endl;                 // Displaying Correlation coefficient
	fout << " " << endl;
	fout << "Linear fitting function:" << endl;                                                          // Displaying linear fitting
	fout << " " << endl;

	// defining slope and intercept variables for Best fit line
	double slope, intercept;

	array_x.Best_Fit_Line(array_x, array_y, slope, intercept);
	fout << "y =" << slope << "x + " << intercept << endl;                                               // Displaying in y = mx + b form 
	fout << " " << endl;
	fout << "Slope: " << slope << endl;                                                                  // Displaying slope 
	fout << "Intercept: " << intercept << endl;                                                          // Displaying intercept
		 

	// Closing all the input and output file
	fin.close();
	fout.close();

	system("pause");
	return 0;

}