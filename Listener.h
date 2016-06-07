#ifndef LISTENER_H
#define LISTENER_H

#include <QThread>
#include <QDebug>
#include <QTcpSocket>
#include <QByteArray>
#include <QAbstractSocket>
#include <QString>
#include <QTcpServer>

#include "Logger.h"
#include "Creator.h"

class Listener : public QThread
{
	Q_OBJECT

private:
	int socket;
	Creator *create;
	Logger *logger;

public:
	
	Listener(int sockfd)
	{
		this->socket = sockfd;
		create = new Creator(); 
		logger = create->logger("listener_thread.log");
	}

	void run()
	{
		QString str = QString("New Thread on socket %1\n").arg(this->socket);
		qDebug() << "Thread start with socket: " << this->socket;
		logger->write(str);	
	}

};

#endif // LISTENER_H
