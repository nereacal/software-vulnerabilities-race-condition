#include <stdio.h>

#include <stdlib.h>

#include <pthread.h>

 

void *add_function( void *ptr );
void *multiply_function( void *ptr );



main(){

     pthread_t thread1, thread2;
	int addMul = 0;
     int  iret1, iret2;

     iret1 = pthread_create( &thread1, NULL, add_function, &addMul);

     if(iret1){
         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret1);
         exit(EXIT_FAILURE);
     }
 
     iret2 = pthread_create( &thread2, NULL, multiply_function,  &addMul);

     if(iret2){
         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret2);
         exit(EXIT_FAILURE);
     }

	 
	

     pthread_join( thread1, NULL);

     pthread_join( thread2, NULL);
	 printf("RESULT %d\n",addMul);
     exit(EXIT_SUCCESS);

}

 

void *add_function( void *ptr){

	int *x_ptr = (int *)ptr;
     int i =0;
	 for(i=0;i<10;i++){
		(*x_ptr) = (*x_ptr) + 1;
		    printf("Adding until i=10 %d\n",(*x_ptr));
	 }
	printf("Result of adding i=10 %d\n",(*x_ptr));
}

void *multiply_function( void *ptr){

	 int *x_ptr = (int *)ptr;
     int i =0;
	 for(i=0;i<5;i++){
		int a = *x_ptr + 2;
		(*x_ptr) = (*x_ptr) + a;
		    printf("Multiply until i=100 %d\n",(*x_ptr));
	 }
	 
	 	printf("Result of Multiply i=100 %d\n",(*x_ptr));
	     
}
