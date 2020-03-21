#include "wlidle_interface.h"
#include <QtDBus/QDBusMessage>
#include <QDBusInterface>

#include <idle.h>

WlIdleInterface::WlIdleInterface(QObject *parent)
    : QDBusAbstractAdaptor(parent)
{
    setAutoRelaySignals(true);
}

WlIdleInterface::~WlIdleInterface()
{
}

void WlIdleInterface::SetIdleTimeout(quint32 time)
{
    if(m_idleTimeout != time) {
        m_idleTimeout = time;
    }
}

void WlIdleInterface::addIdleTimeOut(Idle* idle, Seat* seat)
{
    auto idleTimeout = idle->getTimeout(m_idleTimeout, seat, this);
    connect(idleTimeout, &IdleTimeout::idle, this, [ = ]{
        qDebug() << "idle timeout on";
        IdleTimeout(true);
    });
    connect(idleTimeout, &IdleTimeout::resumeFromIdle, this, [ = ]{
        qDebug() << "idle timeout off";
        IdleTimeout(false);
    });
}
