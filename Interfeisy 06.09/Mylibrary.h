#pragma once
#include<iostream>
#include<string.h>
using namespace std;




struct ISwim //интерфейс - это класс или структура с открытыми чисто виртуальными функциями.

{
	virtual void Swim() = 0;
};


struct IFly//Interface Интерфейсы не наследуются а реализуются. А реализация - это переопределение.

{
	virtual void Fly() = 0;
};



class Animal  // абстрактный класс !!Абстрактный класс имеет определенное поведение по умолчанию. 
	//Поля - методы с телом, соответственно при наследовании потомки все это получают. 

{
protected:
	char* name;
	int kg;
public:
	Animal() = default;
	Animal(const char* n, int k)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
		kg = k;
	}

	~Animal()
	{
		delete[] name;
	}
	void Print()
	{
		cout << "Name: " << name << "Kg: " << kg << endl;
	}

	//чисто виртуальные методы
	virtual void Continent() = 0;
	virtual void Eat() = 0;
	virtual void Sound() = 0;


};





//* 1.Создать класс Попугай на основе Animal, реализовать нужные интерфейсы

class Parrot : public Animal, public IFly
{
	char* continent;
public:
	Parrot() = default;
	Parrot(const char* n, int kg, const char* cont) :Animal(n, kg)
	{
		continent = new char[strlen(cont) + 1];
		strcpy_s(continent, strlen(cont) + 1, cont);
	}



	virtual void Continent()
	{
		cout << "Попугаи могут обитать в различных местах по всему миру\n";
	}

	virtual void Eat()
	{
		cout << "Попугаи едят фрукты и семена\n";
	}

	virtual void Sound()
	{
		cout << "Попугаи издают разнообразные звуки и повторяют слова\n";
	}

	virtual void Fly()
	{
		cout << "Попугаи могут летать\n";
	}

	~Parrot()
	{
		delete continent;
	}

};



//2. Создать класс Самолет, и реализовать нужный интерфейс.
class Plane : public IFly
{
public:
	virtual void Fly()
	{
		cout << "Самолет летит по воздуху\n";
	}
};



//3. Создать функцию, который может работать и с объектом класса самолет, и с объектом класса попугай!!
void Func1(IFly* ptr)
{
	ptr->Fly();
}










class Pinguin : public Animal, public ISwim//(Реализация интерфейса)
{
	char* continent;

public:
	Pinguin() = default;
	Pinguin(const char* n, int kg, const char* cont) :Animal(n, kg)
	{
		continent = new char[strlen(cont) + 1];
		strcpy_s(continent, strlen(cont) + 1, cont);
	}



	virtual void Continent()
	{
		cout << "Пингвины живут в Антарктиде\n";
	}


	virtual void Eat()
	{
		cout << "Пингвины едят рыбу\n";
	}
	virtual void Sound()
	{
		cout << "Пингвины издают какие то звуки\n";
	}


	//реализация интерфейса ISwim
	virtual  void Swim()
	{
		cout << "Пингвины отлично плавают\n";
	}

	~Pinguin()
	{
		delete[] continent;
	}

};

class Ship : public ISwim
{
public:
	virtual void Swim()
	{
		cout << "Корабль-водный транспорт\n";
	}
};
void Func(ISwim* ptr)
{
	ptr->Swim();

}




