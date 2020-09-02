/*
 * Searcher.h
 *
 *  Created on: 1 sep. 2020
 *      Author: luisd
 */

#ifndef SEARCHER_H_
#define SEARCHER_H_

#include <iostream>
#include <vector>
template <class T>
class Searcher{
public:

	static int sequentialSearch(std::vector<T> *vector, T value);
	static int orderedSequentialSearch(std::vector <T> *vector, T value);
	static int binarySearch(std::vector <T>* vector,T value);
	static int sequentialSearchWithMovementForward(std::vector <T> *vec,T value);
	static void rightShift(std::vector <T>*vec,int index);
	static int sequentialSearchWithTransposition(std::vector <T> *vec,T value);
	static void swapValues(std::vector <T>*vec,int index1, int index2);

};






template <class T>
int Searcher<T>::sequentialSearch(std::vector<T> *vector, T value){
	std::vector<T> vec= *vector;
    int i = 0;
    int found = -1;

    long int size = vec.size();

    while (found == -1 && i < size) {
        if (vec[i] == value) {
            found = i;
        }
        ++i;
    }

    return found;
}


template <class T>
int Searcher<T>::orderedSequentialSearch(std::vector <T> *vector, T value){
	std::vector<T> vec = *vector;
	sort(vec.begin(),vec.end());
	// if value is not in the min-max range it is not in the vector
	int i = 0;
	int found = -1;
    long int size = vec.size();

    while (found == -1 && i < size) {
    	if (vec[i] > value && vec[i] != value){
    		break;
    	}

        if (vec[i] == value) {
            found = i;
        }
        ++i;
    }
	return found;
}



template <class T>
int Searcher<T>::binarySearch(std::vector <T> *vector,T value){
	// Sort Vector
	std::vector<T> vec = *vector;
	int N = vec.size();
	sort(vec.begin(),vec.end());
	if (N == 0){
		return -1;
	}

	int middle,inf = 0, sup = N-1;
	do{
		middle = (inf+sup)/2;
		if(value > vec[middle]){
			inf = middle +1;
		}
		else{
			sup = middle -1;
		}

	}while(vec[middle] != value && inf <= sup);

	if(vec[middle] == value){
		return middle;
	}
	else{
		return -1;
	}
}


template <class T>
// I decided to use a pointer because the real vector needs to change.
int Searcher<T>::sequentialSearchWithMovementForward(std::vector <T> *vec,T value){
	int index = sequentialSearch(vec,  value);
	// If the value is not found, you don't need to move any element.
	if(index == -1 || index == 0){
		return index;
	}
	else if (index >= 0){
		rightShift(vec,index);
		return index;
	}
}



template <class T>
// Auxiliary Function: Will shift the elements to the right from the first to the index position.
void Searcher<T>::rightShift(std::vector <T>*vec,int index){
	//cout << "Enter" << endl;
	T indexVal = vec->at(index);
	for(int i = index; i > 0; i--){
		vec->at(i) = vec->at(i-1);
		//cout << i << endl;
	}
	vec->at(0) = indexVal;

}


template <class T>
int Searcher<T>::sequentialSearchWithTransposition(std::vector <T> *vec,T value){
	int index = sequentialSearch(vec,  value);
	if(index == -1 || index == 0){
		return index;
	}
	else if(index > 0){
		swapValues(vec,index,0);
		return index;
	}
}

template <class T>
void Searcher<T>::swapValues(std::vector <T>*vec,int index1, int index2){
	T aux = vec->at(index1);
	vec->at(index1) = vec->at(index2);
	vec->at(index2) = aux;
}


#endif /* SEARCHER_H_ */
