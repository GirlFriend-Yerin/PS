#pragma once
#include <iostream>
using namespace std;
class Fraction
{
private:
	int number, denom; // 분자, 분모
public:
	Fraction() {};
	Fraction(int number, int denom);
	void setNumber(int n) { number = n; };
	int getNumber()const { return number; };
	void setDenom(int d) { denom = d; };
	int getDenom()   const { return denom; };
	void makeFract();      //기약분수 만들기
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
			bool irreducible = true; // 기약분수 유무 while 시작할때는 true로 시작
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
					irreducible = false; // 약분을 했으면 기약분수 flase하고 for이 더 돌아가도록 함
				}
			}
			if (irreducible == true)
				break; //for에서 if가 한번도 작동하지 않으면 약분이 완료된 것이므로 while 탈출
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
	int n, d;//분자,분모에 들어갈 수
	Fraction f1, f2;

	while (1)
	{
		cout << "첫번째 분수의 정보를 입력하세요" << endl;
		if (readNumberDenom(n, d) == 0)
			break;
		f1.setNumber(n);
		f1.setDenom(d);
		cout << "두번째 분수의 정보를 입력하세요" << endl;
		readNumberDenom(n, d);
		f2.setNumber(n);
		f2.setDenom(d);
		cout << "입력된 값은" << f1 << "과" << f2 << endl << endl;
		cout << f1 << " + " << f2 << " = " << f1 + f2 << endl;
		cout << f1 << " - " << f2 << " = " << f1 - f2 << endl;
		cout << f1 << " * " << f2 << " = " << f1 * f2 << endl;
		cout << f1 << " / " << f2 << " = " << f1 / f2 << endl;
	}
}
int readNumberDenom(int& n, int& d)
{
	cout << "분자값을 입력하세요(종료하려면 0) :";
	cin >> n;
	if (n == 0)
		return 0;
	do
	{
		cout << "0이 아닌 분모값을 입력하세요: ";
		cin >> d;
	} while (d == 0);

	return 1;
};