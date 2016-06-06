#ifndef CREATOR_H
#define CREATOR_H

#include <QDebug>
#include <QSqlDatabase>

class Creator
{


	public:
		QSqlDatabase database()
		{
			qDebug() << "Creating sql database for storing sensor data...";
			QSqlDatabase db;
			db = QSqlDatabase::addDatabase("QSQLITE");
			db.setDatabaseName("db.sql");
			return db;
			
		}
		
		
};

#endif
