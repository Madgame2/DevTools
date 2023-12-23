#pragma once
#include<String>
#include<SFML/Graphics.hpp>



using namespace sf;

String encoder(String data, int operation_id); //���������� ASCII UTF-8 UTF-16...
											   /*
											   * 0- UTF-16
											   * 1- UTF-8
											   * 2- ASCII
											   * 3- WIN-1251
											   */

String converter_to_mathematical_system(String data, int operation_id); //��������� � ���� ����� ������... 
																		/*
																		* 1 - ����
																		* 2 - ����
																		* 3 - �����
																		* 4 - �����
																		* 5 - �����
																		* 6 - �����
																		*/

String converter_to_scale_of_nation(String value, int operation_id, int labelId); //��������� � ������� ���������
																	/*1 - BIN(��������)
																	  2 - OCT(�����������)
																	  3 - DEC(����������)
																	  4 - HEX(�����������������)*/

void binary_logic(int operation_ID,String label_input); //��������� ������ ����� ������� arithmetic_operations � ������� convertor_to_machine_code
									 /*
									 * 1 - arithmetic_operations(�������������� ������� ��� �������)
									 * 2 - convertor_to_machine_code(������������� � �������� ���)
									 */

String arithmetic_operations(String operation); //�������������� �������� � ����� ������ ���������������/���������������

String convertor_to_machine_code(String data, int operation_id); //����������� ���������� ����� � �������� ���
																 /*
																  * 1 - ��
																  * 2 - ��
																  * 3 - ��
																 */

String intToBin(String value); //����������� ���������� ����� � ��������

String intToHex(String value); //����������� ���������� ����� � �����������������

String binToInt(String value); //����������� �������� ����� � ����������

bool checking(int module_ID, String data);