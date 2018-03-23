#include<iostream>
#include<vector>
#include<string>


using namespace std;

const int MAX_START = 50;   // maximum starting number

							


/***** Fuction Declarations. *****/

void do_prime_spiral(const int n, const int start);

int increment_number(int current_number);

string supply_current_symbol(int current_number);

/**
* The main: Generate and print spirals of various sizes.
*/
int main()
{
	do_prime_spiral(5, 1);
	do_prime_spiral(25, 11);
	do_prime_spiral(35, 0);
	do_prime_spiral(50, 31);
	do_prime_spiral(101, 41);
}



/***** Fuction Definitions. *****/

void do_prime_spiral(const int n, const int start)
{

	vector< vector<string>> v(n, vector<string>(n));    // 2d string vector of n columns and n rows
	int current_number = start;                          // number for storing curret value of start 


	if (start <= MAX_START && start>0) //Checking the maximum limit condtion for size and start
	{

		/*** for given prime spiral having odd size ***/

		if (n % 2 == 1)
		{
			cout << "Prime spiral of size " << n << " starting at " << start << endl;
			cout << endl;

			/*** Variable Declarations ***/

			int start_point = (n - 1) / 2;    // row and column number where the start element will be placed
			int current_row_number;           // current value of row number
			int current_column_number;        // current value of column number
			int max_rowNumber = n - 1;        // maximum value of row number
			int max_columnNumber = n - 1;     // maximum value of column number
			int counter1 = 0;                 // counter1 for tracking number of columns traversed horizontally 
			int counter2 = 2;                 // counter2 to store number of steps to be traversed in vertical top direction 
			int counter3 = 0;                 // counter3 to store number of current steps traversed in vertical top direction
			string current_symbol = "";       // to store the character returned '#' or '.' based on current number

			if (n == 1)
			{

				current_symbol = supply_current_symbol(current_number);
				v[current_row_number][current_column_number] = current_symbol;
				cout << v[max_rowNumber][max_columnNumber] << endl;
				cout << endl;
			}

			else
			{
				current_row_number = start_point;
				current_column_number = start_point;
				current_symbol = supply_current_symbol(current_number);
				v[current_row_number][current_column_number] = current_symbol;
				current_number = increment_number(current_number);


				while (current_row_number<max_rowNumber)
				{
					counter3 = 1;
					if (current_row_number<n)
					{
						current_column_number = current_column_number + 1;
						current_symbol = supply_current_symbol(current_number);
						v[current_row_number][current_column_number] = current_symbol;
						current_number = increment_number(current_number);
					}

					while (counter3<counter2)
					{
						current_row_number = current_row_number - 1;
						current_symbol = supply_current_symbol(current_number);
						v[current_row_number][current_column_number] = current_symbol;
						current_number = increment_number(current_number);
						counter3 = counter3 + 1;
					}

					while (current_column_number>current_row_number)
					{
						current_column_number = current_column_number - 1;
						current_symbol = supply_current_symbol(current_number);
						v[current_row_number][current_column_number] = current_symbol;
						current_number = increment_number(current_number);
						counter1++;
					}

					while (counter1 != 0)
					{
						current_row_number = current_row_number + 1;
						current_symbol = supply_current_symbol(current_number);
						v[current_row_number][current_column_number] = current_symbol;
						current_number = increment_number(current_number);
						counter1 = counter1 - 1;
					}

					while (current_column_number<current_row_number)
					{
						current_column_number = current_column_number + 1;
						current_symbol = supply_current_symbol(current_number);
						v[current_row_number][current_column_number] = current_symbol;
						current_number = increment_number(current_number);
						counter1++;
					}

					counter2 = counter2 + 2;
					counter1 = 0;

				}

				for (int current_row_number = 0; current_row_number<n; current_row_number++)
				{

					for (int current_column_number = 0; current_column_number<n; current_column_number++)
					{

						if (current_column_number<(n - 1))
						{
							cout << v[current_row_number][current_column_number];
						}
						else
						{
							cout << v[current_row_number][current_column_number] << endl;
						}

					}
				}

				cout << endl;

			}
		}

		/*** for given prime spiral having even size ***/

		else
		{
			cout << "Prime spiral of size " << n << " starting at " << start << endl;
			cout << "***** Error: Size " << n << " must be odd." << endl;
			cout << endl;
		}

	}

	else
	{
		cout << "Prime spiral of size " << n << " starting at " << start << endl;
		cout << "***** Error: Starting value 0 < 1 or > 50" << endl;
		cout << endl;
	}

}


int increment_number(int current_number)
{
	current_number = current_number + 1;
	return current_number;
}


string supply_current_symbol(int current_number)
{
	int max_number = 30000;
	int a[30000] = {};   // 1d array to store and print prime numbers
	int j = 2;
	string current_symbol = "";


	while (j < max_number)
	{
		for (int k = j * j; k < max_number; k = k + j)
		{
			a[k - 1] = 1;
		}
		j = j + 1;
	}

	j = current_number;

	if (j == 1)
	{
		current_symbol = ".";
	}
	else
	{
		while (j < max_number)
		{
			if (a[j - 1] == 0)
			{

				current_symbol = "#";
				break;
			}
			else
			{
				current_symbol = ".";
				break;

			}
			j++;
		}
	}

	return current_symbol;
}


