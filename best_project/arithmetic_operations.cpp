#include"Header.h"

using namespace std;

string plusFunction(long long int firstCount, long long int secondCount) {

	return to_string(firstCount + secondCount);
}

string minusFunction(long long int firstCount, long long int secondCount) {

	return to_string(firstCount - secondCount);
}

string multFunction(long long int firstCount, long long int secondCount) {

	return to_string(firstCount * secondCount);
}

string divisionFunction(long long int firstCount, long long int secondCount) {

	return to_string(firstCount / secondCount);
}

String getResult(String count_1, String count_2, int operation_id) {

	long long int firstCount = stoll(count_1.toAnsiString());
	long long int secondCount = stoll(count_2.toAnsiString());
	string intResult, result;

	switch (operation_id)
	{
	case 1:
		intResult = plusFunction(firstCount, secondCount);
		break;
	case 2:
		intResult = minusFunction(firstCount, secondCount);
		break;
	case 3:
		intResult = multFunction(firstCount, secondCount);
		break;
	case 4:
		intResult = divisionFunction(firstCount, secondCount);
		break;
	default:
		break;
	}

	result = intToBin(intResult);
	return result;
}

String arithmetic_operations(String count_1, String count_2, int operation_id)
{   
	bool check = true;
	string checkingString1 = count_1.toAnsiString();
	string checkingString2 = count_2.toAnsiString();
	char symbol;

	for (int i = 0; i < checkingString1.length(); i++) {

		symbol = checkingString1[i];

		if (!((int)symbol >= 48 && (int)symbol <= 57)) {
			check = false;
			break;
		}
	}

	for (int i = 0; i < checkingString2.length(); i++) {

		symbol = checkingString2[i];

		if (!((int)symbol >= 48 && (int)symbol <= 57)) {
			check = false;
			break;
		}
	}

	if (check == true) {

		switch (operation_id)
		{
		case 1:
			return getResult(count_1, count_2, 1);
			break;
		case 2:
			return getResult(count_1, count_2, 2);
			break;
		case 3:
			return getResult(count_1, count_2, 3);
			break;
		case 4:
			return getResult(count_1, count_2, 4);
			break;
		default:
			break;
		}
	}
	else {
		return "Eror";
	}
}