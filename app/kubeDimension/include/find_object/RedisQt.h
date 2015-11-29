#ifndef __HIREDIS_QT_H
#define __HIREDIS_QT_H

#include "hiredis/adapters/qt.h"

class QtRedis : public QObject {

    Q_OBJECT

    public:
        QtRedis(const char * value, QObject * parent = 0)
            : QObject(parent), m_value(value) {}

    Q_SIGNALS:
        void finished();

    public Q_SLOTS:
        void run();

    private:
        void finish() { Q_EMIT finished(); }

    private:
        const char * m_value;
        redisAsyncContext * m_ctx;
        RedisQtAdapter m_adapter;

    friend
    void getCallback(redisAsyncContext *, void *, void *);
};

#endif /* !__HIREDIS_QT_H */
