/*
 * main.hpp
 *
 *  Created on: May 23, 2020
 *      Author: rohit
 */
#ifndef MAIN_HPP_
#define MAIN_HPP_

#include <string>
#include <string.h>
#include <fstream>
#include <cassert>
//#include <fstream>

#define LEN	24
typedef uint32_t size_bit;

// structs:
struct gradStu
{
	char name[50];
	float avgMarks;
};

enum class Color{red, blue, green};

// abstraction using classes
class memLyoutClass
{
private:
	//uint32_t publicValue;
	size_bit var1;
	size_bit var2;
	size_bit var3;
	size_bit var4;

public:
	// polymorphism using function overloading
	memLyoutClass(uint32_t val1, uint32_t val2):var1{val1}, var2{val2}, var3{val1+val2}, var4{val1-val2}{}
	memLyoutClass(uint32_t val1) : var1{val1}{}

	// encapsulation
	size_bit getVar1() { return var1;}
	size_bit getVar2() { return var2;}
	size_bit getVar3() { return var3;}
	size_bit getVar4() { return var4;}

	// polymorphism using function overloading
	size_bit method_add(size_bit val1, size_bit val2, size_bit val3) { return (val1 + val2); }
	size_bit method_add(size_bit val1, size_bit val2) { return (val1 + val2); }
	size_bit method_add() { return (var1 + var2 + var3 + var4); }

	// operator overloading
	memLyoutClass& operator+=(memLyoutClass& c){ c.var1+=var1; c.var1+=var1; c.var1+=var1; c.var1+=var1; return c;}

	//uint32_t privateValue;
};

// inheriatnce example
class vehical
{
public:
	vehical(size_bit s, size_bit fcap):
		m_speed{s}, m_fuelCap{fcap}{}

	void setSpeed(size_bit s){m_speed = s;}
	void setFuelCapacity(size_bit f){m_fuelCap = f;}
	size_bit getFuelCapacity(){return m_fuelCap;}

	virtual size_bit getSpeed() = 0;
	virtual ~vehical(){}
protected:
	size_bit m_speed;
private:
	size_bit m_fuelCap;
};

class car:public vehical
{
public:
	car(size_bit s, size_bit fcap):
		vehical(s, fcap){}
	size_bit getSpeed(){return m_speed;}
protected:

private:

};

//abstraction example
// creating an abstract class
class person
{
public:
	person():m_age{0}, m_gender{0}{}		// default constructor
	person(size_bit age, size_bit gender):	// parametric constructor
		m_age{age}, m_gender{gender}{}
	virtual ~person() {}					// virtual destructor
	virtual void setAge(size_bit ) = 0;		// pure virtual functions
	virtual void setGender(size_bit ) = 0;
	size_bit m_age;
	size_bit m_gender;
};

// usage of abstract class
class employee: public person
{
public:
	employee(char * name, size_bit empNum):person(0,0){memcpy(m_name, name, 50); m_Number = empNum;}
	void setAge(size_bit age){m_age = age;}
	void setGender(size_bit gender){m_gender = gender;}
	size_bit getAge(){return m_age;}
	char* getName(){return m_name;}
private:
	char m_name[50];
	size_bit m_Number;
};

// friend class example:
class A;
class B;

class B
{
public:
	B(size_bit val1, size_bit val2):classBVar1{val1}, classBVar2{val2}{}
	friend class A;
private:
	size_bit classBVar1;
	size_bit classBVar2;
};

class A
{
public:
	A(size_bit val1, size_bit val2):classAVar1{val1}, classAVar2{val2}{}
	//size_bit getClassBVar();
private:
	size_bit classAVar1;
	size_bit classAVar2;
};

class product
{
private:
	int codeNo;
	float value;
	static int itemCount;
public:
	product();
	product(int, float);

	void display();
	static void displayCount();
};

class Employee
{
private:
	char m_name[LEN];
	int m_employeeNumber;
public:
	Employee();
	void inputData(char *name, int num);
	void printData();

	~Employee();
protected:
	float m_basic;
	void inputBasic(float sal);
};

class Manager : public Employee
{
private:
	char m_title[LEN];
public:
	Manager();
	void inputData(char *name, int num, float sal);
	void printData();
	~Manager();
};



/**
 * Multi level inheritance example
 * */
//Person is the base class in this case
class Person{
private:
	char m_name[LEN];
	int m_age;
public:
	Person();
	void setName(char *);
	void setAge(int);
	char * getName(){return m_name;}
	int getAge(){return m_age;}
	void printData();
};

// Student is derived from person
class Student:public Person
{
private:
	int m_rollNo;
	int m_avgMarks;
public:
	Student();
	void setRollNum(int);
	void setAvgMarks(int);
	int getRollNum(){return m_rollNo;}
	int getAvgMarks(){return m_avgMarks;}
	void printData();
};

// Graduate_Student is derived from Student
class Graduate_Student:public Student
{
private:
	char m_subject[LEN];
	bool m_employed;
public:
	Graduate_Student();
	void setSubject(char*);
	void setEmpStat(bool emp){m_employed = emp;}
	char *getSubject(){return m_subject;}
	bool getEmpStat(){return m_employed;}
	void printData();
};



// base and derived class for virtual functions
class Base{
protected:
	int m_value;

public:
	Base(int val):m_value{val}{
	}
	std::string getName() const { return "Base"; }
	int getValue() const { return m_value; }
};

class Derived:public Base{
public:
	Derived(int val):Base{val}{}
	std::string getName() const { return "Derived"; }
	int getValueDoubled() const { return (m_value*2); }
};

// Virtual functions
class Animal{
protected:
	std::string m_name;
	Animal(std::string &name):m_name{name}{}

public:
	const std::string& getName() const { return m_name;}
	// using pure virtual function:
	virtual std::string speak() = 0;
	// using non pure virtual function
	//virtual std::string speak() const { return "???"; }
	virtual Animal* getThis() {return this;}
};

class Cat: public Animal{
public:
	Cat(std::string name):Animal{name}{}
	std::string speak() override { return "Meow"; }
	Cat* getThis() override { return this;}
};

class Dog: public Animal{
public:
	Dog(std::string name):Animal{name}{}
	std::string speak() override { return "Woof"; }
	Dog* getThis() override { return this; }
};

class Cow:public Animal{
public:
	Cow(std::string name):Animal(name){}
	std::string speak() override { return "Moo"; }
};

class Duck:public Animal{
public:
	Duck(std::string name):Animal(name){}
	// the following gets called if uncommented
	//std::string speak() override { return "Quack Quack"; }
	std::string speak() override{
		return Animal::speak();
	}
};

// pure virtual class = Interface class
class IErrorLog{
public:
	virtual bool openLog(const char *fileName) = 0;
	virtual bool closeLog() = 0;
	virtual bool writeError(const char *errorMessage) = 0;
	virtual ~IErrorLog() {}	// this is vitual destructor
};

class FileErrorLog:public IErrorLog{
private:
	std::fstream m_fio;
	char *m_fileName;

public:
	FileErrorLog(const char *fname);
	~FileErrorLog(){
		closeLog();
	}

	bool openLog(const char *fileName);
	bool closeLog();
	bool writeError(const char* errorMessage);
};

class ScreenErrorLog:public IErrorLog{

};

// Virtual Base class:
class PoweredDevice{
public:
	PoweredDevice(int power)
	{
		std::cout << "PoweredDevice: " << power << std::endl;
	}
};

class Scanner:virtual public PoweredDevice{
public:
	Scanner(int scanner, int power):
		PoweredDevice(power){
		std::cout << "Scanner: " << scanner << std::endl;
	}
};

class Printer:virtual public PoweredDevice{
public:
	Printer(int printer, int power)
		:PoweredDevice(power){
		std::cout << "Printer: " << printer << std::endl;
	}
};

class Copier: public Scanner, public Printer{
public:
	Copier(int scanner, int printer, int power):
		PoweredDevice(power),
		Scanner(scanner, power), Printer(printer, power){}
};

// operator overloading
class Cents{
private:
	int m_cents;
public:
	Cents(int cents):m_cents{cents}{}
	int getCents(){return m_cents;}
	friend bool operator>(const Cents &c1, const Cents &c2)
	{
		return(c1.m_cents > c2.m_cents);
	}
	friend std::ostream& operator<<(std::ostream& out, const Cents &cents)
	{
		out << cents.m_cents << " cents";
		return out;
	}
	Cents &operator+(const Cents &cents)
	{
		m_cents = m_cents + cents.m_cents;
		return *this;
	}
	Cents &operator/(int value)
	{
		m_cents = m_cents / value;
		return *this;
	}
};

// template function example:
template <typename T>			// this is the template param declaration
const T& maxRohit(const T& x, const T& y){
	return (x>y)?x:y;
}

// template class examples:
template <class TC>
TC averageRohit(TC* array, int length){
	TC sum(0);
	int count = 0;
	for(count=0; count < length; count++)
	{
		sum = sum + array[count];
	}
	sum = sum/length;
	return sum;
}

template <class TCA>
class Array{
private:
	int m_length{};
	TCA *m_data{};
public:
	Array(int length):m_length{length}{
		if(length > 0){
			m_data = new TCA[length];
		}
	};
	~Array(){
		printf("Destructor called\n");
		delete[] m_data;
	}
	void erase(){
		delete[] m_data;
		m_data = nullptr;
		m_length = 0;
	}
	TCA& operator[](int index){
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}
	int getLength() const {return m_length;}

	void reallocate(int newLength){
		erase();
		if(newLength <= 0)
			return;
		m_data = new TCA[newLength];
		m_length = newLength;
	}

	void resize(int newLength){
		if(newLength == m_length)
			return;
		if(newLength <= 0){
			erase();
			return;
		}

		int *data = new TCA[newLength];

		if(m_length > 0){
			int elementsToCopy = ((newLength > m_length)?m_length:newLength);
			for(int index = 0; index < elementsToCopy; ++index){
				data[index] = m_data[index];
			}
		}
		delete[] m_data;

		m_data = data;
		m_length = newLength;
	}

	void insertBefore(TCA value, int index){
		assert(index >= 0 && index <= m_length);
		printf("Inserting %d at index %d\n", value, index);
		int *data = new TCA[m_length+1];
		for(int before = 0; before < index; ++before)
			data[before] = m_data[before];

		data[index] = value;
		for(int after{index};after<=m_length;++after){
			data[after+1] = m_data[after];
		}

		delete[] m_data;
		m_data = data;
		m_length = m_length + 1;
	}
	void remove(int index){
		assert(index >=0 && index < m_length);
		printf("Removing from index %d\n", index);
		if(m_length == 1){
			erase();
			return;
		}

		int *data = new TCA[m_length-1];
		int before;
		for(before = 0; before < index; ++before){
			data[before] = m_data[before];
		}
		int after = index +1;
		for(;after<=m_length; ++after){
			data[after-1] = m_data[after];
		}
		delete[] m_data;
		m_data = data;
		m_length = m_length-1;
	}
	void insertAtBeginning(TCA value){insertBefore(value, 0);}
	void insertAtEnd(TCA value){insertBefore(value, m_length);}
	void print(){
		printf("Contents:\n");
		for(int index{0}; index<m_length; ++index){
			//printf("%d ", m_data[index]);
			std::cout << m_data[index] << " ";
		}
		printf("\n");
	}
};

class IntArray{
private:
	int m_length{};
	int *m_data{};
public:
	IntArray() = default;
	IntArray(int length):m_length{length}{
		if(length > 0){
			m_data = new int[length];
		}
	};
	~IntArray(){
		printf("Destructor called\n");
		delete[] m_data;
	}
	void erase(){
		delete[] m_data;
		m_data = nullptr;
		m_length = 0;
	}
	int& operator[](int index){
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}
	int getLength() const {return m_length;}

	void reallocate(int newLength){
		erase();
		if(newLength <= 0)
			return;
		m_data = new int[newLength];
		m_length = newLength;
	}

	void resize(int newLength){
		if(newLength == m_length)
			return;
		if(newLength <= 0){
			erase();
			return;
		}

		int *data = new int[newLength];

		if(m_length > 0){
			int elementsToCopy = ((newLength > m_length)?m_length:newLength);
			for(int index = 0; index < elementsToCopy; ++index){
				data[index] = m_data[index];
			}
		}
		delete[] m_data;

		m_data = data;
		m_length = newLength;
	}

	void insertBefore(int value, int index){
		assert(index >= 0 && index <= m_length);
		printf("Inserting %d at index %d\n", value, index);
		int *data = new int[m_length+1];
		for(int before = 0; before < index; ++before)
			data[before] = m_data[before];

		data[index] = value;
		for(int after{index};after<=m_length;++after){
			data[after+1] = m_data[after];
		}

		delete[] m_data;
		m_data = data;
		m_length = m_length + 1;
	}
	void remove(int index){
		assert(index >=0 && index < m_length);
		printf("Removing from index %d\n", index);
		if(m_length == 1){
			erase();
			return;
		}

		int *data = new int[m_length-1];
		int before;
		for(before = 0; before < index; ++before){
			data[before] = m_data[before];
		}
		int after = index +1;
		for(;after<=m_length; ++after){
			data[after-1] = m_data[after];
		}
		delete[] m_data;
		m_data = data;
		m_length = m_length-1;
	}
	void insertAtBeginning(int value){insertBefore(value, 0);}
	void insertAtEnd(int value){insertBefore(value, m_length);}
	void print(){
		printf("Contents:\n");
		for(int index{0}; index<m_length; ++index){
			printf("%d ", m_data[index]);
		}
		printf("\n");
	}

};

template <class T>
class Pool
{
public:
	// this will return a value from the available pool of mem
	virtual T* checkout() = 0;

	// this will get
	virtual bool checkin(T* instance) = 0;

	virtual ~Pool() = 0;
};

// assuming that only 10 bytes are requested at every checkout and so
// 10 bytes will be release at checkin
template <class T>
class usePool:public Pool<T>{
private:
	T* m_dataBase;
	T* m_data;
	int m_allocatedSpace;
public:
	usePool(){
		m_data = nullptr;
		// initialize with memory allocation for 1000 ints = 1000*4 = 4000 bytes
		m_dataBase = new T[1000];
		m_data = m_dataBase;
		m_allocatedSpace = 0;
	}
	T* checkout();
	bool checkin(T* instance);
	T getDataBaseAddress(){return m_dataBase;}
	T getDataAddress(){return m_data;}
	int getAllocatesSpace(){return m_allocatedSpace;}

	//~usePool(){delete[] m_data;}
	~usePool();
};

// main function declerations here:
void vlearnFundamentalTypes();
void vlearnConstantTypes();
void vlearnArithmatics();
void vlearnBitManipulation();
void learnMemLayout();
void vPrintFromFile();
void vReadBinaryFile();
void vLearnEnumClass();
void vLearnEncapsulation();
void vLearnInheritance();
void vLearnAbstraction();
void vLearnFriendFunc();
void vLearnPointer();
void vLearnStatic();
void vLearnInheritance1();
void vLearnInheritance2();
void vLearnVirtualFunctions();
void vLearnVtable();
void vlearnFileHandling1();
void vlearnFileHandling2();
void vlearnStringHandling();
void vlearnTemplates();
void vlearnContainers();
void vlearnMemPool();

// helper function declerations:
void memAlloc();
int add(int , int& );
bool isAlmostEqual(double a, double b, double epsilon);
bool approxEqual(double a, double b, double epsilon);
double mySqrt(double value, FileErrorLog &log);

#endif /* MAIN_HPP_ */
