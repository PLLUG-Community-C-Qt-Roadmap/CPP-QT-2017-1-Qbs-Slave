#ifndef QBSPROCCES_H
#define QBSPROCCES_H

#include <QProcess>
#include <QWidget>
#include <QObject>
#include <QByteArray>
#include <QDebug>
#include <QStringList>

class QbsProcces : public QWidget
{
    Q_OBJECT
public:
    QbsProcces(QWidget *parent = 0);
    void setPath(QString str);
private:
    QProcess *mProcess;
    QString mPath;
public  slots:
    void signalOutput();
    void slotCommand();
signals:
    void outputRead(QString);
};

#endif // QBSPROCCES_H
