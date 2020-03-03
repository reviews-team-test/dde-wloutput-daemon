#ifndef SIGNAL_HANDLER_H
#define SIGNAL_HANDLER_H

#include <QObject>

class signal_handler : public QObject
{
    Q_OBJECT
public:
    explicit signal_handler(QObject *parent = nullptr);

public slots:
    void onOutputAdded(QString output);
    void onOutputRemoved(QString output);
    void onOutputChanged(QString output);
};

#endif // SIGNAL_HANDLER_H
