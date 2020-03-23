#include "plasma_window_interface.h"
#include <QtDBus/QDBusMessage>
#include <QDBusInterface>

PlasmaWindowInterface::PlasmaWindowInterface(DPlasmaWindow* plasma_window)
    : QDBusAbstractAdaptor(plasma_window)
    , m_plasmaWindow(plasma_window)
{
    setAutoRelaySignals(true);

    InitConnect();
}

PlasmaWindowInterface::~PlasmaWindowInterface()
{
    if(m_plasmaWindow != nullptr)
        m_plasmaWindow->deleteLater();
}

void PlasmaWindowInterface::InitConnect()
{
    qDebug() << "on plasma Window created, title:" << m_plasmaWindow->Title();

    connect(m_plasmaWindow, &DPlasmaWindow::ActiveChanged, this, &PlasmaWindowInterface::ActiveChanged);
    connect(m_plasmaWindow, &DPlasmaWindow::AppIdChanged, this, &PlasmaWindowInterface::AppIdChanged);
    connect(m_plasmaWindow, &DPlasmaWindow::CloseableChanged, this, &PlasmaWindowInterface::CloseableChanged);
    connect(m_plasmaWindow, &DPlasmaWindow::DemandsAttentionChanged, this, &PlasmaWindowInterface::DemandsAttentionChanged);
    connect(m_plasmaWindow, &DPlasmaWindow::FullscreenableChanged, this, &PlasmaWindowInterface::FullscreenableChanged);
    connect(m_plasmaWindow, &DPlasmaWindow::FullscreenChanged, this, &PlasmaWindowInterface::FullscreenChanged);
    connect(m_plasmaWindow, &DPlasmaWindow::GeometryChanged, this, &PlasmaWindowInterface::GeometryChanged);
    connect(m_plasmaWindow, &DPlasmaWindow::IconChanged, this, &PlasmaWindowInterface::IconChanged);
    connect(m_plasmaWindow, &DPlasmaWindow::KeepAboveChanged, this, &PlasmaWindowInterface::KeepAboveChanged);
    connect(m_plasmaWindow, &DPlasmaWindow::KeepBelowChanged, this, &PlasmaWindowInterface::KeepBelowChanged);
    connect(m_plasmaWindow, &DPlasmaWindow::MaximizeableChanged, this, &PlasmaWindowInterface::MaximizeableChanged);
    connect(m_plasmaWindow, &DPlasmaWindow::MaximizedChanged, this, &PlasmaWindowInterface::MaximizedChanged);
    connect(m_plasmaWindow, &DPlasmaWindow::MinimizeableChanged, this, &PlasmaWindowInterface::MinimizeableChanged);
    connect(m_plasmaWindow, &DPlasmaWindow::MinimizedChanged, this, &PlasmaWindowInterface::MinimizedChanged);
    connect(m_plasmaWindow, &DPlasmaWindow::MovableChanged, this, &PlasmaWindowInterface::MovableChanged);
    connect(m_plasmaWindow, &DPlasmaWindow::OnAllDesktopsChanged, this, &PlasmaWindowInterface::OnAllDesktopsChanged);
    connect(m_plasmaWindow, &DPlasmaWindow::ParentWindowChanged, this, &PlasmaWindowInterface::ParentWindowChanged);
    connect(m_plasmaWindow, &DPlasmaWindow::PlasmaVirtualDesktopEntered, this, &PlasmaWindowInterface::PlasmaVirtualDesktopEntered);
    connect(m_plasmaWindow, &DPlasmaWindow::PlasmaVirtualDesktopLeft, this, &PlasmaWindowInterface::PlasmaVirtualDesktopLeft);
    connect(m_plasmaWindow, &DPlasmaWindow::ResizableChanged, this, &PlasmaWindowInterface::ResizableChanged);
    connect(m_plasmaWindow, &DPlasmaWindow::ShadeableChanged, this, &PlasmaWindowInterface::ShadeableChanged);
    connect(m_plasmaWindow, &DPlasmaWindow::ShadedChanged, this, &PlasmaWindowInterface::ShadedChanged);
    connect(m_plasmaWindow, &DPlasmaWindow::SkipSwitcherChanged, this, &PlasmaWindowInterface::SkipSwitcherChanged);
    connect(m_plasmaWindow, &DPlasmaWindow::SkipTaskbarChanged, this, &PlasmaWindowInterface::SkipTaskbarChanged);
    connect(m_plasmaWindow, &DPlasmaWindow::TitleChanged, this, &PlasmaWindowInterface::TitleChanged);
    connect(m_plasmaWindow, &DPlasmaWindow::Unmapped, this, &PlasmaWindowInterface::Unmapped);
    connect(m_plasmaWindow, &DPlasmaWindow::VirtualDesktopChangeableChanged, this, &PlasmaWindowInterface::VirtualDesktopChangeableChanged);
    connect(m_plasmaWindow, &DPlasmaWindow::VirtualDesktopChanged, this, &PlasmaWindowInterface::VirtualDesktopChanged);
}

QString PlasmaWindowInterface::AppId() const
{
    return m_plasmaWindow->AppId();
}

void PlasmaWindowInterface::Destroy()
{
    m_plasmaWindow->Destroy();
}

QRect PlasmaWindowInterface::Geometry() const
{
    return m_plasmaWindow->Geometry();
}

QIcon PlasmaWindowInterface::Icon () const
{
    return m_plasmaWindow->Icon();
}

quint32 PlasmaWindowInterface::InternalId () const
{
    return m_plasmaWindow->InternalId();
}

bool PlasmaWindowInterface::PlasmaWindowInterface::IsActive () const
{
    return m_plasmaWindow->IsActive();
}

bool PlasmaWindowInterface::IsCloseable () const
{
    return m_plasmaWindow->IsCloseable();
}

bool PlasmaWindowInterface::IsDemandingAttention () const
{
    return m_plasmaWindow->IsDemandingAttention();
}

bool PlasmaWindowInterface::IsFullscreen () const
{
    return m_plasmaWindow->IsFullscreen();
}

bool PlasmaWindowInterface::IsFullscreenable () const
{
    return m_plasmaWindow->IsFullscreenable();
}

bool PlasmaWindowInterface::IsKeepAbove () const
{
    return m_plasmaWindow->IsKeepAbove();
}

bool PlasmaWindowInterface::IsKeepBelow () const
{
    return m_plasmaWindow->IsKeepBelow();
}

bool PlasmaWindowInterface::IsMaximizeable () const
{
    return m_plasmaWindow->IsMaximizeable();
}

bool PlasmaWindowInterface::IsMaximized () const
{
    return m_plasmaWindow->IsMaximized();
}

bool PlasmaWindowInterface::IsMinimizeable () const
{
    return m_plasmaWindow->IsMinimizeable();
}

bool PlasmaWindowInterface::IsMinimized () const
{
    return m_plasmaWindow->IsMinimized();
}

bool PlasmaWindowInterface::IsMovable () const
{
    return m_plasmaWindow->IsMovable();
}

bool PlasmaWindowInterface::IsOnAllDesktops () const
{
    return m_plasmaWindow->IsOnAllDesktops();
}

bool PlasmaWindowInterface::IsResizable () const
{
    return m_plasmaWindow->IsResizable();
}

bool PlasmaWindowInterface::IsShadeable () const
{
    return m_plasmaWindow->IsShadeable();
}

bool PlasmaWindowInterface::IsShaded () const
{
    return m_plasmaWindow->IsShaded();
}

bool PlasmaWindowInterface::IsValid () const
{
    return m_plasmaWindow->IsValid();
}

bool PlasmaWindowInterface::IsVirtualDesktopChangeable () const
{
    return m_plasmaWindow->IsVirtualDesktopChangeable();
}

quint32 PlasmaWindowInterface::Pid () const
{
    return m_plasmaWindow->Pid();
}

QStringList PlasmaWindowInterface::PlasmaVirtualDesktops () const
{
    return m_plasmaWindow->PlasmaVirtualDesktops();
}

void PlasmaWindowInterface::Release ()
{
    m_plasmaWindow->Release();
}

void PlasmaWindowInterface::RequestActivate ()
{
    m_plasmaWindow->RequestActivate();
}

void PlasmaWindowInterface::RequestClose ()
{
    m_plasmaWindow->RequestClose();
}

void PlasmaWindowInterface::RequestEnterNewVirtualDesktop ()
{
    m_plasmaWindow->RequestEnterNewVirtualDesktop();
}

void PlasmaWindowInterface::RequestEnterVirtualDesktop (const QString &id)
{
    m_plasmaWindow->RequestEnterVirtualDesktop(id);
}

void PlasmaWindowInterface::RequestLeaveVirtualDesktop (const QString &id)
{
    m_plasmaWindow->RequestLeaveVirtualDesktop(id);
}

void PlasmaWindowInterface::RequestMove ()
{
    m_plasmaWindow->RequestMove();
}

void PlasmaWindowInterface::RequestResize ()
{
    m_plasmaWindow->RequestResize();
}

void PlasmaWindowInterface::RequestToggleKeepAbove ()
{
    m_plasmaWindow->RequestToggleKeepAbove();
}

void PlasmaWindowInterface::RequestToggleKeepBelow ()
{
    m_plasmaWindow->RequestToggleKeepBelow();
}

void PlasmaWindowInterface::RequestToggleMaximized ()
{
    m_plasmaWindow->RequestToggleMaximized();
}

void PlasmaWindowInterface::RequestToggleMinimized ()
{
    m_plasmaWindow->RequestToggleMinimized();
}

void PlasmaWindowInterface::RequestToggleShaded ()
{
    m_plasmaWindow->RequestToggleShaded();
}

void PlasmaWindowInterface::RequestVirtualDesktop (quint32 desktop)
{
    m_plasmaWindow->RequestVirtualDesktop(desktop);
}

void PlasmaWindowInterface::SetMinimizedGeometry (Surface *panel, const QRect &geom)
{
    m_plasmaWindow->SetMinimizedGeometry(panel, geom);
}

bool PlasmaWindowInterface::SkipSwitcher () const
{
    return m_plasmaWindow->SkipSwitcher();
}

bool PlasmaWindowInterface::SkipTaskbar () const
{
    return m_plasmaWindow->SkipTaskbar();
}

QString PlasmaWindowInterface::Title () const
{
    return m_plasmaWindow->Title();
}

void PlasmaWindowInterface::UnsetMinimizedGeometry (Surface *panel)
{
    m_plasmaWindow->UnsetMinimizedGeometry(panel);
}

quint32 PlasmaWindowInterface::VirtualDesktop () const
{
    return m_plasmaWindow->VirtualDesktop();
}
