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
#include <registry.h>
#include <connection_thread.h>
#include <outputmanagement.h>
#include <QList>
#include <outputconfiguration.h>



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


class wloutput_interface : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.deepin.daemon.KWayland.Output")
public:
    explicit wloutput_interface(QObject *parent=nullptr);
    virtual ~wloutput_interface();
    bool InitDBus();
    void StartWork();
    static OutputInfo GetOutputInfo(const OutputDevice* dev);
    static QString OutputInfo2Json(QList<OutputInfo>& listOutputInfos);
    static QList<OutputInfo> json2OutputInfo(QString jsonString);
signals:
    void OutputAdded(QString output);
    void OutputRemoved(QString output);
    void OutputChanged(QString output);
public slots:
    QString ListOutput();
    QString GetOutput(QString uuid);
    void Apply(QString outputs);
private:
    //QTimer m_Timer;


    ConnectionThread *m_pConnectThread;
    QThread *m_pThread;
    Registry *m_pRegisry;
    OutputManagement *m_pManager;
    OutputConfiguration *m_pConf;
    bool m_bConnected;

};

#endif // WLOUTPUT_INTERFACE_H
