#ifndef WLOUTPUT_INTERFACE_H
#define WLOUTPUT_INTERFACE_H

#include <QObject>
#include <QString>
#include <QTimer>
#include <QtDBus/QtDBus>
#include <QtDBus/QDBusConnection>
#include <QThread>

#include <outputdevice.h>
#include <registry.h>
#include <fakeinput.h>
#include <connection_thread.h>
#include <outputmanagement.h>
#include <QList>
#include <outputconfiguration.h>

#include "wlidle_interface.h"

namespace KWayland {
namespace  Client{
    class PlasmaWindowModel;
}
}

using namespace KWayland::Client;

const QString SERVER = "com.deepin.daemon.KWayland";
const QString PATH = "/com/deepin/daemon/KWayland/Output";
const QString INTERFACE = "com.deepin.daemon.KWayland.Output";

typedef struct _mode_info
{
    int id;
    int width;
    int height;
    int refresh_rate;
    int flags; // avaliable values: [current, preferred]
}ModeInfo;


typedef  struct _output_info
{
    QString model;
    QString manufacturer;
    QString uuid;
    int enabled;
    int x;
    int y;
    int width;
    int height;
    int refresh_rate;
    int transform;
    int phys_width;
    int phys_height;
    double scale;
    QList<ModeInfo> lstModeInfos;
}OutputInfo;


class wloutput_interface : public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.deepin.daemon.KWayland.Output")

public:
    explicit wloutput_interface(QObject *parent=nullptr);
    virtual ~wloutput_interface();
    bool InitDBus();
    void StartWork();
    QDBusAbstractAdaptor* idleObject() { return m_wlIdleInterface; }
    static OutputInfo GetOutputInfo(const OutputDevice* dev);
    static QString OutputInfo2Json(QList<OutputInfo>& listOutputInfos);
    static QList<OutputInfo> json2OutputInfo(QString jsonString);

signals:
    void OutputAdded(QString output);
    void OutputRemoved(QString output);
    void OutputChanged(QString output);

public Q_SLOTS:
    QString ListOutput();
    QString GetOutput(QString uuid);
    void Apply(QString outputs);
    void WlSimulateKey(int keycode);

private:
    void onDeviceChanged(OutputDevice *dev);
    void onDeviceRemove(quint32 name, quint32 version) ;
    void onMangementAnnounced(quint32 name, quint32 version);
    void createPlasmaWindowManagement(quint32 name, quint32 version);

private:
    //QTimer m_Timer;
    ConnectionThread *m_pConnectThread{nullptr};
    QThread *m_pThread{nullptr};
    Registry *m_pRegisry{nullptr};
    OutputManagement *m_pManager{nullptr};
    OutputConfiguration *m_pConf{nullptr};
    EventQueue *m_eventQueue{nullptr};
    bool m_bConnected;
    PlasmaWindowManagement *m_pWindowManager{nullptr};
    WlIdleInterface *m_wlIdleInterface{nullptr};
    Idle *m_idle{nullptr};
    Seat *m_seat{nullptr};
    FakeInput *m_fakeInput{nullptr};
};

#endif // WLOUTPUT_INTERFACE_H
