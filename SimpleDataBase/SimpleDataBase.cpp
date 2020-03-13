//SimpleLevel

#include <iostream>
using namespace std;

struct Date {
		short day;
		short month;
		short year;
		bool isCorrect();
};

bool Date::isCorrect()
{
	bool result = false;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if ((day <= 31) && (day > 0))
			result = true;
		break;
	}

	case 4:
	case 6:
	case 9:
	case 11:
	{
		if ((day <= 30) && (day > 0))
			result = true;
		break;
	}

	case 2:
	{
		if (year % 4 != 0)
		{
			if ((day <= 28) && (day > 0))
				result = true;
		}
		else
			if (year % 400 == 0)
			{
				if ((day <= 29) && (day > 0))
					result = true;
			}
			else
				if ((year % 100 == 0) && (year % 400 != 0))
				{
					if ((day == 28) && (day > 0))
						result = true;
				}
				else
					if ((year % 4 == 0) && (year % 100 != 0))
						if ((day <= 29) && (day > 0))
							result = true;
		break;
	}

	default:
		result = false;
	}

	return result;
}


struct Product{
	char F[25];
	char I[25];
	char O[25];
	short Amount;
	int Price;
	char Creator[25];
	Date date;
};
 void CoutNameProduct(Product *product,const short *N) {
	 int max = 0;
	 for (int i = 0;i < *N-1;i++) {
		 if (product[i + 1].Price * product[i + 1].Amount > product[max].Price * product[max].Amount) {
			 max = i+1;
		 }
	 }
	 cout << "NameOfTheMostExpensive:"<< product[max].F<<" "<<product[max].I<<" "<< product[max].O;
 }

 int main()
 {
	 const short N = 2;
	 Product product[N];
	 setlocale(LC_ALL, "");

	 for (int i = 0; i < N; i++) {

		 cout << "\nInput F: ";
		 cin.ignore(cin.rdbuf()->in_avail());
		 cin >> product[i].F;

		 cout << "\nIinput I: ";
		 cin.ignore(cin.rdbuf()->in_avail());
		 cin >> product[i].I;

		 cout << "\nInput O: ";
		 cin.ignore(cin.rdbuf()->in_avail());
		 cin >> product[i].O;

		 cout << "\nInput Creator: ";
		 cin.ignore(cin.rdbuf()->in_avail());
		 cin >> product[i].Creator;

		 do
		 {
			 cout << "\nInput date: ";
			 cin.ignore(cin.rdbuf()->in_avail());
			 cin >> product[i].date.day >> product[i].date.month >> product[i].date.year;
		 } while (!product[i].date.isCorrect()); {

			 cout << "\nInput amount:";
			 cin.ignore(cin.rdbuf()->in_avail());
			 cin >> product[i].Amount;

			 cout << "\nInput price:";
			 cin.ignore(cin.rdbuf()->in_avail());
			 cin >> product[i].Price;


		 }
	 }
	 

	 CoutNameProduct(product, &N);
	cin.clear();
}
