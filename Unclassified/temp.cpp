#pragma once
#include <iostream>
using namespace std;
class Fraction
{
private:
	int number, denom; // ����, �и�
public:
	Fraction() {};
	Fraction(int number, int denom);
	void setNumber(int n) { number = n; };
	int getNumber()const { return number; };
	void setDenom(int d) { denom = d; };
	int getDenom()   const { return denom; };
	void makeFract();      //���м� �����
	Fraction operator +(Fraction& f2);
	Fraction operator -(Fraction& f2);
	Fraction operator *(Fraction& f2);
	Fraction operator /(Fraction& f2);
	friend ostream& operator <<(ostream& outputStream, const Fraction& f1);
};
Fraction::Fraction(int number, int denom)
{
	setNumber(number);
	setDenom(denom);
	makeFract();
}
void Fraction::makeFract()
{
	if (number == 0 || denom == 0)
	{
		number = 0;
		denom = 0;
	}
	else
	{
		while (true)
		{
			int max;
			bool irreducible = true; // ���м� ���� while �����Ҷ��� true�� ����
			if (number < 0)
				max = number * -1;
			else
				max = number;
			for (int i = 2; i <= max; i++)
			{
				if (number % i == 0 && denom % i == 0)
				{
					max /= i;
					number /= i;
					denom /= i;
					irreducible = false; // ����� ������ ���м� flase�ϰ� for�� �� ���ư����� ��
				}
			}
			if (irreducible == true)
				break; //for���� if�� �ѹ��� �۵����� ������ ����� �Ϸ�� ���̹Ƿ� while Ż��
		}
	}
}

Fraction Fraction:: operator +(Fraction& f2)
{
	int n = number * f2.getDenom() + f2.getNumber() * denom;
	int d = denom * f2.getDenom();
	return Fraction(n, d);
}

Fraction Fraction:: operator -(Fraction& f2)
{
	int n = number * f2.getDenom() - f2.getNumber() * denom;
	int d = denom * f2.getDenom();
	return Fraction(n, d);
}
Fraction Fraction:: operator *(Fraction& f2)
{
	int n = number * f2.getNumber();
	int d = denom * f2.getDenom();
	return Fraction(n, d);
}
Fraction Fraction:: operator /(Fraction& f2)
{
	int n = number * f2.getDenom();
	int d = denom * f2.getNumber();
	return Fraction(n, d);
}
ostream& operator <<(ostream& outputStream, const Fraction& f1)
{
	if (f1.getDenom() == 0 || f1.getDenom() == 1)
		outputStream << f1.getNumber();
	else
	{
		outputStream << f1.getNumber() << "/" << f1.getDenom();
	}

	return outputStream;
}

int readNumberDenom(int& n, int& d);

int main()
{
	int n, d;//����,�и� �� ��
	Fraction f1, f2;

	while (1)
	{
		cout << "ù��° �м��� ������ �Է��ϼ���" << endl;
		if (readNumberDenom(n, d) == 0)
			break;
		f1.setNumber(n);
		f1.setDenom(d);
		cout << "�ι�° �м��� ������ �Է��ϼ���" << endl;
		readNumberDenom(n, d);
		f2.setNumber(n);
		f2.setDenom(d);
		cout << "�Էµ� ����" << f1 << "��" << f2 << endl << endl;
		cout << f1 << " + " << f2 << " = " << f1 + f2 << endl;
		cout << f1 << " - " << f2 << " = " << f1 - f2 << endl;
		cout << f1 << " * " << f2 << " = " << f1 * f2 << endl;
		cout << f1 << " / " << f2 << " = " << f1 / f2 << endl;
	}
}
int readNumberDenom(int& n, int& d)
{
	cout << "���ڰ��� �Է��ϼ���(�����Ϸ��� 0) :";
	cin >> n;
	if (n == 0)
		return 0;
	do
	{
		cout << "0�� �ƴ� �и��� �Է��ϼ���: ";
		cin >> d;
	} while (d == 0);

	return 1;
};