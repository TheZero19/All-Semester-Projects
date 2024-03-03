#include <stdio.h>

void input(int A[][5], int n, int m){
    int i,j = 0;
    for(i = 0; i<n; i++){
    	printf("For process %d: ",i+1);
        for(j = 0; j<m; j++){
        	printf("Resource %d: ",j+1);
            scanf("%d",&A[i][j]);
        }
    }
}

int main(){
    int max[5][5], alloc[5][5], need[5][5], available[5], finish[5], work[5];
    int n,m;
    printf("Input number of process and resource: ");
    scanf("%d %d",&n, &m);

	printf("For max:\n");
    input(max,n,m);
    printf("For alloc:\n");
    input(alloc,n,m);
    int i,j = 0;
    for(i = 0; i<n; i++){
        for(j = 0; j<m; j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
        finish[i] = 0;
    }

    for(j = 0; j<m; j++){
    	printf("Enter available resource for resource %d: ",j+1);
        scanf("%d", &available[j]);
        work[j] = available[j];
    }
	
	int count = 0;
	int order[5];
	
	while(count < n){
		for(i = 0; i < n; i++){
			if(finish[i] == 0){
				int isExecutable = 1;
				for(j = 0; j < m; j++){
					if(need[i][j] > work[j]){
						isExecutable = 0;
					}
				}
				
				if(isExecutable == 1){
					for(j = 0; j<m; j++){
						work[j] += alloc[i][j];
					}
					finish[i] = 1;
					order[count] = i+1;
					count++;
				}
			}
			
		}
	}
	
	printf("Order of execution:\n");
	for(i = 0; i<n; i++){
		printf("%d\t",order[i]);
	}
	printf("\n");
    return 0;
}
