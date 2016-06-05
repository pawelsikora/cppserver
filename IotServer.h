#ifndef IOTSERVER_H
#define IOTSERVER_H

#include <QObject>
#include <QTcpServer>
#include "Listener.h"
#include <QtSql/QtSql>
#include <QSignalMapper>

class Logger;
class Listener;

class IotServer : public QSignalMapper
{
	Q_OBJECT
	QTcpServer *server = new QTcpServer();

	private:
		Logger *logger;
		QTcpSocket* client;

public slots:
	
	void listenConnection()
	{
		QTcpSocket * newSocket = this->server->nextPendingConnection();
		
		qDebug() << this->server->socketDescriptor();

		if(newSocket)
		{
			connect(newSocket, SIGNAL(readyRead()),this,SLOT(on_readyRead()));

			connect(newSocket, SIGNAL(disconnected()),newSocket ,SLOT(deleteLater()));
		}
		
		int sockd = this->server->socketDescriptor();
		Listener *listener = new Listener(sockd);
		qDebug() << "Start listen... on socket:" << sockd;
		
		
		listener->start();
		// free
	}

	void run()
	{
		logger = new Logger(NULL, "tcpserver.log");
		logger->write("App starts");
	
		qDebug() << "Create sql database for storing sensor data...";
		QSqlDatabase db;
		db = QSqlDatabase::addDatabase("QSQLITE");
		db.setDatabaseName("db.sql");
		db.open();

		qDebug() << " Do sql query...";
		QSqlQuery query(db);
		query.exec("SELECT * FROM global;");
		
		while (query.next())
		{
			qDebug() << "name: " << query.value(0).toString() << " value: " << query.value(1).toString();
		}

		db.close();

		qDebug() << " Listen on port 6666...";
		this->server->listen(QHostAddress::Any, 6666);
		
		int sockd = this->server->socketDescriptor();
		qDebug() << " Connect to signal";
		
		connect(this->server, SIGNAL(newConnection()), this, SLOT(listenConnection()));
		qDebug() << "Socket descriptor = " << sockd;
		
		if(this->server->isListening())
			qDebug() << "Server is listening...";
		
	}

	void on_readyRead()
	{
		QTcpSocket * senderSocket = dynamic_cast<QTcpSocket*>(sender());
		if(senderSocket){
			qDebug() << "reading data:";
			qDebug() << senderSocket->readAll();
		}
	}
	

};
	

#endif // IOTSERVER_H
