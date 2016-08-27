#include<string>
#include<iostream>
#include<fstream>

using namespace std;

int fibonacci(int num);

int main() {

	cout << fibonacci(5);

	cin.ignore();
	cin.get();
	return 0;
}

int fibonacci(int num) {
	int loopCounter = num;
	int fibNum;

	if (num == 0) {
		return 0;
	}
	else if (num == 1) {
		return 1;
	}
	else if (num >= 2){
		
		while (loopCounter > 0) {
			fibNum = (num - 1) + (num - 2);
			loopCounter--;
		}

		return fibNum;
	}
	else {
		return 0;
	}
}

