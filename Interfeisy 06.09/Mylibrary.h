#pragma once
#include<iostream>
#include<string.h>
using namespace std;




struct ISwim //��������� - ��� ����� ��� ��������� � ��������� ����� ������������ ���������.

{
	virtual void Swim() = 0;
};


struct IFly//Interface ���������� �� ����������� � �����������. � ���������� - ��� ���������������.

{
	virtual void Fly() = 0;
};



class Animal  // ����������� ����� !!����������� ����� ����� ������������ ��������� �� ���������. 
	//���� - ������ � �����, �������������� ��� ������������ ������� ��� ��� ��������. 

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

	//����� ����������� ������
	virtual void Continent() = 0;
	virtual void Eat() = 0;
	virtual void Sound() = 0;


};





//* 1.������� ����� ������� �� ������ Animal, ����������� ������ ����������

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
		cout << "������� ����� ������� � ��������� ������ �� ����� ����\n";
	}

	virtual void Eat()
	{
		cout << "������� ���� ������ � ������\n";
	}

	virtual void Sound()
	{
		cout << "������� ������ ������������� ����� � ��������� �����\n";
	}

	virtual void Fly()
	{
		cout << "������� ����� ������\n";
	}

	~Parrot()
	{
		delete continent;
	}

};



//2. ������� ����� �������, � ����������� ������ ���������.
class Plane : public IFly
{
public:
	virtual void Fly()
	{
		cout << "������� ����� �� �������\n";
	}
};



//3. ������� �������, ������� ����� �������� � � �������� ������ �������, � � �������� ������ �������!!
void Func1(IFly* ptr)
{
	ptr->Fly();
}










class Pinguin : public Animal, public ISwim//(���������� ����������)
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
		cout << "�������� ����� � ����������\n";
	}


	virtual void Eat()
	{
		cout << "�������� ���� ����\n";
	}
	virtual void Sound()
	{
		cout << "�������� ������ ����� �� �����\n";
	}


	//���������� ���������� ISwim
	virtual  void Swim()
	{
		cout << "�������� ������� �������\n";
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
		cout << "�������-������ ���������\n";
	}
};
void Func(ISwim* ptr)
{
	ptr->Swim();

}




