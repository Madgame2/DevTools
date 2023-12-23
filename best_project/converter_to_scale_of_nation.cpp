#include"Header.h"
#include"list.h"
#include<string>
#include <vector>

using namespace std;

void findPos(string &wholePart, string& fraction, size_t& dotPosition) {

	dotPosition = wholePart.find('.');

	if (dotPosition == -1) {
		dotPosition = wholePart.find(',');
	}

	if (dotPosition != -1) {
		fraction += '0';
		fraction += wholePart.substr(dotPosition);
		wholePart.erase(dotPosition);
	}
}

void initialiseVector(string wholePart, vector<int>& decNumbers, int size) {

	for (int i = 0; i < size; i++) {
		decNumbers.push_back((stoi(wholePart.substr(i, 1))));
	}
}

void initialiseVectorHex(string wholePart, vector<int>& decNumbers, int size) {

	for (int i = 0; i < size; i++) {
		decNumbers.push_back(hexToIntNumbers[wholePart.substr(i, 1)]);
	}
}

String intToBin(String value) {

	string wholePart = value.toAnsiString();
	string fraction;
	size_t dotPosition;
	long long int number;
	long double fractionNumber;
	int occurasity; //число знаков

	occurasity = 10;

	findPos(wholePart, fraction, dotPosition);

	if (wholePart[0] == '-') {

		number = stoll(wholePart);
		wholePart.clear();

		if (number != 0) {

			number *= -1;

			while (number > 0) {

				wholePart += to_string(number % 2);
				number /= 2;
			}

			wholePart += '-';
			reverse(wholePart.begin(), wholePart.end());
		}
		else {

			wholePart.insert(0, "-0");
		}
	}
	else {

		number = stoll(wholePart);
		wholePart.clear();

		if (number != 0) {

			while (number > 0) {

				wholePart += to_string(number % 2);
				number /= 2;
			}

			reverse(wholePart.begin(), wholePart.end());
		}
		else {

			wholePart = '0';
		}
	}

	if (fraction.empty() == false) {

		fractionNumber = stold(fraction);
		fraction.clear();

		while (occurasity > 0 && fractionNumber != 0) {
			fractionNumber *= 2;

			if (fractionNumber >= 1) {
				fraction += '1';
				fractionNumber -= 1;
			}
			else {
				fraction += '0';
			}

			occurasity--;
		}

		wholePart = wholePart + '.' + fraction;
	}
	return wholePart;
}

String intToOct(String value) {

	string wholePart = value.toAnsiString();
	string fraction;
	size_t dotPosition;
	long long int number;
	long double fractionNumber;
	int occurasity; //число знаков

	occurasity = 10;

	findPos(wholePart, fraction, dotPosition);

	if (wholePart[0] == '-') {

		number = stoll(wholePart);
		wholePart.clear();

		if (number != 0) {

			while (number < 0) {

				wholePart += to_string((number % 8) * -1);
				number /= 8;
			}

			wholePart += '-';

			reverse(wholePart.begin(), wholePart.end());
		}
		else {

			wholePart.insert(0, "-0");
		}
	}
	else {

		number = stoll(wholePart);
		wholePart.clear();

		if (number != 0) {

			while (number > 0) {

				wholePart += to_string(number % 8);
				number /= 8;
			}

			reverse(wholePart.begin(), wholePart.end());
		}
		else {

			wholePart = '0';
		}
	}

	if (fraction.empty() == false) {

		fractionNumber = stold(fraction);
		fraction.clear();

		while (fractionNumber != 0 && occurasity > 0) {
			fractionNumber *= 8;
			fraction += to_string((int)fractionNumber);

			if (fractionNumber > 1) {
				fractionNumber -= (int)fractionNumber;
			}
			occurasity--;
		}

		wholePart = wholePart + '.' + fraction;
	}

	return wholePart;
}

String intToHex(String value) {

	string wholePart = value.toAnsiString();
	string fraction;
	size_t dotPosition;
	long long int number;
	long double fractionNumber;
	int occurasity; //число знаков

	occurasity = 10;

	findPos(wholePart, fraction, dotPosition);

	if (wholePart[0] == '-') {

		number = stoll(wholePart);
		wholePart.clear();

		if (number != 0) {

			number *= -1;

			while (number > 0) {

				wholePart += hexNumbers[number % 16];
				number /= 16;
			}

			wholePart += '-';

			reverse(wholePart.begin(), wholePart.end());
		}
		else {

			wholePart.insert(0, "-0");
		}
	}
	else {

		number = stoll(wholePart);
		wholePart.clear();

		if (number != 0) {

			while (number > 0) {

				wholePart += hexNumbers[number % 16];
				number /= 16;
			}

			reverse(wholePart.begin(), wholePart.end());
		}
		else {

			wholePart = '0';
		}
	}

	if (fraction.empty() == false) {

		fractionNumber = stold(fraction);
		fraction.clear();

		while (occurasity > 0) {
			
			fractionNumber *= 16;

			fraction += hexNumbers[(int)fractionNumber];

			fractionNumber -= (int)fractionNumber;

			occurasity--;
		}

		wholePart = wholePart + '.' + fraction;
	}

	return wholePart;
}

String binToInt(String value) {

	string wholePart = value.toAnsiString();
	string fraction;
	size_t dotPosition;
	size_t stringSize;
	long long int number = 0;
	long double fractionNumber = 0;
	vector<int> decNumbers;

	findPos(wholePart, fraction, dotPosition);

	if (wholePart[0] == '-') {

		wholePart.erase(0, 1);
		stringSize = wholePart.size();

		reverse(wholePart.begin(), wholePart.end());

		initialiseVector(wholePart, decNumbers, (int)stringSize);
		wholePart.clear();

		for (int i = (int)stringSize - 1; i >= 0; i--) {

			number += (long long int)(decNumbers[i] * pow(2, i));
		}

		wholePart += "-";
		wholePart += to_string(number);
	}
	else {

		stringSize = wholePart.size();

		reverse(wholePart.begin(), wholePart.end());

		initialiseVector(wholePart, decNumbers, (int)stringSize);
		wholePart.clear();

		for (int i = (int)stringSize - 1; i >= 0; i--) {

			number += (long long int)(decNumbers[i] * pow(2, i));
		}

		wholePart += to_string(number);

	}

	decNumbers.clear();

	if (fraction.empty() == false) {

		fraction.erase(0, 2);
		stringSize = fraction.size();

		reverse(fraction.begin(), fraction.end());

		initialiseVector(fraction, decNumbers, (int)stringSize);
		fraction.clear();

		for (int i = (int)stringSize - 1, j = -1; i >= 0; i--, j--) {

			fractionNumber += decNumbers[i] * pow(2, j);
		}

		fraction += to_string(fractionNumber);
		fraction.erase(0, 1);

		wholePart = wholePart + fraction;
	}

	return wholePart;
}

String octToInt(String value) {

	string wholePart = value.toAnsiString();
	string fraction;
	size_t dotPosition;
	size_t stringSize;
	long long int number = 0;
	long double fractionNumber = 0;
	vector<int> decNumbers;

	findPos(wholePart, fraction, dotPosition);

	if (wholePart[0] == '-') {

		wholePart.erase(0, 1);
		stringSize = wholePart.size();

		reverse(wholePart.begin(), wholePart.end());

		initialiseVector(wholePart, decNumbers, (int)stringSize);
		wholePart.clear();

		for (int i = (int)stringSize - 1; i >= 0; i--) {

			number += (long long int)(decNumbers[i] * pow(8, i));
		}

		wholePart += "-";
		wholePart += to_string(number);
	}
	else {

		stringSize = wholePart.size();

		reverse(wholePart.begin(), wholePart.end());

		initialiseVector(wholePart, decNumbers, (int)stringSize);
		wholePart.clear();

		for (int i = (int)stringSize - 1; i >= 0; i--) {

			number += (long long int)(decNumbers[i] * pow(8, i));
		}

		wholePart += to_string(number);

	}

	decNumbers.clear();

	if (fraction.empty() == false) {

		fraction.erase(0, 2);
		stringSize = fraction.size();

		reverse(fraction.begin(), fraction.end());

		initialiseVector(fraction, decNumbers, (int)stringSize);
		fraction.clear();

		for (int i = (int)stringSize - 1, j = -1; i >= 0; i--, j--) {

			fractionNumber += decNumbers[i] * pow(8, j);
		}

		fraction += to_string(fractionNumber);
		fraction.erase(0, 1);

		wholePart = wholePart + fraction;
	}

	return wholePart;
}

String hexToInt(String value) {

	string wholePart = value.toAnsiString();
	string fraction;
	size_t dotPosition;
	size_t stringSize;
	long long int number = 0;
	long double fractionNumber = 0;
	vector<int> decNumbers;

	findPos(wholePart, fraction, dotPosition);

	if (wholePart[0] == '-') {

		wholePart.erase(0, 1);
		stringSize = wholePart.size();

		reverse(wholePart.begin(), wholePart.end());

		initialiseVectorHex(wholePart, decNumbers, (int)stringSize);
		wholePart.clear();

		for (int i = (int)stringSize - 1; i >= 0; i--) {

			number += (long long int)(decNumbers[i] * pow(16, i));
		}

		wholePart += "-";
		wholePart += to_string(number);
	}
	else {

		stringSize = wholePart.size();

		reverse(wholePart.begin(), wholePart.end());

		initialiseVectorHex(wholePart, decNumbers, (int)stringSize);
		wholePart.clear();

		for (int i = (int)stringSize - 1; i >= 0; i--) {

			number += (long long int)(decNumbers[i] * pow(16, i));
		}

		wholePart += to_string(number);

	}

	decNumbers.clear();

	if (fraction.empty() == false) {

		fraction.erase(0, 2);
		stringSize = fraction.size();

		reverse(fraction.begin(), fraction.end());

		initialiseVectorHex(fraction, decNumbers, (int)stringSize);
		fraction.clear();

		for (int i = (int)stringSize - 1, j = -1; i >= 0; i--, j--) {

			fractionNumber += decNumbers[i] * pow(16, j);
		}

		fraction += to_string(fractionNumber);
		fraction.erase(0, 1);

		wholePart = wholePart + fraction;
	}

	return wholePart;
}


String converter_to_scale_of_nation(String value, int operation_id, int labelId)
{	
	switch (labelId)
	{
	case 1:
		value = binToInt(value);
		break;
	case 2:
		value = octToInt(value);
		break;
	case 4:
		value = hexToInt(value);
		break;
	default:
		break;
	}

	switch (operation_id)
	{
	case 1:
		return intToBin(value);
		break;
	case 2:
		return intToOct(value);
		break;
	case 3: 
		return value;
		break;
	case 4:
		return intToHex(value);
		break;
	default:
		break;
	}
}