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

void list_init(vector<int> &list){
    for(int i = 0;i < list.size();i++){
        list[i] = i;
    }
}

void Linear_Best(){
    ofstream file;
    for(int n = 100;n <= 100000;n+=100){
        vector<int> list(n,0);
        list_init(list);
        int key = list[0];
        
        double start = omp_get_wtime();
            Linear_Search(list, key);
        double end = omp_get_wtime();

        file.open("linear_search_average.csv", ios::app);
        file << n << "," << end-start << endl;
        file.close();

        cout << "List Size: " << n << " , " << "Time to find index: " << end - start << endl;
        
    }
}

void Linear_Worst(){
    ofstream file;
    for(int n = 100;n <= 100000;n+=100){
        vector<int> list(n,0);
        list_init(list);
        int key = list[n-1];
        
        double start = omp_get_wtime();
            Linear_Search(list, key);
        double end = omp_get_wtime();

        file.open("linear_search_worst.csv", ios::app);
        file << n << "," << end-start << endl;
        file.close();

        cout << "List Size: " << n << " , " << "Time to find index: " << end - start << endl;
        
    }
}

void Linear_Average(){
    ofstream file;
    for(int n = 100;n <= 100000;n+=100){
        vector<int> list(n,0);
        list_init(list);
        int key = list[rand()%n + 1];
        
        double start = omp_get_wtime();
            Linear_Search(list, key);
        double end = omp_get_wtime();

        file.open("linear_search_average.csv", ios::app);
        file << n << "," << end-start << endl;
        file.close();

        cout << "List Size: " << n << " , " << "Time to find index: " << end - start << endl;
        
    }
}

void Binary_Best(){
    ofstream file;
    for(int n = 100;n <= 100000;n+=100){
        vector<int> list(n,0);
        list_init(list);
        int key = list[(n-1)/2];
        
        double start = omp_get_wtime();
            Binary_Search(list, key);
        double end = omp_get_wtime();

        file.open("binary_search_best.csv", ios::app);
        file << n << "," << end-start << endl;
        file.close();

        cout << "List Size: " << n << " , " << "Time to find index: " << end - start << endl;
        
    }
}

void Binary_Worst(){
    ofstream file;
    for(int n = 100;n <= 100000;n+=100){
        vector<int> list(n,0);
        list_init(list);
        int key = list[n-2];
        
        double start = omp_get_wtime();
            Binary_Search(list, key);
        double end = omp_get_wtime();

        file.open("binary_search_worst.csv", ios::app);
        file << n << "," << end-start << endl;
        file.close();

        cout << "List Size: " << n << " , " << "Time to find index: " << end - start << endl;
        
    }
}

void Binary_Average(){
    ofstream file;
    for(int n = 100;n <= 100000;n+=100){
        vector<int> list(n,0);
        list_init(list);
        int key = list[rand()%n + 1];
        
        double start = omp_get_wtime();
            Binary_Search(list, key);
        double end = omp_get_wtime();

        file.open("binary_search_average.csv", ios::app);
        file << n << "," << end-start << endl;
        file.close();

        cout << "List Size: " << n << " , " << "Time to find index: " << end - start << endl;
        
    }
}




int main(){
    srand(time(NULL));

    Binary_Average();
}
