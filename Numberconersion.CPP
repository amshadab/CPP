#include <iostream.h>
#include <conio.h>
#include <math.h>
#include<stdio.h>

class Decimal_to_all   //Decimal to all conversion
{
public:
    int NUM[50], decimal, binary, octal, hexadecimal, i;

    Decimal_to_all()
    {
    decimal=0;
    binary=0;
    octal=0;
    hexadecimal=0;
    }

    void get()
    {
	cout << "Enter a decimal number(0-10): ";
	cin >> decimal;
    }

    void Dec_to_bin()   //Decimal to binary
    {
	binary = decimal;
	for (i = 0; binary != 0; i++)
	{
	    NUM[i] = binary % 2;
	    binary = binary / 2;
	}
	cout << "Binary= ";
	for (int j = i - 1; j >= 0; j--)
	{
	    cout << NUM[j];
	}
	cout << endl;
    }

    void Dec_to_oct()  //Decimal to octal
    {
	octal = decimal;
	for (i = 0; octal != 0; i++)
	{
	    NUM[i] = octal % 8;
	    octal = octal / 8;
	}
	cout << "Octal= ";
	for (int j = i - 1; j >= 0; j--)
	{
	    cout << NUM[j];
	}
	cout << endl;
    }

    void Dec_to_hex()  //Decimal to hexadecimal
    {
	hexadecimal = decimal;
	for (i = 0; hexadecimal != 0; i++)
	{
	    NUM[i] = hexadecimal % 16;
	    hexadecimal = hexadecimal / 16;
	}
	cout << "Hexadecimal= ";
	for (int j = i - 1; j >= 0; j--)
	{
	    if (NUM[j] >= 10)
	    {
		cout << (char)('A' + NUM[j] - 10);
	    }
	    else
	    {
		cout << NUM[j];
	    }
	}
	cout << endl;
    }
};

class Binary_to_all :virtual public Decimal_to_all  //Binary to all conversion
{
public:
    void Bin_to_dec()
    {
	cout << "Enter a Binary number(0-1): ";
	cin >> binary;
	decimal = 0;
	for (i = 0; binary != 0; i++)
	{
	    decimal = decimal + pow(2, i) * (binary % 10);
	    binary = binary / 10;
	}
	cout << "Decimal= " << decimal;
	cout << endl;
    }

    void Bin_to_oct()  //Binary to octal
    {
	Dec_to_oct();
    }

    void Bin_to_hex() //Binary to hexadecimal
    {
	Dec_to_hex();
    }
};

class Octal_to_all :virtual public Decimal_to_all //Octal to all conversion
{
public:
    void Oct_to_dec()  //Octal to decimal
    {
	cout << "Enter an Octal number(0-7): ";
	cin >> octal;
	decimal = 0;
	for (i = 0; octal != 0; i++)
	{
	    decimal = decimal + pow(8, i) * (octal % 10);
	    octal = octal / 10;
	}
	cout << "Decimal= " << decimal;
	cout << endl;
    }

    void Oct_to_bin()  //Octal to binary
    {
	Dec_to_bin();
    }

    void Oct_to_hex()   //Octal to hexadecimal
    {
	Dec_to_hex();
    }
};

class Hexadecimal_to_all : virtual public Decimal_to_all  //Hexadecimal to all cnversion
{
public:
    void Hex_to_dec() //Hexadecimal to decimal
    {
	cout << "Enter a Hexadecimal number(0-9,A-F): ";
	scanf("%x", &decimal);
	printf("Decimal= %d", decimal);
	cout << endl;
    }

    void Hex_to_bin()  //hexadecimal to binary
    {
	Dec_to_bin();
    }

    void Hex_to_oct()  //Hexadecimal to octal
    {
	Dec_to_oct();
    }
};

int main()
{
    Decimal_to_all obj1;
    Binary_to_all obj2;
    Octal_to_all obj3;
    Hexadecimal_to_all obj4;
    int ch;
    clrscr();

    cout << "*Number Conversion*" << endl;
    do
    {
	cout << "1.Decimal to all conversion\n2.Binary to all conversion\n3.Octal to all conversion\n4.Hexadecimal to all\n5.Exit" << endl;
	cout << "Enter your choice: ";
	cin >> ch;
	switch (ch)
	{
	case 1:
	    obj1.get();
	    obj1.Dec_to_bin();
	    obj1.Dec_to_oct();
	    obj1.Dec_to_hex();
	    cout << endl;
	    break;
	case 2:
	    obj2.Bin_to_dec();
	    obj2.Bin_to_oct();
	    obj2.Bin_to_hex();
	    cout << endl;
	    break;
	case 3:
	    obj3.Oct_to_dec();
	    obj3.Oct_to_bin();
	    obj3.Oct_to_hex();
	    cout << endl;
	    break;
	case 4:
	    obj4.Hex_to_dec();
	    obj4.Hex_to_bin();
	    obj4.Hex_to_oct();
	    cout << endl;
	    break;
	case 5:
	    cout << "*Program Terminated*" << endl;
	    break;
	default:
	    cout << "Invalid Choice!" << endl;
	}
    } while (ch != 5);
    getch();
}
