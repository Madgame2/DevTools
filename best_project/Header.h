#pragma once
#include<string>
#include<SFML/Graphics.hpp>


using namespace std;
using namespace sf;

string encoder(string data); //���������� ASCII UTF-8 UTF-16...

string converter_to_mathematical_system(string data); //��������� � ���� ����� ������... 

string converter_to_scale_of_nation(string value, int operation_id); //��������� � ������� ���������
																	/*1 - BIN(��������)
																	  2 - OCT(�����������)
																	  3 - DEC(����������)
																	  4 - HEX(�����������������)*/

void binary_logic(int operation_ID,string label_input); //��������� ������ ����� ������� arithmetic_operations � ������� convertor_to_machine_code
									 /*
									 * 1 - arithmetic_operations(�������������� ������� ��� �������)
									 * 2 - convertor_to_machine_code(������������� � �������� ���)
									 */

string arithmetic_operations(string operation); //�������������� �������� � ����� ������ ���������������/���������������

string convertor_to_machine_code(float value); //����������� ���������� ����� � �������� ���

bool checking(int module_ID, string data);