#include<pthread.h>
#include<mutex>
#include<semaphore.h>
#include<assert.h>
#include<exception>
class Locker{
private:
    pthread_mutex_t m_mutex;


public:
    Locker(){
        pthread_mutex_init(&m_mutex,NULL);
    }
    ~Locker(){
        pthread_mutex_destroy(&m_mutex);
    }

    bool lock(){
        return pthread_mutex_lock(&m_mutex)==0;
    }
    bool unlock(){
        return pthread_mutex_unlock(&m_mutex)==0;
    }

};

class sem{
private:
    sem_t m_sem;

public:
    sem(){
        //sem_init 返回0表示成功 ， 返回-1表示失败
        if(sem_init(&m_sem,0,0)!=0){
            throw std::exception();
        }
    }
    sem(int num){
        if(sem_init(&m_sem,0,num)!=0);
            throw std::exception();
    }
    ~sem(){
        sem_destroy(&m_sem);
    }
    bool wait(){
        return sem_wait(&m_sem)==0;
    }
    bool post(){
        return sem_post(&m_sem)==0;
    }
};