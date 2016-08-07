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

void Linear_Best_Case();
void Linear_Worst_Case();
void Linear_Average_Case();
void Binary_Best_Case();
void Binary_Worst_Case();
void Binary_Average_Case();

int main () {
    int choice;
    cout << "Choose option:" << endl;
    cout << "\t 1.Linear Search" << endl;
    cout << "\t 2.Binary Search" << endl;
    cin >> choice;

    if(choice == 1){
        cout << "\t 1.Best case linear search" << endl;
        cout << "\t 2.Worst case linear search" << endl;
        cout << "\t 3.Average case linear search" << endl;
        cin >> choice;
        if(choice == 1)
            Linear_Best_Case();
        else if(choice == 2)
            Linear_Worst_Case();
        else if(choice == 3)
            Linear_Average_Case();
    }
    else{
        cout << "\t 1.Best case binary search" << endl;
        cout << "\t 2.Worst case binary search" << endl;
        cout << "\t 3.Average case binary search" << endl;
        cin >> choice;
        if(choice == 1)
            Binary_Best_Case();
        else if(choice == 2)
            Binary_Worst_Case();
        else if(choice == 3)
            Binary_Average_Case();
    }
}

void Linear_Best_Case(){
    ofstream file;
    for(int n = 100; n <= 50000;n+=100){
        vector<int> list(n,0);
        int key = list[0];
        Random_List_Distinct(list, key);

        double start = omp_get_wtime();
                int index = Linear_Search(list, key);
        double end = omp_get_wtime();

        file.open("linear_search_best", ios::app);
        file << n << "," << end-start << endl;
        file.close();

        cout << "List Size: " << n << " , " << "Time to find index: " << end - start << endl;
    }  
}

void Linear_Worst_Case(){
    ofstream file;
    for(int n = 100; n <= 50000;n+=100){
        vector<int> list(n,0);
        int key = list[n-1];
        Random_List_Distinct(list, key);

        double start = omp_get_wtime();
                int index = Linear_Search(list, key);
        double end = omp_get_wtime();

        file.open("linear_search_worst", ios::app);
        file << n << "," << end-start << endl;
        file.close();

        cout << "List Size: " << n << " , " << "Time to find index: " << end - start << endl;
    }  
}

void Linear_Average_Case(){
    ofstream file;
    for(int n = 100; n <= 50000;n+=100){
        vector<int> list(n,0);
        int key = list[rand()%n + 1];
        Random_List_Distinct(list, key);

        double start = omp_get_wtime();
                int index = Linear_Search(list, key);
        double end = omp_get_wtime();

        file.open("linear_search_average", ios::app);
        file << n << "," << end-start << endl;
        file.close();

        cout << "List Size: " << n << " , " << "Time to find index: " << end - start << endl;
    }  
}

void Binary_Best_Case(){
    ofstream file;

    for(int n = 100; n <= 50000;n+=100){
        vector<int> list(n,0);
        int key = -1;
        Random_List_Increasing(list, key);
        key = list[(n-1)/2];

        double start = omp_get_wtime();
                int index = Binary_Search(list, key);
        double end = omp_get_wtime();

        file.open("binary_search_best", ios::app);
        file << n << "," << end-start << endl;
        file.close();

        cout << "List Size: " << n << " , " << "Time to find index: " << end - start << endl;
    }  
}

void Binary_Worst_Case(){
    ofstream file;

    for(int n = 100; n <= 30000;n+=100){
        vector<int> list(n,0);
        int key = -1;
        Random_List_Increasing(list, key);
        key = list[n-2];

        double start = omp_get_wtime();
                int index = Binary_Search(list, key);
        double end = omp_get_wtime();

        file.open("binary_search_worst", ios::app);
        file << n << "," << end-start << endl;
        file.close();

        cout << "List Size: " << n << " , " << "Time to find index: " << end - start << endl;
    }  
}

void Binary_Average_Case(){
    ofstream file;

    for(int n = 100; n <= 50000;n+=100){
        vector<int> list(n,0);
        int key = -1;
        Random_List_Distinct(list, key);
        key = list[rand()%n + 1];

        double start = omp_get_wtime();
                int index = Binary_Search(list, key);
        double end = omp_get_wtime();

        file.open("binary_search_average", ios::app);
        file << n << "," << end-start << endl;
        file.close();

        cout << "List Size: " << n << " , " << "Time to find index: " << end - start << endl;
    }  
}
