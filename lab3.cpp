#include "lab3.h"
#include <windows.h>
#include <map>
#include <cstring>

#include <iostream>
#include <string>

#define Q 3
#define in_range(n) = 0; i < n; i++
// definition
using func = void* (*)(void*);

enum STATUS
{
    DONE,
    STOPS,
    RUNNING,
    PENDING
};

func fabric(char chose);

class Mutex
{
private:
    HANDLE _lock;
    LPCTSTR _name;
public:
    Mutex()
    {
        _lock = CreateMutex(NULL, false, _name);
        if(_lock == NULL)
            throw GetLastError();
    }
    void lock()
    {
        WaitForSingleObject(_lock, INFINITE);
//        _lock = OpenMutex(MUTEX_ALL_ACCESS, true, _name);
    }
    void unlock()
    {
        ReleaseMutex(_lock);
    }

    ~Mutex()
    {
        CloseHandle(_lock);
    }
};

class Sem
{
private:
    HANDLE _sem;
public:
    Sem(int count = 0, int max = 20)
    {
        _sem = CreateSemaphore(NULL,
                count, max, NULL);
        if(_sem == NULL)
            throw GetLastError();
    }
    void push(int count = 1)
    {
        ReleaseSemaphore(_sem, count, NULL);
    }
    void wait()
    {
        WaitForSingleObject(_sem, INFINITE);
    }
    ~Sem()
    {
        CloseHandle(_sem);
    }

};
struct Thread
{
    HANDLE hThread;
    DWORD tid;
    Sem *sem;
    Sem *_selfSem;
    char name;
    STATUS status;
    func function;

    Thread(char name)
    {
        this->name = name;
        sem = new Sem();
        function = fabric(name);
//        _selfSem = new Sem();
        status = PENDING;
    }
    static DWORD WINAPI wrapper(LPVOID ptr)
    {
        Thread *tmp = (Thread*) ptr;
        tmp->status = RUNNING;
//        tmp->_selfSem->push();
        tmp->function(ptr);
        tmp->status = DONE;
        ExitThread(0);
    }
    void run_thread()
    {
        hThread = CreateThread(NULL, 0, wrapper, (LPVOID)this , 0, &tid);
        if( hThread == NULL)
            throw GetLastError();
    }
    void wait()
    {
//        _selfSem ->wait();// wait while pending
        WaitForSingleObject(hThread, INFINITE);
    }
    ~Thread()
    {
        CloseHandle(hThread);
        if(sem != NULL)
            delete sem;
    }
};

// Important
std::map<char, Thread*> threads;

void* thread_a(void* val);
void* thread_b(void* val);
void* thread_c(void* val);
void* thread_d(void* val);
void* thread_e(void* val);
void* thread_f(void* val);
void* thread_g(void* val);
void* thread_h(void* val);
void* thread_i(void* val);
void* thread_k(void* val);
void* thread_m(void* val);
void* thread_n(void* val);
void* thread_p(void* val);
void* thread_r(void* val);

// support function
void doSmth(std::string name, Sem *semA = nullptr, Sem *semB = nullptr);
void wait(HANDLE* thread, int amount = 1);
void wait(std::string flow);
void run_threads(std::string flow);
void init_threads(std::string seq, std::string sem = "");
void cond();

unsigned int lab3_thread_graph_id() 
{
    return 20;
}
const char* lab3_unsynchronized_threads()
{
    return "bcf";
}
const char* lab3_sequential_threads()
{
    return "gkmn";
}

std::string seq("abcdefghikmnpr");
std::string underSem("gkmn");

int lab3_init()
{
    init_threads(seq, underSem);
    run_threads("a");
    wait(seq);
    threads.clear();
    return 0;
}

void run_threads(std::string flow)
{
    for(auto it : flow)
        threads[it]->run_thread();
}

void wait(std::string flow)
{
    for(auto it : flow)
        threads[it]->wait();
}

void* thread_a(void* val)
{
    doSmth("a");
    run_threads("bcf");
    return 0;
}
void* thread_b(void* val)
{
    doSmth("b");
    run_threads("ged");
return 0;
}
void* thread_c(void* val)
{
    doSmth("c");
    doSmth("c");
    run_threads("rh");
    return 0;
}
void* thread_d(void* val)
{
    doSmth("d");
    return 0;
}
void* thread_e(void* val)
{
    doSmth("e"); 
    doSmth("e");
    doSmth("e");
    run_threads("k");
    return 0;
}
void* thread_f(void* val)
{
    doSmth("f");
    doSmth("f");
    doSmth("f");
    run_threads("imn");
    return 0;
}
void* thread_g(void* val)
{
    Thread *tmp = (Thread*) val;
    doSmth("g");
    doSmth("g");
    doSmth("g", tmp->sem, threads['m']->sem);
    doSmth("g", tmp->sem, threads['k']->sem);
    doSmth("g", tmp->sem, threads['n']->sem);
    return 0;
}
void* thread_h(void* val)
{  
    doSmth("h");
    return 0;
}
void* thread_i(void* val)
{
    doSmth("i");
    return 0;

}
void* thread_k(void* val)
{
    Thread *tmp = (Thread*) val;
    doSmth("k", tmp->sem, threads['m']->sem);
    run_threads("p");
    return 0;

}
void* thread_m(void* val)
{
    Thread* tmp = (Thread*) val;
    doSmth("m", tmp->sem, threads['n']->sem);
    doSmth("m", tmp->sem, threads['n']->sem);
    return 0;

}
void* thread_n(void* val)
{
    Thread* tmp = (Thread*) val;
    doSmth("n", tmp->sem, threads['g']->sem);
    doSmth("n", tmp->sem, threads['g']->sem);
    doSmth("n", tmp->sem, threads['g']->sem);
    return 0;
}
void* thread_p(void* val)
{
    doSmth("p");
    return 0;
}
void* thread_r(void* val)
{
    doSmth("r");
    doSmth("r");
    return 0;
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
        threads[it]->sem = new Sem(count);
        if (count)
            count--;
    }
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
        case 'n':
            return thread_n;
        case 'p':
            return thread_p;
        case 'r':
            return thread_r;
        default:
            return NULL;
    }
}
void cond()
{
    static Sem sem(0, 10);
    static Mutex mtx;
    static int tmp[7] = {1, 3, 5, 5, 6, 4, 3};
    static int tact = 0;
    static int count = 0;

    if( tact >= 7)
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