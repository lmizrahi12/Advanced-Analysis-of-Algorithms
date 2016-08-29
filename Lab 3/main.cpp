#include "stdio.h"
#include "omp.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <array>
#include <fstream>
#include "algorithms.h"

using namespace std;

void MergeSort_Best();
void MergeSort_Worst();
void MergeSort_Average();
void QuickSort_Worst();
void QuickSort_Average();

int main(){

	srand(time(NULL));

	int n;

	/*cout << "1. MergeSort" << endl;
	cout << "2. QuickSort" << endl;
	cin >> n;
	
	if(n == 1){
		cout << "1. Standard Merge Sort" << endl;
		cout << "2. Improved Merge Sort" << endl;
		cin >> n;
		
		if(n == 1){
			cout << "1. Best Case" << endl;
        	cout << "2. Worst Case" << endl;
        	cout << "3. Average Case" << endl;
        	cin >> n;
        	
        	if(n == 1){
        		//MergeSort_Best();
        	}
        	else if(n == 2){
        		//MergeSort_Worst();
        	}
        	else if(n == 3){
        		MergeSort_Average();
        	}
		}
		
		else if(n == 2){
			cout << "1. Best Case" << endl;
        	cout << "2. Worst Case" << endl;
        	cout << "3. Average Case" << endl;
        	cin >> n;
        	
        	if(n == 1){
        		//Improved_MergeSort_Best();
        	}
        	else if(n == 2){
        		//Improved_MergeSort_Worst();
        	}
        	else if(n == 3){
        		//Improved_MergeSort_Average();
        	}
		}
	}
	
	else if(n == 2){
    	cout << "1. Worst Case" << endl;
    	cout << "2. Average Case" << endl;
    	cin >> n;
    	
    	if(n == 1){
    		QuickSort_Worst();
    	}
    	else if(n == 2){
    		QuickSort_Average();
    	}
	}*/
	
	n = 10;
	vector<int> list(10);
	Random_List(list);
	Print_List(list);
	MergeSort(list, 0, 9);
	Print_List(list);
}


void MergeSort_Best(){
	
}

void MergeSort_Worst(){
	
}

void MergeSort_Average(){
	ofstream file;
    vector<int> list;
    int n;
    
    for(n = 1000;n <= 20000;n+=100){
        vector<int> list(n,0);
        Random_List(list);

        double start = omp_get_wtime();
            MergeSort(list, 0,n-1);
        double end = omp_get_wtime();
        
        cout << "List size: " << n << " ,  Sort time: " << end-start << endl;
        file.open("mergesort_average.csv", ios::app);
        file << n << "," << end-start << endl;
        file.close();
    }
}

void QuickSort_Worst(){
	ofstream file;
    vector<int> list;
    int n;
    
    for(n = 1000;n <= 20000;n+=100){
        vector<int> list(n,0);
        List_Increasing(list);

        double start = omp_get_wtime();
            QuickSort(list, 0,n-1);
        double end = omp_get_wtime();
        
        cout << "List size: " << n << " ,  Sort time: " << end-start << endl;
        file.open("quicksort_worst.csv", ios::app);
        file << n << "," << end-start << endl;
        file.close();
    }
}

void QuickSort_Average(){
	ofstream file;
    vector<int> list;
    int n;
    
    for(n = 1000;n <= 20000;n+=100){
        vector<int> list(n,0);
        Random_List(list);

        double start = omp_get_wtime();
            QuickSort(list, 0,n-1);
        double end = omp_get_wtime();
        
        cout << "List size: " << n << " ,  Sort time: " << end-start << endl;
        file.open("quicksort_average.csv", ios::app);
        file << n << "," << end-start << endl;
        file.close();
    }
}























