#pragma once
#include<String>
#include<SFML/Graphics.hpp>



using namespace sf;

String encoder(String data, int operation_id); //кодировшик ASCII UTF-8 UTF-16...
											   /*
											   * 0- UTF-16
											   * 1- UTF-8
											   * 2- ASCII
											   * 3- WIN-1251
											   */

String converter_to_mathematical_system(String data, int operation_id); //конвертор в биты байты Кбайты... 
																		/*
																		* 1 - Биты
																		* 2 - Байт
																		* 3 - КБайт
																		* 4 - МБайт
																		* 5 - ГБайт
																		* 6 - ТБайт
																		*/

String converter_to_scale_of_nation(String value, int operation_id, int labelId); //конвертор в системы счисления
																	/*1 - BIN(двоичная)
																	  2 - OCT(восмеричная)
																	  3 - DEC(десфтичная)
																	  4 - HEX(шестнадцатиричная)*/

void binary_logic(int operation_ID,String label_input); //связуюшее звенно между модулем arithmetic_operations и модулем convertor_to_machine_code
									 /*
									 * 1 - arithmetic_operations(арифметическое насилие над числами)
									 * 2 - convertor_to_machine_code(приобразовать в машинный код)
									 */

String arithmetic_operations(String operation); //арифметические операции с точки зрения микропроцессора/микроконтролера

String convertor_to_machine_code(String data, int operation_id); //преобразует десятичное число в машинный код
																 /*
																  * 1 - ПК
																  * 2 - ОК
																  * 3 - ДК
																 */

String intToBin(String value); //преобразует десятичное число в двоичное

String intToHex(String value); //преобразует десятичное число в шестнадцатиричное

String binToInt(String value); //преобразует двоичное число в десятичное

bool checking(int module_ID, String data);