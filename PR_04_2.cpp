#include "math.h"
#include <cmath>
#include "iostream"
#include <string>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <stdio.h>

using namespace std;

/*Задание.

Класс Сотрудник. Класс Босс, производный от Сотрудника.
Босс имеет надбавку к зарплате.

Дано: компания, в которой есть несколько отделов.
Каждым отделом руководит Босс.
В каждом отделе несколько сотрудников.

Реализовать перегрузку функции

Реализовать перегрузку метода вычисления зарплаты Сотрудника и Босса.

Реализовать перегрузку оператора сравнения
доходов двух Сотрудников, двух Боссов.

Реализовать перегрузку оператора суммирования
доходов двух Сотрудников, двух Боссов.*/


class Sotrudnik
{
public:
	int zarplata;
	void display_1()
	{
		cout << "\tZarplata: " << zarplata << endl;
	}

};
class Boss : public Sotrudnik
{
public:
	int nadbavka;
	void display_2()
	{
		cout << "\nZarplata sotrudnica: " << zarplata << endl;
		cout << "Zarplata bossa: " << zarplata + nadbavka << endl;
	}
};

class Srav : public Boss
{
public:
	Srav(int pr)
	{
		price = pr;
	}
	void displ1()
	{
		if (price > 0)
		{
			cout << "\n1st boss price > 2nd boss price.\n";
		}
		else if (price < 0)
		{
			cout << "\n1st boss price < 2nd boss price.\n";
		}
		else
		{
			cout << "\n1st boss price = 2nd boss price.\n";
		}
	}
	int price;
};

Srav operator - (Srav c1, Srav c2)
{
	return Srav(c1.price - c2.price);
}

void Otdel()
{
	int pr;
	int nad;

		cout << "\n-------- " << 1 << " otdel --------";


		cout << "\nVvedite zarplatu sotrudnica:\t";
		cin >> pr;

		cout << "\nVvedite nadbavku bossa:\t";
		cin >> nad;

		Boss sotr;
		sotr.zarplata = pr;
		sotr.nadbavka = nad;
		sotr.display_2();

		Srav c1(pr+nad);

		cout << "\n-------- " << 2 << " otdel --------";

		cout << "\nVvedite zarplatu sotrudnica:\t";
		cin >> pr;

		cout << "\nVvedite nadbavku bossa:\t";
		cin >> nad;

		sotr.zarplata = pr;
		sotr.nadbavka = nad;
		sotr.display_2();

		Srav c2(pr+nad);

		Srav c3 = c1 - c2;
		c3.displ1();


}

int main()
{
	Otdel();
}