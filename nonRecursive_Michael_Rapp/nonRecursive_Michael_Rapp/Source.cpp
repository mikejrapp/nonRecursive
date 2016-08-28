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
	int base = 0;
	int adder = 1;
	int answer;

	while (loopCounter > 0) {
		if (base <= 2) {
			answer = base + adder;
			//since the adder will remain one until the answer becoms 3 there is no need to update the adder.
			if(answer < 3)
				//this prevents the base, adder and answer from all becoming three.
				base = answer;
		}
		if (answer >= 3) {
			//once the answer becomes three the logic changes a bit. The adder will now hold the number that preceeds the base before the
			//arithmetic begins.
			adder = base;
			base = answer;
			answer = base + adder;
		}
		loopCounter--;
	}

	return answer;
}

