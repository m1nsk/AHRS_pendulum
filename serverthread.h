#ifndef PENDULUMTHREAD_H
#define PENDULUMTHREAD_H

#include <QObject>
#include <QThread>
#include "Network/piserver.h"

class PendulumThread : public QThread
{
public:
    PendulumThread();
    void run ();
    void setPiServer(PiServer *ps){
     this->pi = ps;
    }
private:
    PiServer *pi;
};

#endif // PENDULUMTHREAD_H
