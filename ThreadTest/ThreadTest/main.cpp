//
//  main.cpp
//  ThreadTest
//
//  Created by Jyothyraj S on 17/12/2020.
//

#include <iostream>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t oddmutex, evenmutex;

void* printer_odd(void* p)
{
    wait(evensem)
    for(int i =0; i <100; i+=2)
    {
        std::cout << i<< std::endl;
        usleep(10);
    }
    return NULL;
}

void* printer_even(void* p)
{
    wait(oddsem);
    for(int i =1; i <100; i+=2)
    {
        std::cout << i<< std::endl;
        usleep(10);
    }
    return NULL;
}

int main(int argc, const char * argv[]) {
    pthread_t t1, t2, t3;

    pthread_sem
    pthread_create(&t1, NULL, printer_odd, NULL);
    pthread_create(&t2, NULL, printer_even, NULL);
    pthread_create(&t3, NULL, printer_even, NULL);
    int ret;
    pthread_join(t1, (void**)&ret);
    pthread_join(t2, (void**)&ret);
    return 0;
}
