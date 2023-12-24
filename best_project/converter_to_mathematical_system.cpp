#include"Header.h"
#include<sstream>

using namespace std;

string changeString(long double data) {

	int position;
	string result, powbit;

	ostringstream bitConvert;
	bitConvert << data;
	result = bitConvert.str();

	position = result.find('e');

	if (position != -1) {

		powbit = result.substr(position + 1);

		for (int i = 0; i < powbit.length(); i++) {

			if (powbit[i] == '0') {

				powbit.erase(i, 1);
			}
			else if (powbit[i] != '-') {
				break;
			}
		}

		result.erase(position);
		result = result + "*10^" + powbit;
	}

	return result;
}

String convertToByte(long double data) {

	long double byte = data / 8;
	string result = changeString(byte);

	return result;
}

String convertToKilobyte(long double data) {

	long double byte = (data / 8) * pow(2, -10);
	string result = changeString(byte);

	return result;
}

String convertToMegabyte(long double data) {

	long double byte = (data / 8) * pow(2, -20);
	string result = changeString(byte);

	return result;
}

String convertToGigabyte(long double data) {

	long double byte = (data / 8) * pow(2, -30);
	string result = changeString(byte);

	return result;
}

String convertToTerabyte(long double data) {

	long double byte = (data / 8) * pow(2, -40);
	string result = changeString(byte);

	return result;
}


String converter_to_mathematical_system(String data, int operation_id, int labelId)
{	
	string bitString = data.toAnsiString();
	long double bit;

	switch (labelId)
	{
	case 1:
		bit = stold(bitString);
		break;
	case 2:
		bit = stold(bitString) * 8;
		break;
	case 3:
		bit = (stold(bitString) / pow(2, -10)) * 8;
		break;
	case 4:
		bit = (stold(bitString) / pow(2, -20)) * 8;
		break;
	case 5:
		bit = (stold(bitString) / pow(2, -30)) * 8;
		break;
	case 6:
		bit = (stold(bitString) / pow(2, -40)) * 8;
		break;
	default:
		break;
	}

	switch (operation_id)
	{
	case 1:
		return to_string(bit);
		break;
	case 2:
		return convertToByte(bit);
		break;
	case 3:
		return convertToKilobyte(bit);
		break;
	case 4:
		return convertToMegabyte(bit);
		break;
	case 5:
		return convertToGigabyte(bit);
		break;
	case 6:
		return convertToTerabyte(bit);
		break;
	default:
		break;
	}
}