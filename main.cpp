/*
 * main.cpp
 *
 *  Created on: May 17, 2020
 *      Author: rohit
 */

#include <cstdint>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <dirent.h>
#include <string>
#include <memory>
#include <iostream>
#include <bitset>
#include <cmath>

#include "main.hpp"

using namespace std;
using namespace std::chrono;

//#define FUNDAMENTAL_TYPES
//#define CONSTANT_TYPES
//#define ARITHMATIC
#define BIT_MANIPULATION
//#define READ_BINARY_IN_CPP
//#define CPP_MACROS
//#define PRINT_LAST_K_LINES_IN_A_FILE
//#define MEMORY_LAYOUT
//#define MEM_ALLOC_CPP
//#define INHERITANCE
//#define ABSTRACTION
//#define FRIEND_FUNCTION
//#define LEARNPOINTER
//#define LEARNSTATIC
//#define INHERITANCE1
//#define INHERITANCE2
//#define FILE_HANDLING1
//#define FILE_HANDLING2
//#define STRING_HANDLING
//#define LEARN_TEMPLATES
//#define LEARN_CONTAINERS
//#define MEM_POOL_PATTERN


Color& operator++(Color& c)
{
	switch(c)
	{
	case Color::red:
		c = Color::blue;
		break;
	case Color::blue:
		c = Color::green;
		break;
	case Color::green:
		c = Color::red;
		break;
	}
	return c;
}

Color& printColor(Color& c)
{
	switch(c)
	{
	case Color::red:
		cout << "Color is red\n";
		break;
	case Color::blue:
		cout << "Color is blue\n";
		break;
	case Color::green:
		cout << "Color is green\n";
		break;
	}
	return c;
}

int main()
{
	cout << "C++ version = " << __cplusplus << "\nCompilation Date is " << __DATE__ << "\nCompilation Time is " << __TIME__ << endl << endl;

#ifdef FUNDAMENTAL_TYPES
	vlearnFundamentalTypes();
#endif

#ifdef CONSTANT_TYPES
	vlearnConstantTypes();
#endif

#ifdef ARITHMATIC
	vlearnArithmatics();
#endif

#ifdef BIT_MANIPULATION
	vlearnBitManipulation();
#endif

#ifdef PRINT_LAST_K_LINES_IN_A_FILE
	vPrintFromFile();
#endif

#ifdef READ_BINARY_IN_CPP
	vReadBinaryFile();
#endif

#ifdef CPP_MACROS
	cout << __func__ << "() in file " << __FILE__ << " on line " << __LINE__ << endl;
	cout << "C++ compiler version = " << __cplusplus << endl;
	cout << "Compilation Date is " << __DATE__ << endl;
	cout << "Compilation Time is " << __TIME__ << endl;
	auto d = steady_clock::now() - t;
#endif

#ifdef MEMORY_LAYOUT
	learnMemLayout();
#endif

#ifdef MEM_ALLOC_CPP
	memAlloc();
#endif

#ifdef INHERITANCE
	vLearnInheritance();
#endif

#ifdef ABSTRACTION
	vLearnAbstraction();
#endif

#ifdef FRIEND_FUNCTION
	vLearnFriendFunc();
#endif

#ifdef LEARNPOINTER
	vLearnPointer();
#endif

#ifdef LEARNSTATIC
	vLearnStatic();
#endif

#ifdef INHERITANCE1
	vLearnInheritance1();
#endif

#ifdef INHERITANCE2
	vLearnInheritance2();
#endif

#ifdef FILE_HANDLING1
	vlearnFileHandling1();
#endif

#ifdef FILE_HANDLING2
	vlearnFileHandling2();
#endif

#ifdef STRING_HANDLING
	vlearnStringHandling();
#endif

#ifdef LEARN_TEMPLATES
	vlearnTemplates();
#endif

#ifdef LEARN_CONTAINERS
	vlearnContainers();
#endif

#ifdef MEM_POOL_PATTERN
	vlearnMemPool();
#endif

	printf("\nProgram execution completed\n");
	return 0;
}

void vlearnFundamentalTypes(){
	cout << "This function is to learn about fundamental types in C++11\n";
	bool boolVar = false;								// 1 byte

	char charVar = 'A';								// 1 byte
	wchar_t wcharVar = 'B';							// 1 byte
	char16_t char16_tVar = 'C';						// 2 bytes
	char32_t char32_tVar = 'D';						// 4 bytes

	short shortVar = 1;								// 2 bytes
	int intVar = 2;									// 4 bytes
	long longVar = 3;								// 4 bytes
	long long longlongVar = 4;						// 8 bytes

	float floatVar = 3.14f;							// 4 bytes
	double doubleVar = 4.14;						// 8 bytes
	long double longdoubleVar = 5.14;				// 8 Bytes

	cout << "Type \t\t Value \t\t sizeof" << endl;
	cout << "boolVar \t " << boolVar << "\t\t" << sizeof(boolVar) << endl;

	cout << "charVar \t" << charVar << "\t\t" << sizeof(charVar) << endl;
	cout << "wcharVar \t" << wcharVar << "\t\t" << sizeof(wcharVar) << endl;
	cout << "char16_tVar\t" << char16_tVar << "\t\t" << sizeof(char16_tVar) << endl;
	cout << "char32_tVar\t" << char32_tVar << "\t\t" << sizeof(char32_tVar) << endl;

	cout << "shortVar \t" << shortVar << "\t\t" << sizeof(shortVar) << endl;
	cout << "intVar \t\t" << intVar << "\t\t" << sizeof(intVar) << endl;
	cout << "longVar \t" << longVar << "\t\t" << sizeof(longVar) << endl;
	cout << "longlongVar \t" << longlongVar << "\t\t" << sizeof(longlongVar) << endl;

	cout << "floatVar \t" << floatVar << "\t\t" << sizeof(floatVar) << endl;
	cout << "doubleVar \t" << doubleVar << "\t\t" << sizeof(doubleVar) << endl;
	cout << "longdoubleVar \t" << longdoubleVar << "\t\t" << sizeof(longdoubleVar) << endl << endl;

	// Fixed width integers:
	int8_t num = 55;
	// in the following line c++ takes the int8_t variable and uses that as a character so it prints its ASCII value
	cout << "using std::cout \nint8_t Number = " << num << " Size = " << sizeof(num) << endl;
	// in the following line we are explicitly type casting that variable as int and so 55 is getting printed
	cout << "using std::cout with static cast\nint8_t Number = " << static_cast<int>(num) << " Size = " << sizeof(num) << endl;
	printf("using printf int8_t Number = %d \n\n", num);


	// binary and hex representation in C++14
	int binVal{};
	int hexVal{0x55};
	int binVal2{ 0b01011010 };

	binVal = 0b10101010;
	cout << "cout -> Binary number = " << binVal << endl;
	printf("printf -> Binary number = 0x%X\n", binVal);

	cout << "cout -> Hex number = " << hexVal << endl;
	printf("printf -> Hex number = 0x%X\n\n", hexVal);

	// print formatting in C++ using cout
	int x{ 12 };
	cout << "Decimal mode = " << x << '\n'; 					// decimal print
	cout << "Hex mode = 0x" << std::hex << x << '\n';				// hex mode
	cout << "Still in Hex mode = 0x" << x << '\n';				// still in hex mode
	cout << "Octal mode = " << std::oct << x << endl;
	cout << "Back in decimal mode = " << std::dec << x << endl;
	cout << "Binary mode = " << bitset<8>(x) << endl;

}

void vlearnConstantTypes(){
	cout << "This function is to learn about constants in C++11 \n";

	// compile time constant
	const int value { 10 };
	cout << "const value = " << value << endl;
	//value = 11;			// compiler error

	// run time constant as the value of userNum is defined by
	// user at the time when program is running
	int num;
	cout << "Enter a number :";
	cin >> num;
	const int userNum{ num };
	cout << "userNum = " << userNum << endl;


	// C++11 to ensure it is compile time constant 'constexpr' is used
	constexpr int newValue { 12 };

}

void vlearnArithmatics(){
	cout << "This function is to learn about arithmatic operations in C++11 \n";
	int x {7};
	int y {4};
	cout << "x = " << x << ", y = " << x << endl;
	// get quotient after division
	cout << "int/int = " << x / y << endl;
	cout << "double/int = " << static_cast<double>(x) / y << endl;
	cout << "int/double = " << x / static_cast<double>(y) << endl;
	cout << "double/double = " << static_cast<double>(x) / static_cast<double>(y) << endl;

	// get remainder after division: modulus (remainder opetrator)
	cout << "remainder of x/y = " << x%y << endl;
	x = -x;
	cout << "remainder of -x/y = " << x%y << endl;

	// exponentiation:
	double exp{0.0};
	exp = pow(4.0,3.0);
	cout << "4^3 = " << exp << endl;

	// pre and post inc/dec operators;
	x = 2;
	y = 7;
	cout << "x = " << x << ", y = " << y << endl;
	y = ++x;											// increment and then return
	cout << "x = " << x << ", y = " << y << endl;
	x = 2;
	y = 7;
	y = x++;
	cout << "x = " << x << ", y = " << y << endl;

	// comma operator, this evaluates first operand and returns 2nd operand
	// so the follwowing returns y
	cout << (x,y) << endl;

	// conditional operator c?x:y
	(x<y)?x=100:y=100;
	cout << "x = " << x << ", y = " << y << endl;

	// floating point comparisons
	// == and != should be avoided with floating point
	double d1{100.00 - 99.99};
	double d2{10.0 - 9.99};
	cout << "d1 = " << d1 << " d2 = " << d2 << endl;
	printf("d1 = %lf, d2 = %lf\n", d1, d2);
	if(d1 == d2)
		cout << "d1 == d2" << endl;
	else if(d1 > d2)
		cout << "d1 > d2" << endl;
	else if(d1 < d2)
		cout << "d1 < d2" << endl;

	// floating point comparison using a particular precision
	double ep = 0.00000001;
	cout << "d1 and d2 are they close enough ? (1=true,0=false) = " << isAlmostEqual(d1, d2, ep) << endl;
	ep = 0.01;
	cout << "d1 and d2 are they close enough ? (1=true,0=false) = " << approxEqual(d1, d2, ep) << endl;

}

void vlearnBitManipulation(){
	cout << "This function is to learn about arithmatic operations in C++11 \n";

	// bit handling using bitset
	bitset<8> bits{0b01100101};
	cout << "Bit pos 0 = " << bits.test(0) << endl;
	cout << "Bit pos 1 = " << bits.test(1) << endl;
	cout << "Bit pos 2 = " << bits.test(2) << endl;
	cout << "Bit pos 3 = " << bits.test(3) << endl;
	cout << "Bit pos 4 = " << bits.test(4) << endl;
	cout << "Bit pos 5 = " << bits.test(5) << endl;
	cout << "Bit pos 6 = " << bits.test(6) << endl;
	cout << "Bit pos 7 = " << bits.test(7) << endl;

	bits.set(3);		// make this bit to 1
	bits.flip(0);		// toggle this bit
	bits.reset(5);		// make this bit to 0

	// bit shifting:
	// left shift is multiplication
	// right shift is division
	cout << "Bit shifting demo: \n";
	uint32_t myVal {0x01};
	int index = 0;

	cout << "Init val  myVal = " << bitset<8>(myVal) << " = " << myVal << endl;

	// using for loop
	for(index=0; index < 7; ++index){
		myVal = myVal << 1;
		cout << "Left shift by 1 = " << bitset<8>(myVal) << " = " << myVal << endl;
	}
#if 0
	myVal = myVal << 1;		//left shift
	cout << "Left shift by 1 = " << bitset<8>(myVal) << " = " << myVal << endl;
	myVal = myVal << 1;		//left shift
	cout << "Left shift by 1 = " << bitset<8>(myVal) << " = " << myVal << endl;
	myVal = myVal << 1;		//left shift
	cout << "Left shift by 1 = " << bitset<8>(myVal) << " = " << myVal << endl;
	myVal = myVal << 1;		//left shift
	cout << "Left shift by 1 = " << bitset<8>(myVal) << " = " << myVal << endl;
	myVal = myVal << 1;		//left shift
	cout << "Left shift by 1 = " << bitset<8>(myVal) << " = " << myVal << endl;
	myVal = myVal << 1;		//left shift
	cout << "Left shift by 1 = " << bitset<8>(myVal) << " = " << myVal << endl;
	myVal = myVal << 1;		//left shift
	cout << "Left shift by 1 = " << bitset<8>(myVal) << " = " << myVal << endl;
#endif

	cout << "\nNow doing right shift by 1 and displaying result in binary and decimal\n\n";

	cout << "Init valu  myVal = " << bitset<8>(myVal) << " = " << myVal << endl;
	// using for loop
	for(index=0; index < 7; ++index){
		myVal = myVal >> 1;		//right shift
		cout << "Right shift by 1 = " << bitset<8>(myVal) << " = " << myVal << endl;
	}
#if 0
	myVal = myVal >> 1;		//right shift
	cout << "Right shift by 1 = " << bitset<8>(myVal) << " = " << myVal << endl;
	myVal = myVal >> 1;		//right shift
	cout << "Right shift by 1 = " << bitset<8>(myVal) << " = " << myVal << endl;
	myVal = myVal >> 1;		//right shift
	cout << "Right shift by 1 = " << bitset<8>(myVal) << " = " << myVal << endl;
	myVal = myVal >> 1;		//right shift
	cout << "Right shift by 1 = " << bitset<8>(myVal) << " = " << myVal << endl;
	myVal = myVal >> 1;		//right shift
	cout << "Right shift by 1 = " << bitset<8>(myVal) << " = " << myVal << endl;
	myVal = myVal >> 1;		//right shift
	cout << "Right shift by 1 = " << bitset<8>(myVal) << " = " << myVal << endl;
	myVal = myVal >> 1;		//right shift
	cout << "Right shift by 1 = " << bitset<8>(myVal) << " = " << myVal << endl;
	myVal = myVal >> 1;		//right shift
	cout << "Right shift by 1 = " << bitset<8>(myVal) << " = " << myVal << endl;
#endif
	cout << endl;
	// bitwise operators
	// OR = |
	// AND = &
	// NOT = ~
	// XOR = ^

	// Bit masking for C++11:
	constexpr uint_fast8_t mask0{ 1 << 0 }; // 0x01};
	constexpr uint_fast8_t mask1{ 1 << 1 }; // 0x02};
	constexpr uint_fast8_t mask2{ 1 << 2 }; // 0x03};
	constexpr uint_fast8_t mask3{ 1 << 3 }; // 0x04};
	constexpr uint_fast8_t mask4{ 1 << 4 }; // 0x05};
	constexpr uint_fast8_t mask5{ 1 << 5 }; // 0x06};
	constexpr uint_fast8_t mask6{ 1 << 6 }; // 0x07};
	constexpr uint_fast8_t mask7{ 1 << 7 }; // 0x08};

	uint_fast8_t flag{0xAA};
	cout << "flag = " << bitset<8>(flag) << endl;
	// testing a bit
	cout << "Bit 0 is = " << ((flag & mask0)?"on\n":"off\n");

	// setting bit 2 (use bitwise OR)
	flag = flag | mask2;
	cout << "flag = " << bitset<8>(flag) << " = 0x"	<< hex << static_cast<int>(flag) << endl;

	// multiple bit setting
	flag |= (mask4 | mask6);
	cout << "flag = " << bitset<8>(flag) << " = 0x"	<< hex << static_cast<int>(flag) << endl;

	// resetting bit 5,6 (use bitwise AND with NOT)
	flag = flag & ~(mask5 | mask6);
	cout << "flag = " << bitset<8>(flag) << " = 0x"	<< hex << static_cast<int>(flag) << endl;

	// toggle bit 2,3 (use bitwise XOR)
	flag = flag ^ (mask2 | mask3);
	cout << "flag = " << bitset<8>(flag) << " = 0x"	<< hex << static_cast<int>(flag) << endl;



}

void vPrintFromFile()
{
	// q13.1 print last k lines of a text file
	//FILE
#if 0
#define LAST_LINES_TO_RPINT_COUNT	6
	int line_count = 0;
	int lines_not_print = 0;
	fstream fs{};
	string s;

	fs.open("books.txt", ios_base::in);
	if(fs.good())
	{
		while(!fs.eof())
		{
			getline(fs, s);
			line_count++;
		}
		cout << "Line count = " << line_count << endl;
		fs.seekg (0, fs.beg);	//reset the position to start of file stream
		cout << "pos = " << fs.tellg() << endl;

		lines_not_print = line_count - LAST_LINES_TO_RPINT_COUNT;
		line_count = 0;
		while(!fs.eof())
		{
			getline(fs, s);
			if(line_count >= lines_not_print)
			{
				cout << s << endl;
			}
			line_count++;
		}

		fs.close();
	}
	else
	{
		cout << "unable to open the file" << endl;
	}
#endif
	fstream fs;
	fs.open("../tobuy.txt");
	if(fs.is_open() == false)
	{
		cerr << "Cannot open the file\n";
		exit(EXIT_FAILURE);
	}
	string s;
	while(fs){
		getline(fs, s, ':');		// delimiter = :
		//getline(fs, s);		// default delimiter = new line = \n
		cout << s << endl;
	}
	fs.close();
}

void vReadBinaryFile()
{
	fstream fs{};
	char ch;
	int binary_length = 0;
	fs.open("bootloader_stm32f4.bin", ios_base::in | ios_base::binary);
	if(!fs)
	{
		cout << "unable to open binary file" << endl;
	}
	else
	{
		//binary_length = 1;
		//cout << std::setiosflags (std::ios::showbase | std::ios::uppercase);
		cout << std::setiosflags (std::ios::uppercase);
		while(!fs.eof())
		{
			fs.get(ch);
			//cout << " " << ( ch & 0x00FF ) << hex;
			cout << setfill('0') << setw(2) << hex << ( ch & 0x00FF ) << " ";
			binary_length++;
			if(!(binary_length % 32))
			{
				cout << endl;
			}
			//printf("0x%02X, ",( ch & 0x00FF ) );
		}
		cout << endl << "binary length = " << binary_length << endl;
		fs.close();
	}
}

void learnMemLayout()
{
	//funcptr = 0;
	//ptr = 0;
	cout << "This is memlayout example" << endl;
	memLyoutClass obj1(1 ,2);
	cout << "Size of obj1 = " << sizeof(obj1) << endl;
	//cout << obj1.publicValue << endl;
	/*cout << "Address of the object is: " << &(obj1) << endl;
	cout << "Address of the  value is: " << &(obj1.var1) << endl;
	cout << "Address of the  value is: " << &(obj1.var2) << endl;
	cout << "Address of the  value is: " << &(obj1.var3) << endl;
	cout << "Address of the  value is: " << &(obj1.var4) << endl;*/
}

void vLearnEnumClass()
{
	//int x = 025;	// store octal value when you put 0(zero) before the value
	int a{1};
	int b = 2;
	printf("a = %d, b = %d\n", a, b);
	//cout << x;
	//printf("address of a = %016X\taddress of b = %016X\n", &a ,&b);
	add(a, b);
	printf("a = %d, b = %d\n", a, b);
	Color col = Color::red;
	printColor(col);
	++col;
	printColor(col);
	//cout << col << "\n";
}

void vLearnInheritance()
{
	cout << "This is Inheritance example" << endl;
	car myCar(50, 70);
	cout << "speed of myCar = " << myCar.getSpeed() << endl;
	cout << "Fuel  of myCar = " << myCar.getFuelCapacity() << endl;
	myCar.setFuelCapacity(100);
	cout << "Fuel  of myCar = " << myCar.getFuelCapacity() << endl;
}

void vLearnAbstraction()
{
	char name[] = "Rohit";
	cout << "This is Abstraction example" << endl;
	employee emp1(name, 101);
	cout << "Age is =" << emp1.getAge() << endl;
	cout << "Name is =" << emp1.getName() << endl;
}

void vLearnFriendFunc()
{
	cout << "This is friend function example" << endl;
	cout << "sizeof(char) = " << sizeof(char) << endl;
	cout << "sizeof(int) = " << sizeof(int) << endl;
	cout << "sizeof(float) = " << sizeof(float) << endl;
	cout << "sizeof(double) = " << sizeof(double) << endl;
	cout << "sizeof(long) = " << sizeof(long long unsigned int) << endl;
	A newClassA(5, 7);
	B newClassB(1, 2);
	//cout << newClassA.classBVar1 << endl;
	//cout << newClassA.classBVar1 << endl;
}

void vLearnPointer()
{
	cout << "This is pointer learning code" << endl;
	int *ptr;
	ptr = new int;
	if(ptr)
	{
		cout << "address pointed by ptr =  " << ptr << endl;
		delete ptr;
	}

	int *iptr = new int(5);
	if(iptr)
	{
		cout << "address pointed by iptr = " << iptr << endl;
		cout << "value at address pointed by iptr = " << *iptr << endl;
		delete iptr;
	}

	int *c_ptr;
	c_ptr = (int*)malloc(sizeof(int));
	if(c_ptr)
	{
		printf("address in c_ptr = 0x%p\n", (void*)c_ptr);
		*c_ptr = 75;
		printf("value at address in c_ptr = %d\n", *c_ptr);
		free(c_ptr);
	}

	int *aptr = new int[10];	// allocate 10 ints in the free store
	if(aptr)
	{
		cout << "Start Address of aptr = " << aptr << endl;
		delete aptr;
	}

	int *c_aptr;
	c_aptr = (int*)malloc(10 * sizeof(int));		// allocate memory for 10 ints
	for(int i = 0; i<10;i++)
	{
		c_aptr[i] = i;
	}
	if(c_aptr)
	{
		printf("address c_aptr = 0x%p\n", (void*)c_aptr);
		for(int i = 0; i<10;i++)
		{
			//printf("c_aptr[%d] = %d\t", c_aptr[i],i);
			printf("c_aptr[%d] = %d\t", *(c_ptr + i), i);
		}
		free(c_aptr);
	}

	// following 2 lines are same
	int const c_int1 = 10;
	const int c_int2 = 10;

	int n = 44;

	//1. constant pointer, this points to a constant address
	int *const cptr = &n;
	++(*cptr); 	// valid
	//++cptr;		// invalid


	//2. pointer to a constant
	const int kn = 88;
	const int *ptrC = &kn;
	//++(*ptrC);		// invalid as it is trying to modify a const value
	++ptrC;			// valid as it is incrementing the address being pointed

	//3. this is a constant pointer pointing to a constant
	const int *const cptrC = &kn;
	//++(*cptrC);			// invalid as here both address pointed by pointer and value at that address is a constant
	//++cptrC;			// invalid


	// Reference :
	float value = 1700.25;
	float & amt = value;
	cout << "amt = " << amt << endl;

	// SMART POINTERS:
}

void vLearnStatic()
{
	cout << "This is static example" << endl;
	product p1, p2(7, 15.4f);
	p1.display();
	p2.display();

	p1.displayCount();
	p2.displayCount();

	product p3(75, 15.22f);
	p3.displayCount();

}

void vLearnInheritance1()
{
	cout << "This is inheritance1 example" << endl;
	cout << "Size of Float = " << sizeof(float) << endl;
	cout << "Size of int = " << sizeof(int) << endl;
	cout << "Size of Base class = " << sizeof(Employee) << endl;
	cout << "Size of Derived class = " << sizeof(Manager) << endl;

	// access control in publicly derived class
	Manager m1, m2;
	char m1_name[] = "Vijay";
	char m2_name[] = "Rohit";

	m1.inputData(m1_name, 202, 10000);
	m1.printData();

	m2.inputData(m2_name, 205, 10000);
	m2.printData();

}

void vLearnInheritance2()
{
	cout << "This is inheritance 2 ex" << endl;
	//multilevel inheritance
	const int num_of_grads = 5;
	Graduate_Student g1[num_of_grads];
	g1[0].printData();
}

void vlearnFileHandling1()
{
	cout << "Example for file handling" << endl;

	fstream fio;
	fio.open("grad_student.txt", ios_base::in | ios_base::app);
	if(fio.good())
	{
		fio << "Details of grad students here:" << endl;
		cout << "File opened" << endl;
		Graduate_Student g1;
		//fio.write((char*)&g1, sizeof(g1));			// writing in form of bytes
		//gradStu g2;
		//fio.write((char*)&g2, sizeof(g2));

		// writing in form of char arrays (strings)
		fio << "Age = " << g1.getAge() << endl;
		fio << "Average marks = " << g1.getAvgMarks() << endl;
		fio << "Employment Status = " << g1.getEmpStat() << endl;
		cout << "get_pointer at " << fio.tellg() << endl;
		cout << "put_pointer at " << fio.tellp() << endl;
		fio.seekg(0, ios_base::beg);
		fio.seekp(0, ios_base::beg);
		cout << "get_pointer at " << fio.tellg() << endl;
		cout << "put_pointer at " << fio.tellp() << endl;
		fio << "Name = " << g1.getName() << endl;
		fio << "Roll num = " << g1.getRollNum() << endl;
		fio << "Subject = " << g1.getSubject() << endl;
		cout << "Details written to the file, now closing the file" << endl;
		fio.close();
	}
	else
	{
		cout << "unable to open the file " << endl;
	}
	fio.open("grad_student.txt", ios_base::in );
	if(fio.good())
	{
		char ch;
		cout << "File opened for reading " << endl;
		//while(fio)
		while(!fio.eof())
		{
			fio.get(ch);
			cout << ch;
		}
		fio.close();
	}

}

void vlearnFileHandling2()
{
	cout << "Example for file handling 2" << endl;
}

void vlearnStringHandling(){
#if 0
	cout << "This is string learning\n";
	string one("Hello world!");
	cout << one << endl;
	string two(20, '&');
	cout << two << endl;
	string three(one);
	cout << three << endl;

	one = one + "Earth";
	cout << one << endl;

	two = "Sorry that was ";
	cout << two << endl;

	three[0] = 'P';

	string four;
	four = two + three;
	cout << four << endl;

	char alls[] = "All's well that ends well";
	string five(alls, 50);
	cout << five << "!\n";

	string six(alls+6, alls+10);
	cout << six << ", ";

	string seven(&five[6], &five[10]);
	cout << seven << endl;
#endif
	cout << "Enter the string\n";
	// c-style strings
	//char info[100];
	//memset(info, 0x00, 100*sizeof(char));
	//int i = 0;
	//Options for getting the string from the command line tool:
	// 1.
	//cin >> info;
	// 2. read a line, discard \n
	//cin.getline(info, 100);
	// 3. read a line, leave \n in queue
	//cin.get(info, 100);		// this is for c-style string
	//cout << info << endl;
	//printf("info = ");
	//for(i=0;i<10;i++)
	//	printf("0x%02X ", info[i]);
	//printf("0x%02X ", info[99]);

	// string objects
	string stuff;
	//cin >> stuff;
	getline(cin, stuff);		// this is for c++ string object
	cout << stuff;


}

void vlearnTemplates()
{
	cout << "This is template handling \n";
	cout << maxRohit(2,3) << endl;
	cout << maxRohit(2.2556,3.3326) << endl;
	cout << maxRohit('a','6') << endl;

	Cents nickel(5);
	Cents dime(10);
	Cents bigger(maxRohit(nickel, dime));
	cout << "Bigger = " << bigger.getCents() << endl;

	int arr1[] = {5,3,2,1,4};
	cout << "Average = " << averageRohit(arr1, 5) << endl;

	double arr2[] = {3.14,2.55,65.5,5.5,6.0};
	cout << "Average = " << averageRohit(arr2, 5) << endl;

	Cents arr3[] = {Cents(5), Cents(10), Cents(15), Cents(14), Cents(22), Cents(7)};
	cout << "Average = " << averageRohit(arr3, 6) << endl;

	//Template class example below for container:
	Array<int> intArray(12);
	//Array<float> floatArray(20);
	for(int c{0}; c<intArray.getLength(); ++c)
	{
		intArray[c] = c+1;
	}
	intArray.print();
	intArray.insertAtBeginning(40);
	intArray.print();

	intArray.insertAtEnd(55);
	intArray.print();

	/*for(int c{0}; c<floatArray.getLength(); ++c)
	{
		floatArray[c] = c+5.55;
	}
	floatArray.print();*/


}

/*
template <class TCA>
int Array<TCA>::getLength()const{
	return m_length;
}*/

void vlearnContainers(){
	cout << "This is Container learning\n";
	IntArray array(10);
	try{
		for(int i{0};i<10;++i)
			array[i] = i+1;
		array.print();
		// Resize the array to 8 elements
		array.resize(8);
		array.print();

		// Insert the number 20 before element with index 5
		array.insertBefore(20, 5);
		array.print();

		// Remove the element with index 3
		array.remove(3);
		array.print();

		// Add 30 and 40 to the end and beginning
		array.insertAtEnd(30);
		array.print();
		array.insertAtBeginning(40);
		array.print();
	}
	catch(const char* e){
		printf("Exception caught: %s\n", e);
	}
}

void vlearnMemPool(){
	cout << "This is mem pool design pattern\n";
	// this section is omitted as the requirement for the memory pool question was unkonwn
	//up1.checkout();
}

