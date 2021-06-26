//
//  main.cpp
//  thread_CountingSequence
//
//  Created by Jyothyraj S on 18/12/2020.
//

#include <iostream>
#include <pthread.h>


int n=10;

void* print_I( void* y )
{
    std::cout << "I " <<"\t";
    pthread_exit(NULL);
}
void* print_Love( void* y )
{
    std::cout << "Love " <<"\t";
    pthread_exit(NULL);
}
void* print_You( void* y )
{
    std::cout << "You " <<"\t";
    pthread_exit(NULL);
}



int main()
{
    pthread_t I_t, Love_t,You_t;
    int* c;
    pthread_create( &I_t,NULL, print_I,&n );
    pthread_join( I_t,  (void**)&c );
    
    pthread_create( &Love_t,NULL, print_Love,&n);
    pthread_join( Love_t,  NULL );
    pthread_create( &You_t,NULL, print_You,NULL );
    pthread_join( You_t,  NULL);
   
   // pthread_create(&multiply_t,NULL, multiply,NULL);
   // pthread_join(g_t,NULL);
    return 0;
}
