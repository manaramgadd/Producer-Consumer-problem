//Lab 5
//Hend Khaled Abdelhamid  6986
//Manar Amgad 7113

#include <iostream>
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <random>
#include<math.h>
#include"server.h"
#include <bits/stdc++.h>
#include <ctime>
using namespace std;
int main(int argc, char** argv)
{ 

key_t key;

int c;
int shmid;

if ((key = ftok("tmp.cpp", 5)) == -1) {
        perror("ftok");
        exit(1);
    }


 


char* arr;



 if ((shmid = shmget(key, 0,0)) == -1)//0666 R/W
    {
        perror("error in shmget\n");
      
    }

 if ((arr = (char*)shmat(shmid, (void *)0, 0)) == (char*)-1)
    {
        perror("attachement error\n");}
if ((key = ftok("tmp1", 5)) == -1) {
        perror("ftok");
        exit(1);
    }

if ((semid = semget(key, 3, 0)) == -1)
//semget->obtaining semaphores
    {
        perror("error in creating semaphores\n");
       
    }
    time_t tmNow;
    tmNow = time(NULL);
    struct tm t = *localtime(&tmNow);
    
  FILE* fil;
char* str;
str=argv[1];
printf("y");
int i = 0;
double  mean;
mean=atof(argv[2]);
double number;
double stddev;
stddev=atof(argv[3]);
int secs=atoi(argv[4]);
c=atoi(argv[5]);
double var=pow(stddev,2);
std::normal_distribution<double> normal{mean, stddev};
std::default_random_engine generator;

while(1){

printf("locked\n"); 

sem_action(semid, EMPT, -1);
sem_action(semid,LOCK, -1);
fil = fopen("prod.log", "a+");
  if(!fil) {  
    printf("couldn't open the file !\n");
    exit(-1);
  }

fprintf(fil,"[%d/%d/%d|%d:%d:%d]",t.tm_mday,t.tm_mon+1,t.tm_year+1900,t.tm_hour,t.tm_min,t.tm_sec);
fprintf(fil,"%s trying to get a mutex on a shared buffer\n",str);

// Critical
number=abs(normal(generator));
cout << "before buffer \n";
string tmp = str;
cout << str << "\n" ;
tmp += ",";
tmp += to_string(number);
strcpy(arr,tmp.c_str());
char* o;

fprintf(fil,"[%d/%d/%d %d:%d:%d]",t.tm_mday,t.tm_mon+1,t.tm_year+1900,t.tm_hour,t.tm_min,t.tm_sec);
fprintf(fil, "%s:placing %f on shared buffer\n",str,number); 

fprintf(fil,"[%d/%d/%d %d:%d:%d]",t.tm_mday,t.tm_mon+1,t.tm_year+1900,t.tm_hour,t.tm_min,t.tm_sec);
fprintf(fil, "%s:generating new value %f\n", str,number);  

sem_action(semid, LOCK, 1);
sem_action(semid, FULL, 1);
cout << "After buffer \n";
i++;sleep(secs);

if (i%c == 0 ) i = 0;
fprintf(fil,"[%d/%d/%d %d:%d:%d]",t.tm_mday,t.tm_mon+1,t.tm_year+1900,t.tm_hour,t.tm_min,t.tm_sec);
fprintf(fil, "%s sleeping for %d ms\n",str,atoi(argv[4]));
fclose(fil);

}
return 0;
}