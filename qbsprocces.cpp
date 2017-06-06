#include "qbsprocces.h"

QbsProcces::QbsProcces(QWidget *parent):
    QWidget(parent),
    mProcess{new QProcess(this)}
{
    connect(mProcess, &QProcess::readyReadStandardOutput, this, &QbsProcces::signalOutput, Qt::UniqueConnection);
    connect(mProcess, &QProcess::readyReadStandardError, this, &QbsProcces::signalOutput, Qt::UniqueConnection);

    mProcess->setProcessChannelMode(QProcess::MergedChannels);
}

void QbsProcces::setPath(QString str)
{
    mPath = str;
}

void QbsProcces::signalOutput()
{
    QByteArray output = mProcess->readAll();
        emit outputRead(QString(output));
}

void QbsProcces::slotCommand()
{
    QStringList mArg;
    mArg << "config" << "--list" << "profiles";
    mProcess->start(mPath, mArg);
}

