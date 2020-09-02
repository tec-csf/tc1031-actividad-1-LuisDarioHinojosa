//============================================================================
// Name        : SearchAlgorithms.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <time.h>
#include <algorithm>
#include <chrono>
#include "Searcher.h"
#include <iterator>
using namespace std;



template <class T>
void speedTest(vector <T> vec, T val,int srch(vector<T>* ,T)){
    // Measure execution time
    // Measure execution time
	cout << "**SpeedTest**" << endl;
	cout << "Test Value: " << val << endl;
    vector <int>* loc = & vec;

    for(int i = 0; i < 10; i++){
		auto start = chrono::high_resolution_clock::now();
		//int res = Searcher<int>::sequentialSearch(numbers,n);
		int res = srch(loc,val);
		auto end = chrono::high_resolution_clock::now();
		//auto duration = duration_cast<microseconds>(stop - start);
		long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
		cout << "Index: " << res << endl;
		cout << "Execution time-> " << microseconds << " microseconds" << endl;
		cout << endl;
    }
}



template <class T>
void allAlgorithmsTest(vector <T> numbers, T n){
    cout << "Sequential Search" << endl;
    speedTest(numbers,n,Searcher<int>::sequentialSearch);
    cout << endl;

    cout << "Ordered Sequential Search" << endl;
    speedTest(numbers,n,Searcher<int>::orderedSequentialSearch);
    cout << endl;

    cout << "Binary Search" << endl;

    speedTest(numbers,n,Searcher<int>::binarySearch);
    cout << endl;

    cout << "Sequential Search With Transposition" << endl;
    speedTest(numbers,n,Searcher<int>::sequentialSearchWithTransposition);
    cout << endl;

    cout << "Sequential Search with movement forward" << endl;
    speedTest(numbers,n,Searcher<int>::sequentialSearchWithMovementForward);
    cout << endl;

}

int main() {
	//Searcher <int> s;
	// Seed
    srand(time(NULL));


	// Generate random Numbers in the vector;
    const int N = 100000;
    vector <int> numbers(N);

    std::generate(numbers.begin(), numbers.end(), [](){return rand() % 1000;});


    //std::cout << "Print 1" << std::endl;
    //std::copy(numbers.begin(),numbers.end(),std::ostream_iterator<float>(std::cout, " "));
    /*
    int n;
    cout << "Enter a Number" << endl;
    cin >> n;


    // Measure execution time
    vector <int>* loc = & numbers;
    auto start = chrono::high_resolution_clock::now();
    //int res = Searcher<int>::sequentialSearch(numbers,n);
    int res = Searcher<int>::binarySearch(loc,n);
    auto end = chrono::high_resolution_clock::now();

    //auto duration = duration_cast<microseconds>(stop - start);
    long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();

    cout << "Index: " << res << endl;
    cout << "Execution time-> " << microseconds << " microseconds" << endl;

    std::cout << "Print 2" << std::endl;
    std::copy(numbers.begin(),numbers.end(),std::ostream_iterator<float>(std::cout, " "));
    */
    int n = 455, n2 = 250, n3 = 600, n4 = 5, n5 = 496;
    allAlgorithmsTest(numbers,  n);
    allAlgorithmsTest(numbers,  n2);
    allAlgorithmsTest(numbers,  n3);
    allAlgorithmsTest(numbers,  n4);
    allAlgorithmsTest(numbers,  n5);






	return 0;
}


