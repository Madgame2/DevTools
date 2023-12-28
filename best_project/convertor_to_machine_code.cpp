#include"Header.h"

using namespace std;

void InsertZeros(string& num) {

	if (num.length() < 7) {
		int x = (int)(7 - num.length());
		num.insert(0, x, '0');
	}
	else if (num.length() > 7 && num.length() < 15 && num.length() != 7) {
		int x = (int)(15 - num.length());
		num.insert(0, x, '0');
	}
	else if (num.length() > 15 && num.length() < 23 && num.length() != 15) {
		int x = (int)(23 - num.length());
		num.insert(0, x, '0');
	}
	else if (num.length() > 23 && num.length() < 31 && num.length() != 23) {
		int x = (int)(31 - num.length());
		num.insert(0, x, '0');
	}
	else if (num.length() > 31 && num.length() != 31) {
		int x = (int)(31 - num.length());
		num.insert(0, x, '0');
	}
}

void ConversionToReverseCode(string& num) {
	for (int i = 0; i < num.length(); i++) {
		if (num[i] == '1') {
			num[i] = '0';
		}
		else if (num[i] == '0') {
			num[i] = '1';
		}
	}
}

string ConversionToAdditionalCode(string& num) {
	if (num[num.length() - 1] == '0') {
		num[num.length() - 1] = '1';
		string sigh{ "1" };
		num.insert(0, sigh);
		return num;
	}
	else if (num[num.length() - 1] == '1') {

		for (int i = (int)(num.length() - 1); i > -1; i--) {

			if (num[i] == '1') {
				num[i] = '0';

			}
			else if (num[i] == '0') {
				num[i] = '1';
				string sigh{ "1" };
				num.insert(0, sigh);
				return num;
				break;
			}
		}
	}
}

string PrintNegativeNumber(string sigh, string num) {

	sigh = "1";
	num.insert(0, sigh);
	return num;
}

string PrintPositiveNumber(string sigh, string num) {

	sigh = "0";
	num.insert(0, sigh);
	return num;
}

String convertor_to_machine_code(String data, int operation_id)
{
	string num = intToBin(data.toAnsiString()), sigh;

	if (num == "Error" || num.find('.') != -1 || num.find(',') != -1) {
		return num = "Error";
	}
	else {
		switch (operation_id) {
		case 1:
			if (num[0] == '-') {//число отрицательное
				num.erase(0, 1);
				InsertZeros(num);
				return PrintNegativeNumber(sigh, num);
			}
			else {
				InsertZeros(num);
				return PrintPositiveNumber(sigh, num);
			}
			break;
		case 2:
			if (num[0] == '-') {//число отрицательное
				num.erase(0, 1);
				//вставляем нули
				InsertZeros(num);
				//перевод в обратный код
				ConversionToReverseCode(num);
				//выводим число
				return PrintNegativeNumber(sigh, num);
			}
			else {//если положительное
				//вставляем нули
				InsertZeros(num);
				//выводим число
				return PrintPositiveNumber(sigh, num);
			}
			break;
		case 3:
			if (num[0] == '-') {//если отрицательное число
				num.erase(0, 1);
				//вставка нулей
				InsertZeros(num);
				//перевод в обратный код
				ConversionToReverseCode(num);
				//перевод в дополнительный код 
				return ConversionToAdditionalCode(num);

			}
			else {//если положительное
				//вставка нулей
				InsertZeros(num);
				//вывод числа
				return PrintPositiveNumber(sigh, num);
			}
			break;
		}
	}
}