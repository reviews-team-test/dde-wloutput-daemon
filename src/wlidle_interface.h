#ifndef WLIDLE_INTERFACE_H
#define WLIDLE_INTERFACE_H

#include <QObject>
#include <QString>
#include <QTimer>
#include <QtDBus/QtDBus>
#include <QtDBus/QDBusConnection>

#include <registry.h>

using namespace KWayland::Client;

class WlIdleInterface : public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.deepin.daemon.KWayland.Idle")

public:
    explicit WlIdleInterface(QObject *parent=nullptr);
    virtual ~WlIdleInterface();
    bool InitDBus();
    void addIdleTimeOut(Idle* idle, Seat* seat);

public Q_SLOTS:
    void SetIdleTimeout(quint32 time);

signals:
    void IdleTimeout(bool idle);

private:
    quint32 m_idleTimeout = 60000;
};

#endif // WLOUTPUT_INTERFACE_H
