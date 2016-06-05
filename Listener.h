#ifndef LISTENER_H
#define LISTENER_H

#include <QThread>
#include <QDebug>
#include "Logger.h"
#include <QTcpSocket>
#include <QByteArray>
#include <QAbstractSocket>
#include <QString>
#include <QTcpServer>

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
	
//		newSocket = new QTcpSocket();
//		
//		this->newSocket->setSocketDescriptor(socket);
//
//		qDebug() << this->newSocket->socketDescriptor();
//
//		if(newSocket)
//		{
//			connect(this->newSocket, SIGNAL(readyRead()),this,SLOT(on_readyRead()));
//
//			connect(this->newSocket, SIGNAL(disconnected()),this->newSocket ,SLOT(deleteLater()));
//		}
	}

public slots:

//	void on_readyRead()
//	{
//		//QTcpSocket * senderSocket = dynamic_cast<QTcpSocket*>(sender());
//		QTcpSocket * senderSocket = this->newSocket;
//		if(senderSocket){
//			qDebug() << "reading data:";
//			qDebug() << senderSocket->readAll();
//		}
//	}

private:
	Logger *logger;
	QTcpSocket *newSocket;
};

#endif // LISTENER_H
