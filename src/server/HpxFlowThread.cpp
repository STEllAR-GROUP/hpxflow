#include "hpxflowthread.h"

using namespace hpx::flow;

static void* runThread(void* arg)
{
    return ((Thread*)arg)->run();
}

HpxFlowThread::HpxFlowThread() : m_tid(0), m_running(0), m_detached(0) {}

HpxFlowThread::~HpxFlowThread()
{
    if (m_running == 1 && m_detached == 0) {
        pthread_detach(m_tid);
    }
    if (m_running == 1) {
        pthread_cancel(m_tid);
    }
}

int HpxFlowThread::start()
{
    int result = pthread_create(&m_tid, NULL, runThread, this);
    if (result == 0) {
        m_running = 1;
    }
    return result;
}

int HpxFlowThread::join()
{
    int result = -1;
    if (m_running == 1) {
        result = pthread_join(m_tid, NULL);
        if (result == 0) {
            m_detached = 0;
        }
    }
    return result;
}

int HpxFlowThread::detach()
{
    int result = -1;
    if (m_running == 1 && m_detached == 0) {
        result = pthread_detach(m_tid);
        if (result == 0) {
            m_detached = 1;
        }
    }
    return result;
}

pthread_t HpxFlowThread::self() {
    return m_tid;
}

HpxFlowWorker::wqueue() {

    pthread_mutex_init(&m_mutex, NULL);
    pthread_cond_init(&m_condv, NULL);

}
HpxFlowWorker::~wqueue() {

    pthread_mutex_destroy(&m_mutex);
    pthread_cond_destroy(&m_condv);

}

void HpxFlowWorker::add(T item) {

    pthread_mutex_lock(&m_mutex);
    m_queue.push_back(item);
    pthread_cond_signal(&m_condv);
    pthread_mutex_unlock(&m_mutex);

}

T HpxFlowWorker::remove() {

    pthread_mutex_lock(&m_mutex);
    while (m_queue.size() == 0) {
        pthread_cond_wait(&m_condv, &m_mutex);
    }
    T item = m_queue.front();
    m_queue.pop_front();
    pthread_mutex_unlock(&m_mutex);
    return item;

}

int HpxFlowWorker::size() {

    pthread_mutex_lock(&m_mutex);
    int size = m_queue.size();
    pthread_mutex_unlock(&m_mutex);
    return size;

}