/*
 * helper.cpp
 *
 *  Created on: May 29, 2020
 *      Author: rohit
 */

#include <iostream>
#include "main.hpp"

using namespace std;

int product::itemCount = 0;

product::product(void)
{
	codeNo = 0;
	value = 0;
	++itemCount;
}

product::product(int i, float f)
{
	codeNo = i;
	value = f;
	++itemCount;
}

void product::display()
{
	cout << "CodeNo = " << codeNo << endl;
	cout << "Value = " << value << endl;
}

void product::displayCount()
{
	cout << "Item list number = " << itemCount << endl;
}

// Employee methods here
Employee::Employee()
{
	memset(m_name, 0x00, LEN);
	m_employeeNumber = 0;
	m_basic = 0.0;
	cout << "This is Employee constructor" << endl;
}

void Employee::inputData(char *name, int num)
{
	memcpy(m_name, name, LEN);
	m_employeeNumber = num;
}

void Employee::printData()
{
	cout << "Name = " << m_name << endl;
	cout << "Employee number = " << m_employeeNumber << endl;
	cout << "Basic Salary = " << m_basic << endl;
}

void Employee::inputBasic(float sal)
{
	m_basic = sal;
}
Employee::~Employee()
{
	cout << "This is Employee Desctructor" << endl;
}


// manager methods here
Manager::Manager()
{
	cout << "This is Manager constructor" << endl;
	memset(m_title, 0x00, LEN);
	//Employee();
}

void Manager::inputData(char *name, int num, float sal)
{
	Employee::inputData(name, num);
	Employee::inputBasic(sal);
}

void Manager::printData()
{
	//Employee::printData();
	cout << "Name is = " << m_basic << endl;
}

Manager::~Manager()
{
	cout << "This is Manager Desctructor" << endl;
}

Graduate_Student::Graduate_Student(){
	char emp;
	cout << "Enter subject :";
	cin >> m_subject;
	cout << endl;
	cout << "Enter employement status: E = Employed / U = unemployed ";
	cin >> emp;
	if(emp == 'E' || emp == 'e'){
		setEmpStat(1);
	}
	else{
		setEmpStat(0);
	}
	cout << endl;
}

Student::Student():m_rollNo(0), m_avgMarks(0){
	cout << "Enter roll number :";
	cin >> m_rollNo;
	cout << endl;
	cout << "Enter average marks :";
	cin >> m_avgMarks;
	cout << endl;
}

Person::Person():m_age(0){
	cout << "Enter Name :";
	cin >> m_name;
	cout << endl;
	cout << "Enter age :";
	cin >> m_age;
	cout << endl;
}

void Graduate_Student::printData(){
	Student::printData();
	cout << "Subject = " << m_subject << endl;
	if(m_employed){
		cout << "Emp status = Employed !" << endl;
	}
	else{
		cout << "Emp status = Unemployed" << endl;
	}
}

void Student::printData(){
	Person::printData();
	cout << "Roll number = " << getRollNum() << endl;
	cout << "Averg marks = " << getAvgMarks() << endl;
}

void Person::printData(){
	cout << "Name = " << getName() << endl;
	cout << "Age = " << getAge() << endl;
}

template <class T>
T* usePool<T>::checkout(){
	m_data = m_data + 9;
	m_allocatedSpace = m_allocatedSpace + 10;
	return m_data;
}

template <class T>
bool usePool<T>::checkin(T *instance){
	m_data = m_data - 10;
	m_allocatedSpace = m_allocatedSpace - 10;
	return 1;
}
//T* usePool::checkout();
//bool usePool::checkin(T* instance);
