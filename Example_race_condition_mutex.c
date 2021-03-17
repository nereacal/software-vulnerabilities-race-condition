#include <stdio.h>

#include <stdlib.h>

#include <pthread.h>

 

void *add_function(  );


pthread_mutex_t lock;

int addMul = 0;

main(){

     pthread_t thread;
	pthread_mutex_init(&lock, NULL);
	int ret[70];
	int i=0;
	for(i=0;i<70;i++){
		ret[i] = pthread_create(&thread, NULL, add_function, NULL);
	}
	pthread_exit(NULL);
	printf("RESULT %d\n", addMul);
	exit(EXIT_SUCCESS);
}

 

void *add_function(){

	pthread_mutex_lock(&lock);
	
	int i=0;
		for(i=0; i<10;i++){
			int b=0;
			while(b<400){
				addMul++;
				b++;
			}
			printf("Adding until i=10 %d\n", addMul);
		}
printf("Result of adding i=10 %d\n", addMul);
pthread_mutex_unlock(&lock);
pthread_exit(NULL);

	
}
