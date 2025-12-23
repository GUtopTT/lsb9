#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double loan, rate, amount;
	cout << "Enter initial loan: ";
	cin >> loan;
	cout << "Enter interest rate per year (%): ";
	cin >> rate;
	cout << "Enter amount you can pay per year: ";
	cin >> amount;

	cout << setw(13) << left << "EndOfYear#"
		 << setw(13) << left << "PrevBalance"
		 << setw(13) << left << "Interest"
		 << setw(13) << left << "Total"
		 << setw(13) << left << "Payment"
		 << setw(13) << left << "NewBalance"
		 << endl;

	cout << fixed << setprecision(2);

	int year = 1;
	double prevBalance = loan;

	while (prevBalance > 0)
	{
		double interest = prevBalance * rate / 100.0;
		double total = prevBalance + interest;

		double payment;
		if (total >= amount)
			payment = amount;
		else
			payment = total;

		double newBalance = total - payment;

		cout << setw(13) << left << year
			 << setw(13) << left << prevBalance
			 << setw(13) << left << interest
			 << setw(13) << left << total
			 << setw(13) << left << payment
			 << setw(13) << left << newBalance
			 << endl;

		prevBalance = newBalance;
		year++;
	}

	return 0;
}
