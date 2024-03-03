#include<stdio.h>

// void userInput(int processSize, int resourceSize, int allocation[][int resourceSize], int maximum[][int resourceSize], int available[]){
//     int row, col;
//     row = processSize;
//     col = resourceSize;
//     //input for allocation matrix:
//     for(int i = 0; i < row; i++){
//         for(int j = 0; j < col; j++){
//             scanf("%d", &allocation[i][j]);
//         }
//     }

//     //input for maximum matrix:
//     for(int i = 0; i < row; i++){
//         for(int j = 0; j < col; j++){
//             scanf("%d", &maximum[i][j]);
//         }
//     }
    
//     //input for available matrix:
//     for(int i = 0; i < resourceSize; i++){
//         scanf("%d", &available[i]);
//     }
// }

void userInput(int mat[][5], int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            scanf("%d", &mat[i][j]);
        }
    }
}

void userInputAvailableResources(int mat[], int size){
    for(int i = 0; i<size; i++){
        scanf("%d", &mat[i]);
    }
}

void display(int mat[][5], int processSize, int resourceSize){
    int row, col;
    row = processSize;
    col = resourceSize;

    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            printf("%d \t", mat[row][col]);
        }
        printf("\n");
    }

}


//Maximum - allocation matrix:
void calculateNeed(int matA[][5], int matB[][5], int matC[][5], int processSize, int resourceSize){
    int row, col;
    row = processSize;
    col = resourceSize;

    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            matC[i][j] = matA[i][j] - matB[i][j];
        }
        printf("\n");
    }

}


int main(){

    int processSize, resourceSize;
    printf("Enter the number of processes: \n");
    scanf("%d", &processSize);

    printf("Enter the number of allocated resources");
    scanf("%d", &resourceSize);

    int allocation[processSize][resourceSize]; //for allocation matrix.
    int maximum[processSize][resourceSize]; //for maximum matrix.
    int need[processSize][resourceSize];    //for need matrix.

    int available[resourceSize]; //for available resources matrix.

    //taking user input:
    printf("Enter the Allocated Resources for %d processes with %d resources: \n", processSize, resourceSize);
    userInput(allocation, processSize, resourceSize);

    printf("Enter the Maximum Resources for %d processes with %d resources: \n", processSize, resourceSize);
    userInput(maximum, processSize, resourceSize);

    printf("Enter the Available Resources with %d resource instances: \n", resourceSize);
    userInputAvailableResources(available, resourceSize);

    calculateNeed(maximum, allocation, need, processSize, resourceSize);
    
    // display(allocation, processSize, resourceSize);
    // display(maximum, processSize, resourceSize);

    display(need, processSize, resourceSize);

    return 0;
}