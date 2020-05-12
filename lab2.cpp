#include "lab2.h"
#include <cstring>
#include <semaphore.h>
#include <map>

#define MAIN lab2_init
#define Q 3
#define in_range(n) = 0; i < n; i++
#define NUMBER_OF_THREADS 11
#define elif else if 

using func = void* (*)(void*);

enum STATUS
{
    DONE, 
    STOPS, 
    RUNNING,
    PENDING
};

class Mutex
{
private:
    pthread_mutex_t* _lock = nullptr;
    bool _status = false;
public:
    Mutex()
    {
        _lock = new pthread_mutex_t();
        pthread_mutex_init(_lock, NULL);
    }
    void lock()
    {
        pthread_mutex_lock(_lock);
    }
    void unlock()
    {
        pthread_mutex_unlock(_lock);
    }

    ~Mutex()
    {
        pthread_mutex_destroy(_lock);
    }
};

class Sem
{
private:
    sem_t* _sem = nullptr;
public:
    Sem(int multithread = 0, int count = 0)
    {
        _sem = new sem_t();
        sem_init(_sem, multithread, count);
    }
    void push(int count = 1)
    {
        for (int i = 0; i < count; i++)
            sem_post(_sem);
    }
    void wait()
    {
        sem_wait(_sem);
    }
    ~Sem()
    {
        if(_sem)
            sem_destroy(_sem);
    }

};

func fabric(char chose);


struct Thread
{
    Thread(char name)
    {
        this->name = name;
        tid = new pthread_t();
        function = fabric(name);
        status = PENDING;
    }
    pthread_t* tid = nullptr;
    Sem *sem = nullptr;
    char name;
    STATUS status;
    func function;
    static void* wrapper(void* ptr);
    void run_thread();
    ~Thread()
    {
        if(tid)
            delete tid;
        if(sem)
            delete sem;
    }
};




// treads functions prototype
void *thread_a(void *ptr);
void *thread_b(void *ptr);
void *thread_c(void *ptr);
void *thread_d(void *ptr);
void *thread_e(void *ptr);
void *thread_f(void *ptr);
void *thread_g(void *ptr);
void *thread_h(void *ptr);
void *thread_i(void *ptr);
void *thread_k(void *ptr);
void *thread_m(void *ptr);

void doSmth(std::string name, Sem *semA = NULL, Sem *semB = NULL);

void init_threads(std::string seq, std::string sem);
void wait(std::string flow);
void wait(Thread* thread);
void run_threads(std::string flow);
void cond();
void drop();


std::map<char, Thread*> threads;


// don't touch 
unsigned int lab2_thread_graph_id() 
{
    return 4;
}
const char* lab2_unsynchronized_threads()
{
    return "bcde";
}
const char* lab2_sequential_threads()
{
    return "efgh";
}

std::string seq("abcdefghikm");
std::string underSem("efgh");

int MAIN()
{
    init_threads(seq, underSem);
    run_threads("acde");
    wait("m");;
    std::cout << std::endl;
    drop();
    return 0;
}


void drop()
{
    threads.clear();
}

void cond()
{
    static Sem sem(11, 0);
    static Mutex mtx;
    static int tmp[6] = {4, 4, 4, 4, 3, 1};
    static int tact = 0;
    static int count = 0;

    if( tact >= 6)
        tact = 0;
    mtx.lock();
    count++;
    if(count == tmp[tact])
    {
        sem.push(tmp[tact]);
        tact++;
        count = 0;
    }
    mtx.unlock();
    sem.wait();
}

void run_threads(std::string flow)
{
    for(auto it : flow)
        threads[it]->run_thread();
}

void wait(std::string flow)
{
    for(auto it : flow)
        wait(threads[it]);
}

void wait(Thread* thread)
{
    static Mutex mtx;
    switch(thread->status)
    {
        case PENDING:
            while(thread->status != RUNNING);
            wait(thread);
            break;
        case RUNNING:
            mtx.lock();
            thread->status = STOPS;
            mtx.unlock();
            while(pthread_join(*thread->tid, NULL) != 0);
            break;
        case STOPS:
            while(thread->status != DONE);
            break;
        case DONE:
            break;
        default:
            break;
    }
}


void init_threads(std::string seq, std::string sem)
{
    for(auto it : seq)
    {
        auto *tmp = new Thread(it);
        threads.insert(std::pair<char, Thread*>(it, tmp));
    }
    // !!!! danger !!!!
    int count = 1;
    for(auto it : sem)
    {
        threads[it]->sem = new Sem(0, count);
        if (count)
            count--;
    }
}

void doSmth(std::string name, Sem *semA, Sem *semB)
{
    static Mutex mutex;
    for (int i in_range(Q))
    {
        if(semA != NULL)
            semA->wait(); // catch mutex
        mutex.lock();
        std::cout << name << std::flush;
        mutex.unlock();
        computation();
        if(semB != NULL)    
            semB->push(); // release mutex
    }
    cond();
}

// Thread function
void* Thread::wrapper(void* ptr)
{
    Thread *tmp = (Thread*) ptr;
    tmp->status = RUNNING;
    tmp->function(ptr);
    tmp->status = DONE;
    return ptr;
}
void Thread::run_thread()
{
    pthread_create(tid,NULL, wrapper, (void*)this);
}

// +-----
void *thread_a(void *ptr)
{
    doSmth("a");
    run_threads("b");
    return ptr;
}
// -+----
void *thread_b(void *ptr)
{
    doSmth("b");
    return ptr;
}
// ++----
void *thread_c(void *ptr)
{
    doSmth("c");
//    wait("a");
    doSmth("c");
//    wait("b");
    run_threads("gh");
    return ptr;
}
// ++*---
void *thread_d(void *ptr)
{
    Thread* tmp = (Thread*)ptr;
    doSmth("d");
    doSmth("d");
    doSmth("d");
//    doSmth("d", tmp->sem, threads['e']->sem);
//    wait("cb");
//    doSmth("d");
    run_threads("f");
    return ptr;
}
// ++**--
void *thread_e(void *ptr)
{
    Thread *tmp = (Thread*)ptr;
    doSmth("e");
//    wait("a");
    doSmth("e");
//    wait("cb");
    doSmth("e", tmp->sem, threads['g']->sem);
//    wait("d");
    doSmth("e", tmp->sem, threads['f']->sem);
//    wait("gf");
    run_threads("ik");
    return ptr;
}
// ---*--
void *thread_f(void *ptr)
{
    Thread *tmp = (Thread*)ptr;
    doSmth("f", tmp->sem, threads['g']->sem);
    return ptr;

}
// --**--
void *thread_g(void *ptr)
{
    Thread *tmp = (Thread*)ptr;
    doSmth("g", tmp->sem, threads['h']->sem);
//    wait("d");
    doSmth("g", tmp->sem, threads['h']->sem);
//    wait("f");
    return ptr;
}
// --**+-
void *thread_h(void *ptr)
{
    Thread *tmp = (Thread*)ptr;
//    doSmth("h", tmp->sem, threads['d']->sem);
//    wait("d");
//    doSmth("h", tmp->sem, threads['d']->sem);
    doSmth("h", tmp->sem, threads['e']->sem);
//    threads['e']->sem->push();
    doSmth("h", tmp->sem, threads['e']->sem);
    doSmth("h");
//    wait("ik");
    run_threads("m");
    return ptr;
}
// ----+-
void *thread_i(void *ptr)
{
    doSmth("i");
//    wait("k");
    return ptr;
}

// ----+-
void *thread_k(void *ptr)
{
    doSmth("k");
    return ptr;
}

// -----+
void *thread_m(void *ptr)
{
    doSmth("m");
    return ptr;
}

func fabric(char chose)
{
    switch(chose)
    {
        case 'a':
            return thread_a;
        case 'b':
            return thread_b;
        case 'c':
            return thread_c;
        case 'd':
            return thread_d;
        case 'e':
            return thread_e;
        case 'f':
            return thread_f;
        case 'k':
            return thread_k;
        case 'h':
            return thread_h;
        case 'i':
            return thread_i;
        case 'g':
            return thread_g;
        case 'm':
            return thread_m;
        default:
            return NULL;
        }
}