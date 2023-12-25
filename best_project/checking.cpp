#include"Header.h"

bool encoder(String data) {
	if (true/*какие данные должны быть*/) {
		return true;
	}
	else {
		return false;
	}
}

bool converter_to_mathematical_system(String data) {
	if (true/*какие данные должны быть*/) {
		return true;
	}
	else {
		return false;
	}
}

bool converter_to_scale_of_nation(String data) {
	if (true/*какие данные должны быть*/) {
		return true;
	}
	else {
		return false;
	}
}

bool arithmetic_operations_check(String data) {
	if (true/*какие данные должны быть*/) {
		return true;
	}
	else {
		return false;
	}
}

bool convertor_to_machine_code(String data) {
	if (true/*какие данные должны быть*/) {
		return true;
	}
	else {
		return false;
	}
}

bool checking(int module_ID, String data)
{
	switch (module_ID)
	{
	case 1:
		return encoder(data);
		break;
	case 2:
		return converter_to_mathematical_system(data);
		break;
	case 3:
		return converter_to_scale_of_nation(data);
		break;
	case 4:
		return arithmetic_operations_check(data);
		break;
	case 5:
		return convertor_to_machine_code(data);
		break;

	default:
		std::cout << "ERROE - wrong id" << std::endl;
		return false;
	}
}