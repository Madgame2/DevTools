#include"Header.h"
#include<iostream>
#include<locale>

using namespace std;

void addNull(string &result, int maxSize, int size) {

	for (int i = 0; i < maxSize - size; i++) {
		result += "0";
	}
}

void addSymbolsToResult(string& result, string decNumbers, int stringSize) {

	for (int i = 0; i < stringSize; i++) {

		if (result.size() % 8 == 0) {

			result += "10";
		}
		result += decNumbers[i];
	}
}

String encodeUtf8(String data) {

	Uint32 unicodeNumber;
	string decNumbers;
	string result;
	string finalResult;
	int stringSize;

	for (int i = 0; i < data.getSize(); i++) {

		unicodeNumber = data[i];
		decNumbers += intToBin(to_string(unicodeNumber));

		stringSize = (int)decNumbers.length();

		if (stringSize >= 17 && stringSize <= 21) {

			result += "11110";

			addNull(result, 21, stringSize);

			addSymbolsToResult(result, decNumbers, stringSize);
		}
		else if (stringSize <= 16 && stringSize >= 12) {

			result += "1110";

			addNull(result, 16, stringSize);

			addSymbolsToResult(result, decNumbers, stringSize);
		}
		else if (stringSize <= 11 && stringSize >= 8) {

			result += "110";

			addNull(result, 11, stringSize);

			addSymbolsToResult(result, decNumbers, stringSize);
		}
		else if (stringSize <= 7) {

			result += "0";

			addNull(result, 7, stringSize);

			addSymbolsToResult(result, decNumbers, stringSize);
		}
		decNumbers.clear();

		result = binToInt(result);
		result = intToHex(result);

		finalResult += result +" ";
		result.clear();
	}
	return finalResult;
}

String encodeAscii(String data) {

	locale loc("Russian");
	string simbols = data.toAnsiString(loc);
	char codeOfSimbol;
	string HexCodeOfSimbol, result;

	for (int i = 0; i < simbols.length(); i++) {

		codeOfSimbol = simbols[i];

		if ((int)codeOfSimbol > 127 || (int)codeOfSimbol < 0) {
			result = "Eror";
			break;
		}

		HexCodeOfSimbol += to_string((int)codeOfSimbol);
		result += intToHex(HexCodeOfSimbol) + " ";
		HexCodeOfSimbol.clear();
	}

	return result;
}

String encodeWin1251(String data) {

	locale loc("Russian");
	string simbols = data.toAnsiString(loc);
	unsigned char codeOfSimbol;
	string HexCodeOfSimbol, result;

	for (int i = 0; i < simbols.length(); i++) {

		codeOfSimbol = simbols[i];

		if ((int)codeOfSimbol > 256) {
			result = "Eror";
			break;
		}

		HexCodeOfSimbol += to_string((int)codeOfSimbol);
		result += intToHex(HexCodeOfSimbol) + " ";
		HexCodeOfSimbol.clear();
	}

	return result;
}

String  encodeUtf16(String data) {

	Uint32 unicodeNumber;
	string result;
	string finalResult;

	for (int i = 0; i < data.getSize(); i++) {

		unicodeNumber = data[i];

		if (unicodeNumber <= 65535 && (unicodeNumber < 55296 || unicodeNumber > 57343)) {

			result = result + intToHex(to_string(unicodeNumber));

			while (result.length() < 4) {
				result.insert(0, "0");
			}

			finalResult += result + " ";
			result.clear();
		}
	}
	return finalResult;
}

String encoder(String data, int operation_id)
{
	switch (operation_id)
	{
	case 0:
		return encodeUtf16(data);
		break;
	case 1:
		return encodeUtf8(data);
		break;
	case 2:
		return encodeAscii(data);
		break;
	case 3:
		return encodeWin1251(data);
		break;
	default:
		break;
	}
}