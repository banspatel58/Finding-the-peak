// peak.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <stdexcept>

int findPeak(std::vector<int> v1, int begin, int end){
	
	int peak;
	int middleValue;
	
	try {
		
		middleValue = floor((begin + end) / 2);
				
		// Best case: only one element hence a peak value.	
		if(begin == end){
			
			peak = begin;
			
		} 
		// if there are two elements and the second element is greater than the first one
		else if((end == begin + 1) && (v1.at(end) > v1.at(begin))){
			
			//second element is the peak
			peak = end;
			
		}
		// if there are two elements and the second element is greater than the first one
		else if((end == begin + 1) && (v1.at(end) <= v1.at(begin))){
			
			//first element is the peak
			peak = begin;
			
		}		
		// Best case: middle value is greater than the element before and element after it.
		else if((v1.at(middleValue - 1) < v1.at(middleValue)) && (v1.at(middleValue + 1) < v1.at(middleValue))){
			
			//Case 1: MiddleValue - 1 < MiddleValue > MiddleValue + 1
			peak = middleValue;
			
		} 
		// middle value is greater than value before and is less than the value after
		else if ((v1.at(middleValue - 1) < v1.at(middleValue)) && (v1.at(middleValue + 1) > v1.at(middleValue))){
			
			//Case 2: MiddleValue - 1 < MiddleValue < MiddleValue + 1
			return findPeak(v1, middleValue, end);
			
		}
		// middle value is less than the value before and is greater than value after
		else if ((v1.at(middleValue - 1) > v1.at(middleValue)) && (v1.at(middleValue + 1) < v1.at(middleValue))){
			
			//Case 3: MiddleValue - 1 > MiddleValue > MiddleValue + 1
			return findPeak(v1, begin, middleValue);		
			
		} 
		
	} catch (const std::out_of_range& oor) {
		
		peak = middleValue;
		//std::cerr << "Out of Range error: " << oor.what() << '\n';
		
	}
	
	return peak;
	
}

int main() {
	
	// read the data text file
	std::ifstream in_stream;
	in_stream.open("peak.txt");

	if (in_stream.fail()) {

		std::cout << "File doesn't exist" << std::endl;
		exit(1);

	}
	
	// vector to save data
	int number;
	std::vector<int> data;
	while (in_stream >> number) {

		data.push_back(number);

	}
	// close the file
	in_stream.close();

	int result;
	int length = data.size();
	
	// find the peak values
	result = findPeak(data, 0, length);
	
	// display the results
	std::cout << "Peak index: " << result << std::endl;
	std::cout << "Peak value: " << data.at(result) << std::endl;

	return 0;
}