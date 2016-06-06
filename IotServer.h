#ifndef IOTSERVER_H
#define IOTSERVER_H

#include <QObject>
#include <QTcpServer>
#include "Listener.h"
#include <QtSql/QtSql>
#include <QSignalMapper>
#include <Creator.h>

class Logger;
class Listener;

class IotServer : public QSignalMapper
{
	Q_OBJECT

	private:
		Logger *logger;
		QTcpSocket* client;
		QTcpServer *server = new QTcpServer();
		Creator *create;
		QHostAddress *ip_addr;

		int port;
	public:
		
		IotServer()
			: port (6666)
		{
			this->ip_addr = new QHostAddress("127.0.0.1");
		}

		IotServer( const QString ip_addr, int port)
		{
			this->ip_addr = new QHostAddress(ip_addr);
			this->port = port;
		}

	
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
		}

		void run()
		{
			//logger = new Logger(NULL, "tcpserver.log");
		
			create = new Creator();

			logger = create->logger("tcpserver.log");
			logger->write("Server app starts...\n");

			QSqlDatabase db = create->database();
			db.open();

			qDebug() << " Do sql query...";
			QSqlQuery query(db);
			query.exec("SELECT * FROM global;");
			
			while (query.next())
			{
				qDebug() << "name: " << query.value(0).toString() << \
					    " value: " << query.value(1).toString();
			}

			db.close();

			qDebug() << " Listen on port 6666...";
			//this->server->listen(QHostAddress::Any, 6666);
			this->server->listen(*(this->ip_addr), this->port);
			
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
				qDebug() << "Reading data:";
				QString readall = senderSocket->readAll();
				qDebug() << readall;
				logger->write("Reading data: \n");
				logger->write(readall);
			}
		}
	

};
	

#endif // IOTSERVER_H
