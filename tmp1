#include<sys/shm.h>
#include <bits/stdc++.h>
   

int delete_segment(int seg_id){
    if ((shmctl(seg_id,IPC_RMID,0))==-1){
    std::cout<<" ERROR(C++)with shmctl(IPC_RMID): "<<strerror(errno)<<std::endl;
    return -1;
    }else//on success
        return 0;
}

int main(){

    struct shmid_ds shm_info;
    struct shmid_ds shm_segment;
    int max_id = shmctl(0,SHM_INFO,&shm_info);
    if (max_id>=0){
        for (int i=0;i<=max_id;++i) {
                int shm_id = shmctl(i , SHM_STAT , &shm_segment);
                if (shm_id<=0)
                    continue;
                else if (shm_segment.shm_nattch==0){
                    delete_segment(shm_id);
                }
        }
    }
    return 0;
}
