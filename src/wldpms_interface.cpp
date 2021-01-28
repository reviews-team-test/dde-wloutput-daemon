#include "wldpms_interface.h"

wldpms_interface::wldpms_interface (Dpms *dpms)
    : QDBusAbstractAdaptor(dpms)
    , m_Dpms(dpms)
{
    setAutoRelaySignals(true);
    connect(dpms, &Dpms::supportedChanged, this, &wldpms_interface::updateMode);
    connect(dpms, &Dpms::modeChanged, this, &wldpms_interface::updateMode);
}

wldpms_interface::~wldpms_interface()
{
    if (m_Dpms) {
        m_Dpms->deleteLater();
        m_Dpms = nullptr;
    }
}

void wldpms_interface::setDpmsName(QString str)
{
    m_name = str;
}

void wldpms_interface::updateMode()
{
    if(Dpms::Mode::On == m_Dpms->mode()) {
        m_mode = 0;
    } else if (Dpms::Mode::Standby == m_Dpms->mode()){
        m_mode = 1;
    } else if (Dpms::Mode::Suspend == m_Dpms->mode()){
        m_mode = 2;
    } else if (Dpms::Mode::Off == m_Dpms->mode()){
        m_mode = 3;
    } else {
       qDebug()<<"output mode is error";
    }
}

int wldpms_interface::getDpmsMode()
{
    return m_mode;
}

QString wldpms_interface::getDpmsName()
{
    return m_name;
}
