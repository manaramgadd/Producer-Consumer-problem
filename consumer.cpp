//Lab 5
//Hend Khaled Abdelhamid  6986
//Manar Amgad 7113

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
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
#include <time.h>

using namespace std;

//====================================================================
//printing function
void printingtable(item e[11])
{cout << "\033[2J\033[1;1H";
system("clear");
printf("\e[1;1H\e[2J");
    cout<< "+-----------------------------------------------+\n";
    cout<< "| Currency     | Price          | AvgPrice      |\n"; 
    cout<< "+-----------------------------------------------+\n";
    for(int i=0;i<11;i++){
        std::cout<<"|";
        std::cout.width(14);
        std::cout<<std::left;
        std::cout<<e[i].name;
        std::cout<<"|";
        //////////////////////////////////////////////////
        if(e[i].flag_price==0)
        {
            printf(" \033[;36m%-10.2lf\033[0m\t|",e[i].newprice);
        }
        
        else if(e[i].flag_price==2)
        {
           printf(" \033[;31m%-10.2lf↓\033[0m\t|",e[i].newprice);
        }
        else if (e[i].flag_price ==1)
        {
            printf(" \033[;32m%-10.2lf↑\033[0m\t|",e[i].newprice);
        }
       // //////////////////////////////////////////////////
        if(e[i].flag_avg==0)
        {
            printf(" \033[;36m%-10.2lf\033[0m\t|\n",e[i].avgp);
        }
        else if (e[i].flag_avg==2)
        {
            printf(" \033[;31m%-10.2lf↓\033[0m\t|\n",e[i].avgp);

        }
        else if (e[i].flag_avg==1)
        {
            printf(" \033[;32m%-10.2lf↑\033[0m\t|\n",e[i].avgp);
        }
}
    
    cout<< "+-----------------------------------------------+\n";

}
    
//====================================================================

int main(int argc, char** argv){key_t key ;
if ((key = ftok("tmp.cpp", 5)) == -1) {
        perror("ftok");
        exit(1);
    }
int count=atoi(argv[1]);

int flag=0;

e[0].name="Aluminum";
e[0].newprice=0.00;
e[0].old1=0.00;
e[0].old2=0.00;
e[0].old3=0.00;
e[0].old4=0.00;
e[0].avgp=0.00;
e[0].times=0;
e[0].flag_avg=0;
e[0].flag_price=0;
e[0].avg_old=0.00;

e[1].name="Copper";
e[1].newprice=0.00;
e[1].old1=0.00;
e[1].old2=0.00;
e[1].old3=0.00;
e[1].times=0;
e[1].flag_avg=0;
e[1].flag_price=0;
e[1].avg_old=0.00;

e[2].name="Cotton";
e[2].newprice=0.00;
e[2].old1=0.00;
e[2].old2=0.00;
e[2].old3=0.00;
e[2].old4=0.00;
e[2].avgp=0.00;
e[2].times=0;
e[2].flag_avg=0;
e[2].flag_price=0;
e[2].avg_old=0.00;

e[3].name="CrudeOil";
e[3].newprice=0.00;
e[3].old1=0.00;
e[3].old2=0.00;
e[3].old3=0.00;
e[3].old4=0.00;
e[3].avgp=0.00;
e[3].times=0;
e[3].flag_avg=0;
e[3].flag_price=0;
e[3].avg_old=0.00;

e[4].name="Gold";
e[4].newprice=0.00;
e[4].old1=0.00;
e[4].old2=0.00;
e[4].old3=0.00;
e[4].old4=0.00;
e[4].avgp=0.00;
e[4].times=0;
e[4].flag_avg=0;
e[4].flag_price=0;
e[4].avg_old=0.00;

e[5].name="Lead";
e[5].newprice=0.00;
e[5].old1=0.00;
e[5].old2=0.00;
e[5].old3=0.00;
e[5].old4=0.00;
e[5].avgp=0.00;
e[5].times=0;
e[5].flag_avg=0;
e[5].flag_price=0;
e[5].avg_old=0.00;

e[6].name="MenthaOil";
e[6].newprice=0.00;
e[6].old1=0.00;
e[6].old2=0.00;
e[6].old3=0.00;
e[6].old4=0.00;
e[6].avgp=0.00;
e[6].times=0;
e[6].flag_price=0;
e[6].flag_avg=0;
e[6].avg_old=0.00;

e[7].name="NaturalGas";
e[7].newprice=0.00;
e[7].old1=0.00;
e[7].old2=0.00;
e[7].old3=0.00;
e[7].old4=0.00;
e[7].avgp=0.00;
e[7].times=0;
e[7].flag_avg=0;
e[7].flag_price=0;
e[7].avg_old=0.00;

e[8].name="Nickel";
e[8].newprice=0.00;
e[8].old1=0.00;
e[8].old2=0.00;
e[8].old3=0.00;
e[8].old4=0.00;
e[8].avgp=0.00;
e[8].times=0;
e[8].flag_avg=0;
e[8].flag_price=0;
e[8].avg_old=0.00;

e[9].name="Silver";
e[9].newprice=0.00;
e[9].old1=0.00;
e[9].old2=0.00;
e[9].old3=0.00;
e[9].old4=0.00;
e[9].avgp=0.00;
e[9].times=0;
e[9].flag_avg=0;
e[9].flag_price=0;
e[9].avg_old=0.00;

e[10].name="Zinc";
e[10].newprice=0.00;
e[10].old1=0.00;
e[10].old2=0.00;
e[10].old3=0.00;
e[10].old4=0.00;
e[10].avgp=0.00;
e[10].times=0;
e[10].flag_avg=0;
e[10].flag_price=0;
e[10].avg_old=0.00;

int shmid;
int i = 0;
void* f;
char *t;
double averageprice;


char* arr;

 if ((shmid = shmget(key, 32*count,0666| IPC_CREAT)) == -1)
    {
        perror("error in shmget\n");
      
    }
    
if ((key = ftok("tmp1", 5)) == -1) {
        perror("ftok");
        exit(1);
    }

if ((semid = semget(key, 3, 0666|IPC_CREAT)) == -1)
//semget->obtaining semaphores
    {
        perror("error in creating semaphores\n");
       
    }
    sem_init(semid, FULL, 0);
    sem_init(semid, EMPT, count);
    sem_init(semid, LOCK, 1);
 if ((arr = (char*)shmat(shmid, (void *)0, 0)) == (char*)-1)
    {
        perror("attachement error\n");}
        
         int j=0;



while(true) {  


sem_action(semid, FULL, -1);
sem_action(semid, LOCK, -1);


// Critical

    

t=arr;
char* currency=strtok(t,",");
for(int w =0;w<11;w++)
     {
        char *qaa=(char*)malloc(sizeof(char)*10);
        strcpy(qaa,e[w].name.c_str());

        if(strcmp(qaa,currency)==0)
            {
                char*g=strtok(NULL,",");
        
             e[w].newprice=atof(g);
        
        if(e[w].newprice>e[w].old1)
        {
            e[w].flag_price=1;
        }
        else if (e[w].newprice<e[w].old1)
        {
            e[w].flag_price=2;
        }
        else{
            e[w].flag_price=0;
        }
        
        e[w].times++;
        
         if (e[w].times>4)
        {
            averageprice=(e[w].newprice + e[w].old1 + e[w].old2 + e[w].old3 + e[w].old4) / 5.0;
            e[w].avgp=averageprice;

        }
        else{
            e[w].avgp=0.00;
        }

        e[w].old4=e[w].old3;
        e[w].old3=e[w].old2;
        e[w].old2=e[w].old1;
        e[w].old1=e[w].newprice;

        if(e[w].avgp>e[w].avg_old)
        {
            e[w].flag_avg=1;
        }
        else if (e[w].avgp<e[w].avg_old)
        {
            e[w].flag_avg=2;
        }
        else{
            e[w].flag_avg=0;
        }

        e[w].avg_old=e[w].avgp;
       
           printingtable(e);

        j++;
        strcpy(arr,"\0");
        if ( j%count == 0 ) j = 0;

 }

 }
  
sem_action(semid, LOCK, 1);
sem_action(semid, EMPT, 1);
 
 }
     
 shmdt((void *)arr);
    
    
    return 0;
}
