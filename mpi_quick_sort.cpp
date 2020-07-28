#include "mpi.h"
#include <iostream>
#include <time.h>
#include <fstream>
#include <cmath>
#include <string.h>
#include <cstdlib>
using namespace std;

long *data_loading(char* dir);

long primordal_data_length;
int rank, size;
long *result_data;

int main(int argc, char **argv){
    MPI_Init(&argc, &argv);
    MPI_Comm_size( MPI_COMM_WORLD, &size );
    MPI_Comm_rank( MPI_COMM_WORLD, &rank );
    long *primordal_data;
    if (rank == 0){
        primordal_data=data_loading(argv[1]);
    }
    cout << rank << " process\n";
    MPI_Finalize();
};

long *data_loading(char* dir){
    fstream file;
    string temp;
    long line=0;
    file.open(dir, ios::in);
    getline(file, temp);
    long size=atol(temp.c_str());
    cout << size << endl;
    primordal_data_length=size;
    long *array = new long[size+1];
    long i=0;

    getline(file,temp);
    char *str_arr=new char[temp.size()+1];
    strcpy(str_arr, temp.c_str());
    char *list=strtok(str_arr, ",");
    while(list!=NULL){
        array[i++]=atol(list);
        list=strtok(NULL, ",");
    }
    file.close();
    return array;
}
