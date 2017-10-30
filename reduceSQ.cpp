// ConsoleApplication2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <string>
#include <sstream>
#include <chrono>
using namespace std;


int main()
{
	cout << "Start"<< endl;
	int randNum;
	//init srand with a seed based on time
	srand(time(NULL));
	int* arr = new int[160000000];

	//generates 160 million random numbers for the array
	for (int i = 0; i<160000000; i++)
	{
		arr[i] = rand() % 10 + 1;

	}
	cout << "Array Made" << endl;
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	int sum = 0;
	//sums the array
	for (int i = 0; i<160000000; i++)
	{
		sum = arr[i] + sum;

	}

	cout << sum << endl;
	cout << "Array Summed" << endl;
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds = end - start;
	//outputs the time it took to sum
	cout << elapsed_seconds.count() << std::endl;

	delete[] arr;
	system("pause");
	return 0;
}
