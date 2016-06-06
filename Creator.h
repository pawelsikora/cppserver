#ifndef CREATOR_H
#define CREATOR_H

#include <QDebug>
#include <QSqlDatabase>
#include "Logger.h"

class Creator
{


	public:
		Logger *log;

		QSqlDatabase database()
		{
			qDebug() << "Creating sql database for storing sensor data...";
			QSqlDatabase db;
			db = QSqlDatabase::addDatabase("QSQLITE");
			db.setDatabaseName("db.sql");
			return db;
			
		}

		Logger* logger()
		{
			log = new Logger(NULL, "tcpserver.log");
			return log;
		}
		
};

#endif
