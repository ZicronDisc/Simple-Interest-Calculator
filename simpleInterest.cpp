#include <iostream>
#include <cmath>
using namespace std;

class finance {
public:
	char userInput[1]{};
	double components[4]{};

	bool letterE() {
		return userInput[0] != 'E' && userInput[0] != 'e';
	}
	bool letterS() {
		return userInput[0] == 'S' || userInput[0] == 's';
	}
	bool letterB() {
		return userInput[0] == 'B' || userInput[0] == 'b';
	}
	bool compError() {
		return components[0] == NULL || components[1] == NULL || components[2] == NULL || components[3] == NULL;
	}

	int finalValue() {
		components[3] = 1;
		if (compError()) {
			invalid();
		}
		else {
			double computation = components[0] * (1 + (components[1] / 100) * components[2]);
			cout << "FINAL AMOUNT: PHP " << round(computation * 100) / 100 << endl << endl;
		}		
		return 0;
	};
	int origValue() {
		components[0] = 1;
		if (compError()) {
			invalid();
		}
		else {
			double computation = components[3] / (1 + (components[1] / 100) * components[2]);
			cout << "PRINCIPAL AMOUNT: PHP " << round(computation*100)/100 << endl << endl;
		}
		return 0;
	};
	int rateValue() {
		components[1] = 1;
		if (compError()) {
			invalid();
		}
		else {
			double computation = (((components[3] / components[0]) - 1) / components[2]) * 100;
			cout << "RATE: " << round(computation*100)/100 << "%" << endl << endl;
		}		
		return 0;
	}
	int termValue() {
		components[2] = 1;
		if (compError()) {
			invalid();
		}
		else {
			double computation = (((components[3] / components[0]) - 1) / (components[1] / 100));

			cout << "TERM: " << round(computation) << " year/s" << endl << endl;
		}
		return 0;
	}

	void invalid() {
		cout << "***ERROR: Cannot determine the answer***\n\n";
	}
	void inputIncorrect() {
		cout << "***ERROR: Incorrect input***\n\n";
	}

	void interest() {
		if (userInput[0] == 'P' || userInput[0] == 'p') {
			cout << "\nRate: ";
			cin >> components[1];
			cout << "Term (years): ";
			cin >> components[2];
			cout << "Final: ";
			cin >> components[3];
			cout << endl;
			origValue();
		}
		else if (userInput[0] == 'R' || userInput[0] == 'r') {
			cout << "\nPrincipal: ";
			cin >> components[0];
			cout << "Term (years): ";
			cin >> components[2];
			cout << "Final: ";
			cin >> components[3];
			cout << endl;
			rateValue();
		}
		else if (userInput[0] == 'T' || userInput[0] == 't') {
			cout << "\nPrincipal: ";
			cin >> components[0];
			cout << "Rate: ";
			cin >> components[1];
			cout << "Final: ";
			cin >> components[3];
			cout << endl;
			termValue();
		}
		else if (userInput[0] == 'F' || userInput[0] == 'f') {
			cout << "\nPrincipal: ";
			cin >> components[0];
			cout << "Rate: ";
			cin >> components[1];
			cout << "Term (years): ";
			cin >> components[2];
			cout << endl;
			finalValue();
		}
		else {
			inputIncorrect();
		}
	}
};

int main() {

	finance f;

	while (f.letterE()) {

		cout << "---Simple Interest Calculator---\n";
		cout << "[S] - Start\n";
		cout << "[E] - Exit\n";
		cin >> f.userInput;

		if (f.letterS()) {
		
			cout << "---What do you want to calculate?---\n";
			cout << "[P] - Principal Amount\n";
			cout << "[R] - Rate\n";
			cout << "[T] - Term (years)\n";
			cout << "[F] - Final Amount\n";
			cout << "[B] - Back\n";
			cin >> f.userInput;

			if (!f.letterB()) {
				f.interest();
			}
			else {
				continue;
			}

		}
		else if (f.letterE()) {
			f.inputIncorrect();
		}

	}

	cout << "End of program\n";

	return 0;
}

