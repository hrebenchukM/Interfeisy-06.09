#include <iostream>
using namespace std;
#include<string.h>

#include"Mylibrary.h"
/*дз:
* 1.Создать класс Попугай на основе Animal, реализовать нужные интерфейсы
* 2. Создать класс Самолет, и реализовать нужный интерфейс.
* 3. Создать функцию, который может работать и с объектом класса самолет, и с объектом класса попугай!!
*/




int main()
{
	setlocale(0, "ru");
	Pinguin obj("Королевский пингвин", 100, "Арктика");
	Func(&obj);

	//* ptr = &obj; //Интерфейсные ссылки могут ссылаться на объекты классов, которые их реализуют.

	//ptr->Swim();
	
	
	Ship sh;
	Func(&sh);

	
	Parrot parrot("Кеша", 2,"Домик");
	Func1(&parrot); 

	Plane plane;
	Func1(&plane); 

	return 0;
}

