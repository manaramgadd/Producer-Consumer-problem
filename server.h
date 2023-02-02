//Lab 5
//Hend Khaled Abdelhamid  6986
//Manar Amgad 7113

#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <sys/msg.h>
#include <sys/types.h>


#define N 20

union semun
{
    int val; //SETVAL
    struct semid_ds buf; //IPC_STAT
unsigned short int *array; //GETALL and SETALL
};
struct item
{   
std:: string name;
    double newprice;
    double old1;
    double old2;
    double old3;
    double old4;
    double avgp;
    double avg_old;
    int times;
    int flag_price;
    int flag_avg;

};

struct item e[11];

//char items[11][11]={"Gold","Silver","CrudeOil","NaturalGas",
//"Aluminium","Copper","Nickel","Lead","Zinc","MethaOil","Cotton"};

int shmid;
int semid;

struct sembuf sem = {0, 0, 0};



//semaphores
enum
{
    FULL,
    EMPT,
   LOCK
};

void sem_init(int semid, int num, int val)
{
    union semun arg;
    arg.val = val;

    if (semctl(semid, num, SETVAL, arg) == -1)
    {
        perror("semctl\n");
      
    }
}

void sem_action(int semid, int num, int opr)
{
  sem.sem_num = num;      
   sem.sem_op = opr;      
    sem.sem_flg = 0; 
    
    if (semop(semid, &sem, 1) == -1) {
        perror("semop");
        exit(1);
    }

   
}



 
