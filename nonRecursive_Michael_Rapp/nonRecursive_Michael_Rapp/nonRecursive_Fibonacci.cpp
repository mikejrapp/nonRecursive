/*
	CS 2420 Utah Valley University
	nonRecursive_Fibonacci.cpp
	Purpose: Takes input from data file and outputs the number in the 
			 position of the fibonacci sequence of the number input.
	Author: Michael Rapp
	Date: 8/28/2016
*/

#include<string>
#include<iostream>
#include<fstream>

using namespace std;

int fibonacci(int num);
bool openFile(ifstream &inFile);

int main() {
	int num;
	ifstream inFile;

	if (openFile(inFile)) {
		cout << "The file outputs:" << endl;
		while (!inFile.eof()) {
			inFile >> num;
			cout << num << " ---> " << fibonacci(num) << endl;
		}

		inFile.close();
	}
	else {
		cout << "File not found! Program terminates.";
	}

	cin.ignore();
	cin.get();
	return 0;
}

int fibonacci(int num) {
	/*
		This function outputs the number in the fibonacci sequence at position "num"
	*/

	int loopCounter = num;
	int base = 0;
	int adder = 1;
	int answer;

	if (num <= 0) {
		return 0;
	}

	if (num <= 2) {
		return 1;
	}

	if (num > 2){
		while (loopCounter > 1) {
			if (base <= 2) {
				answer = base + adder;
				//since the adder will remain one until the answer becoms 3 there is no need to update the adder.
				if (answer < 3) {
					//this prevents the base, adder and answer from all becoming three.
					base = answer;
				}//end if answer < 3
					
			}//end if base <= 2

			if (answer >= 3) {
				//once answer becomes three the logic changes a bit. The adder will now hold the number that precedes the base before the
				//arithmetic begins.
				adder = base;
				base = answer;
				answer = base + adder;
			}//end if answer >= 3

			loopCounter--;
		}//end while 
	}//end if num > 2
	
	return base; //since the base is the actual working position in the sequence this should be returned rather than answer.
}

bool openFile(ifstream & inFile) {
	/*
		This function takes the filepath entered by the user and esures the file
		exists. If file is opened returns true, else false.
	*/
	string filePath;

	cout << "please enter the file path including the file extension ";
	cin >> filePath;

	inFile.open(filePath);

	if (!inFile) {
		return false;
	}
	else {
		return true;
	}
}

