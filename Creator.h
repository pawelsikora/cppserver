#ifndef CREATOR_H
#define CREATOR_H

#include <QDebug>
#include <QSqlDatabase>
#include <QString>

#include "Logger.h"

class Creator : QObject
{
	Q_OBJECT

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
		
		QSqlDatabase database(QString filename)
		{
			qDebug() << "Creating sql database for storing sensor data...";
			QSqlDatabase db;
			db = QSqlDatabase::addDatabase("QSQLITE");
			db.setDatabaseName(filename);
			return db;
			
		}

		Logger* logger(QString filename)
		{
			log = new Logger(NULL, filename);
			return log;
		}
		
		Logger* logger()
		{
			log = new Logger(NULL, "default_creator.log");
			return log;
		}
		
};

#endif
