#include "dplasma_window.h"
#include <QDebug>

DPlasmaWindow::DPlasmaWindow(PlasmaWindow* plasma_window, QObject *parent)
    : QObject(parent)
    , m_plasmaWindow(plasma_window)
{
    InitConnect();
}

DPlasmaWindow::~DPlasmaWindow()
{
}

void DPlasmaWindow::InitConnect()
{
    qDebug() << "on plasma Window created, title:" << m_plasmaWindow->title();

    connect(m_plasmaWindow, &PlasmaWindow::activeChanged, this, &DPlasmaWindow::ActiveChanged);
    connect(m_plasmaWindow, &PlasmaWindow::appIdChanged, this, &DPlasmaWindow::AppIdChanged);
    connect(m_plasmaWindow, &PlasmaWindow::closeableChanged, this, &DPlasmaWindow::CloseableChanged);
    connect(m_plasmaWindow, &PlasmaWindow::demandsAttentionChanged, this, &DPlasmaWindow::DemandsAttentionChanged);
    connect(m_plasmaWindow, &PlasmaWindow::fullscreenableChanged, this, &DPlasmaWindow::FullscreenableChanged);
    connect(m_plasmaWindow, &PlasmaWindow::fullscreenChanged, this, &DPlasmaWindow::FullscreenChanged);
    connect(m_plasmaWindow, &PlasmaWindow::geometryChanged, this, &DPlasmaWindow::GeometryChanged);
    connect(m_plasmaWindow, &PlasmaWindow::iconChanged, this, &DPlasmaWindow::IconChanged);
    connect(m_plasmaWindow, &PlasmaWindow::keepAboveChanged, this, &DPlasmaWindow::KeepAboveChanged);
    connect(m_plasmaWindow, &PlasmaWindow::keepBelowChanged, this, &DPlasmaWindow::KeepBelowChanged);
    connect(m_plasmaWindow, &PlasmaWindow::maximizeableChanged, this, &DPlasmaWindow::MaximizeableChanged);
    connect(m_plasmaWindow, &PlasmaWindow::maximizedChanged, this, &DPlasmaWindow::MaximizedChanged);
    connect(m_plasmaWindow, &PlasmaWindow::minimizeableChanged, this, &DPlasmaWindow::MinimizeableChanged);
    connect(m_plasmaWindow, &PlasmaWindow::minimizedChanged, this, &DPlasmaWindow::MinimizedChanged);
    connect(m_plasmaWindow, &PlasmaWindow::movableChanged, this, &DPlasmaWindow::MovableChanged);
    connect(m_plasmaWindow, &PlasmaWindow::onAllDesktopsChanged, this, &DPlasmaWindow::OnAllDesktopsChanged);
    connect(m_plasmaWindow, &PlasmaWindow::parentWindowChanged, this, &DPlasmaWindow::ParentWindowChanged);
    connect(m_plasmaWindow, &PlasmaWindow::plasmaVirtualDesktopEntered, this, &DPlasmaWindow::PlasmaVirtualDesktopEntered);
    connect(m_plasmaWindow, &PlasmaWindow::plasmaVirtualDesktopLeft, this, &DPlasmaWindow::PlasmaVirtualDesktopLeft);
    connect(m_plasmaWindow, &PlasmaWindow::resizableChanged, this, &DPlasmaWindow::ResizableChanged);
    connect(m_plasmaWindow, &PlasmaWindow::shadeableChanged, this, &DPlasmaWindow::ShadeableChanged);
    connect(m_plasmaWindow, &PlasmaWindow::shadedChanged, this, &DPlasmaWindow::ShadedChanged);
    connect(m_plasmaWindow, &PlasmaWindow::skipSwitcherChanged, this, &DPlasmaWindow::SkipSwitcherChanged);
    connect(m_plasmaWindow, &PlasmaWindow::skipTaskbarChanged, this, &DPlasmaWindow::SkipTaskbarChanged);
    connect(m_plasmaWindow, &PlasmaWindow::titleChanged, this, &DPlasmaWindow::TitleChanged);
    connect(m_plasmaWindow, &PlasmaWindow::unmapped, this, &DPlasmaWindow::Unmapped);
    connect(m_plasmaWindow, &PlasmaWindow::virtualDesktopChangeableChanged, this, &DPlasmaWindow::VirtualDesktopChangeableChanged);
    connect(m_plasmaWindow, &PlasmaWindow::virtualDesktopChanged, this, &DPlasmaWindow::VirtualDesktopChanged);
}

QString DPlasmaWindow::AppId() const
{
    if (m_plasmaWindow != nullptr) {
         return m_plasmaWindow->appId();
    }

    return QString();
}

void DPlasmaWindow::Destroy()
{
    if (m_plasmaWindow != nullptr) {
        m_plasmaWindow->destroy();
    }
}

QRect DPlasmaWindow::Geometry() const
{
    if (m_plasmaWindow != nullptr) {
        return m_plasmaWindow->geometry();
    }

    return QRect();
}

QIcon DPlasmaWindow::Icon () const
{
    if (m_plasmaWindow != nullptr) {
        return m_plasmaWindow->icon();
    }

    return QIcon();
}

quint32 DPlasmaWindow::InternalId () const
{
    if (m_plasmaWindow != nullptr) {
        return m_plasmaWindow->internalId();
    }

    return 0;
}

bool DPlasmaWindow::DPlasmaWindow::IsActive () const
{
    if (m_plasmaWindow != nullptr) {
        return m_plasmaWindow->isActive();
    }

    return false;
}

bool DPlasmaWindow::IsCloseable () const
{
    if (m_plasmaWindow != nullptr) {
        return m_plasmaWindow->isCloseable();
    }

    return false;
}

bool DPlasmaWindow::IsDemandingAttention () const
{
    if (m_plasmaWindow != nullptr) {
        return m_plasmaWindow->isDemandingAttention();
    }

    return false;
}

bool DPlasmaWindow::IsFullscreen () const
{
    if (m_plasmaWindow != nullptr) {
        return m_plasmaWindow->isFullscreen();
    }

    return false;
}

bool DPlasmaWindow::IsFullscreenable () const
{
    if (m_plasmaWindow != nullptr) {
        return m_plasmaWindow->isFullscreenable();
    }

    return false;
}

bool DPlasmaWindow::IsKeepAbove () const
{
    if (m_plasmaWindow != nullptr) {
        return m_plasmaWindow->isKeepAbove();
    }

    return false;
}

bool DPlasmaWindow::IsKeepBelow () const
{
    if (m_plasmaWindow != nullptr) {
        return m_plasmaWindow->isKeepBelow();
    }

    return false;
}

bool DPlasmaWindow::IsMaximizeable () const
{
    if (m_plasmaWindow != nullptr) {
        return m_plasmaWindow->isMaximizeable();
    }

    return false;
}

bool DPlasmaWindow::IsMaximized () const
{
    if (m_plasmaWindow != nullptr) {
        return m_plasmaWindow->isMaximized();
    }

    return false;
}

bool DPlasmaWindow::IsMinimizeable () const
{
    if (m_plasmaWindow != nullptr) {
        return m_plasmaWindow->isMinimizeable();
    }

    return false;
}

bool DPlasmaWindow::IsMinimized () const
{
    if (m_plasmaWindow != nullptr) {
        return m_plasmaWindow->isMinimized();
    }

    return false;
}

bool DPlasmaWindow::IsMovable () const
{
    if(m_plasmaWindow != nullptr) {
        return m_plasmaWindow->isMovable();
    }

    return false;
}

bool DPlasmaWindow::IsOnAllDesktops () const
{
    if (m_plasmaWindow != nullptr) {
        return m_plasmaWindow->isOnAllDesktops();
    }

    return false;
}

bool DPlasmaWindow::IsResizable () const
{
    if (m_plasmaWindow != nullptr) {
        return m_plasmaWindow->isResizable();
    }

    return false;
}

bool DPlasmaWindow::IsShadeable () const
{
    if (m_plasmaWindow != nullptr) {
        return m_plasmaWindow->isShadeable();
    }

    return false;
}

bool DPlasmaWindow::IsShaded () const
{
    if (m_plasmaWindow != nullptr) {
        return m_plasmaWindow->isShaded();
    }

    return false;
}

bool DPlasmaWindow::IsValid () const
{
    if (m_plasmaWindow != nullptr) {
        return m_plasmaWindow->isValid();
    }

    return false;
}

bool DPlasmaWindow::IsVirtualDesktopChangeable () const
{
    if (m_plasmaWindow != nullptr) {
        return m_plasmaWindow->isVirtualDesktopChangeable();
    }

    return false;
}

quint32 DPlasmaWindow::Pid () const
{
    if (m_plasmaWindow != nullptr) {
        return m_plasmaWindow->pid();
    }

    return 0;
}

QStringList DPlasmaWindow::PlasmaVirtualDesktops () const
{
    if (m_plasmaWindow != nullptr) {
        return m_plasmaWindow->plasmaVirtualDesktops();
    }

    return QStringList();
}

void DPlasmaWindow::Release ()
{
    if (m_plasmaWindow != nullptr) {
        m_plasmaWindow->release();
    }
}

void DPlasmaWindow::RequestActivate ()
{
    if (m_plasmaWindow != nullptr) {
        m_plasmaWindow->requestActivate();
    }
}

void DPlasmaWindow::RequestClose ()
{
    if (m_plasmaWindow != nullptr) {
        m_plasmaWindow->requestClose();
    }
}

void DPlasmaWindow::RequestEnterNewVirtualDesktop ()
{
    if (m_plasmaWindow != nullptr) {
        m_plasmaWindow->requestEnterNewVirtualDesktop();
    }
}

void DPlasmaWindow::RequestEnterVirtualDesktop (const QString &id)
{
    if (m_plasmaWindow != nullptr) {
        m_plasmaWindow->requestEnterVirtualDesktop(id);
    }
}

void DPlasmaWindow::RequestLeaveVirtualDesktop (const QString &id)
{
    if (m_plasmaWindow != nullptr) {
        m_plasmaWindow->requestLeaveVirtualDesktop(id);
    }
}

void DPlasmaWindow::RequestMove ()
{
    if (m_plasmaWindow != nullptr) {
        m_plasmaWindow->requestMove();
    }
}

void DPlasmaWindow::RequestResize ()
{
    if (m_plasmaWindow != nullptr) {
        m_plasmaWindow->requestResize();
    }
}

void DPlasmaWindow::RequestToggleKeepAbove ()
{
    if (m_plasmaWindow != nullptr) {
        m_plasmaWindow->requestToggleKeepAbove();
    }
}

void DPlasmaWindow::RequestToggleKeepBelow ()
{
    if (m_plasmaWindow != nullptr) {
        m_plasmaWindow->requestToggleKeepBelow();
    }
}

void DPlasmaWindow::RequestToggleMaximized ()
{
    if (m_plasmaWindow != nullptr) {
        m_plasmaWindow->requestToggleMaximized();
    }
}

void DPlasmaWindow::RequestToggleMinimized ()
{
    if (!m_plasmaWindow) {
        m_plasmaWindow->requestToggleMinimized();
    }
}

void DPlasmaWindow::RequestToggleShaded ()
{
    if (m_plasmaWindow != nullptr) {
        m_plasmaWindow->requestToggleShaded();
    }
}

void DPlasmaWindow::RequestVirtualDesktop (quint32 desktop)
{
    if (m_plasmaWindow != nullptr) {
        m_plasmaWindow->requestVirtualDesktop(desktop);
    }
}

void DPlasmaWindow::SetMinimizedGeometry (Surface *panel, const QRect &geom)
{
    if (m_plasmaWindow != nullptr) {
        m_plasmaWindow->setMinimizedGeometry(panel, geom);
    }
}

bool DPlasmaWindow::SkipSwitcher () const
{
    if (m_plasmaWindow != nullptr) {
        return m_plasmaWindow->skipSwitcher();
    }

    return false;
}

bool DPlasmaWindow::SkipTaskbar () const
{
    if (m_plasmaWindow != nullptr) {
        return m_plasmaWindow->skipTaskbar();
    }

    return false;
}

QString DPlasmaWindow::Title () const
{
    if (m_plasmaWindow != nullptr) {
        return m_plasmaWindow->title();
    }

    return QString();
}

void DPlasmaWindow::UnsetMinimizedGeometry (Surface *panel)
{
    if (m_plasmaWindow != nullptr) {
        m_plasmaWindow->unsetMinimizedGeometry(panel);
    }
}

quint32 DPlasmaWindow::VirtualDesktop () const
{
    if (m_plasmaWindow != nullptr) {
        return m_plasmaWindow->virtualDesktop();
    }

    return 0;
}
