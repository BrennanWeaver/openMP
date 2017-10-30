// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <omp.h>
#include <stdio.h>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>
#include <chrono>
#include <windows.h>
#include <stdio.h>

using namespace std;

//int globalSum = 0;


//Sums the array with a starting and ending number, returns the sum  
int sumFucntion(int* arr, int start, int end)
{
	int lcSum = 0;
	for (int i = start; i<end; i++)
	{
		lcSum = arr[i] + lcSum;
	}

	return lcSum;
}

int main()
{
	omp_set_num_threads(16);
	//init srand with a seed based on time
	srand(time(NULL));
	int* arr = new int[160000000];
	std::cout << "Start" << endl;
	//generates 150 million random numbers for the array
	for (int i = 0; i<160000000; i++)
	{
		arr[i] = rand() % 10 + 1;

	}
	std::cout << "Array Made" << endl;
	int sumOne, sumTwo, sumThree, sumFour, sumFive, sumSix, sumSeven, sumEight, sumNine, sumTen, sum11, sum12, sum13, sum14, sum15, sum16 = 0;

	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();

	//Breaks the summing of the array into 16 tasks for 16 threads
#pragma omp parallel sections
	{
#pragma omp section
		sumOne = sumFucntion(arr, 0, 999999);
#pragma omp section
		sumTwo = sumFucntion(arr, 10000000, 19999999);
#pragma omp section
		sumThree = sumFucntion(arr, 20000000, 29999999);
#pragma omp section
		sumFour = sumFucntion(arr, 30000000, 39999999);
#pragma omp section
		sumFive = sumFucntion(arr, 40000000, 49999999);
#pragma omp section
		sumSix = sumFucntion(arr, 50000000, 59999999);
#pragma omp section
		sumSeven = sumFucntion(arr, 60000000, 69999999);
#pragma omp section
		sumEight = sumFucntion(arr, 70000000, 79999999);
#pragma omp section
		sumNine = sumFucntion(arr, 80000000, 89999999);
#pragma omp section
		sumTen = sumFucntion(arr, 90000000, 99999999);
#pragma omp section
		sum11 = sumFucntion(arr, 100000000, 10999999);
#pragma omp section
		sum12 = sumFucntion(arr, 110000000, 119999999);
#pragma omp section
		sum13 = sumFucntion(arr, 120000000, 129999999);
#pragma omp section
		sum14 = sumFucntion(arr, 130000000, 139999999);
#pragma omp section
		sum15 = sumFucntion(arr, 140000000, 149999999);
#pragma omp section
		sum16 = sumFucntion(arr, 150000000, 160000000);
	}
	//adds all local sums together
	int sum = sumOne + sumTwo + sumThree + sumFour + sumFive + sumSix + sumSeven + sumEight + sumNine + sumTen + sum11 + sum12 + sum13 + sum14 + sum15 + sum16;
	std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
	std::cout << sum << endl;
	std::cout << "Array Summed" << endl;

	//std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds = end - start;
	//outputs the time it took to sum
	std::cout << elapsed_seconds.count() << std::endl;

	delete[] arr;

	system("pause");
	return 0;
}