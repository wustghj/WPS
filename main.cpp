#include <pthread.h>
#include <iostream>
#include "locker.h"
#include<unistd.h>
#include <mutex>
#include <list>
using namespace std;
#define MAX_NUM 5
struct Node
{
    int val;
    struct Node *next;
};
sem m_sem;
Locker locker ;
struct Node *head = nullptr;
void *producer(void * arg)
{
    while (1)
    {
        locker.lock();
        Node *newNode = new Node;
        newNode->val = rand();
        std::cout << "生产了值为" << newNode->val << "的节点\n";
        newNode->next = head;
        head = newNode;
        m_sem.post();
        locker.unlock();
        usleep(1000);
    }
}

void *consumer(void *arg)
{
    while (1)
    {
        m_sem.wait();
        locker.lock();
        Node *temp = head;
        std::cout << "消费了值为" << temp->val << "的节点\n";
        head = head->next;
        locker.unlock();
        usleep(1000);
    }
}

int main()
{
    // 创建producer,consumer
    pthread_t ptids[5], ctids[5];
    for (int i = 0; i < MAX_NUM; i++)
    {
        pthread_create(&ptids[i], NULL, producer, NULL);
        pthread_create(&ctids[i], NULL, consumer, NULL);
    }
    for (int i = 0; i < MAX_NUM; i++)
    {
        pthread_detach(ptids[i]);
        pthread_detach(ctids[i]);
    }
    while(1){
        usleep(1000);
    }
}