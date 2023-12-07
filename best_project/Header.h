#pragma once
#include<string>
#include<SFML/Graphics.hpp>


using namespace std;
using namespace sf;

string encoder(string data); //кодировшик ASCII UTF-8 UTF-16...

string converter_to_mathematical_system(string data); //конвертор в биты байты Кбайты... 

string converter_to_scale_of_nation(string value, int operation_id); //конвертор в системы счисления
																	/*1 - BIN(двоичная)
																	  2 - OCT(восмеричная)
																	  3 - DEC(десфтичная)
																	  4 - HEX(шестнадцатиричная)*/

void binary_logic(int operation_ID,string label_input); //связуюшее звенно между модулем arithmetic_operations и модулем convertor_to_machine_code
									 /*
									 * 1 - arithmetic_operations(арифметическое насилие над числами)
									 * 2 - convertor_to_machine_code(приобразовать в машинный код)
									 */

string arithmetic_operations(string operation); //арифметические операции с точки зрения микропроцессора/микроконтролера

string convertor_to_machine_code(float value); //преобразует десятичное число в машинный код

bool checking(int module_ID, string data);