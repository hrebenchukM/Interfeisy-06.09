#include <iostream>
using namespace std;
#include<string.h>

#include"Mylibrary.h"
/*��:
* 1.������� ����� ������� �� ������ Animal, ����������� ������ ����������
* 2. ������� ����� �������, � ����������� ������ ���������.
* 3. ������� �������, ������� ����� �������� � � �������� ������ �������, � � �������� ������ �������!!
*/




int main()
{
	setlocale(0, "ru");
	Pinguin obj("����������� �������", 100, "�������");
	Func(&obj);

	//* ptr = &obj; //������������ ������ ����� ��������� �� ������� �������, ������� �� ���������.

	//ptr->Swim();
	
	
	Ship sh;
	Func(&sh);

	
	Parrot parrot("����", 2,"�����");
	Func1(&parrot); 

	Plane plane;
	Func1(&plane); 

	return 0;
}

