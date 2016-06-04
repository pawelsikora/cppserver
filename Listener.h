#ifndef LISTENER_H
#define LISTENER_H

#include <QThread>
#include <QDebug>
#include "Logger.h"
#include <QTcpSocket>
#include <QByteArray>
#include <QAbstractSocket>
#include <QString>

class Listener : public QThread, public QString
{
	Q_OBJECT
	
	int socket;
public:
	
	Listener(int sockfd)
	{
		this->socket = sockfd;
		logger = new Logger(NULL, "listener_thread.log");
	}

	void run()
	{
		QString str = QString("New Thread on socket %1").arg(this->socket);
		qDebug() << "Thread start with socket: " << this->socket;
		logger->write(str);
/*
    while (server->hasPendingConnections())
    {
        QTcpSocket *socket = server->nextPendingConnection();
        connect(socket, SIGNAL(readyRead()), SLOT(readyRead()));
        connect(socket, SIGNAL(disconnected()), SLOT(disconnected()));
        QByteArray *buffer = new QByteArray();
        qint32 *s = new qint32(0);
        buffers.insert(socket, buffer);
        sizes.insert(socket, s);
    }
*/
	}	


private:
	Logger *logger;
};

#endif // LISTENER_H
