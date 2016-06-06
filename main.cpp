// https://wiki.qt.io

#include <unistd.h>

#include <cstdlib>

#include <QCoreApplication>
#include <QDebug>
#include <QSettings>
#include <QStringList>

#include "IotServer.h"
#include "Listener.h"
#include "Logger.h"


int main(int argc, char** argv)
{
	QCoreApplication app(argc, argv);
	QStringList cmdLine = QCoreApplication::arguments();
	
	QSettings settings("myapp.ini", QSettings::IniFormat);
	settings.setValue("tcpport", 6666);
	settings.setValue("tcpip", "127.0.0.1");

	qDebug() << "Command Line args:";
	
	for (QStringList::iterator it = cmdLine.begin(); it != cmdLine.end(); ++it)
	{
		qDebug() << *it;

	}
	if (cmdLine.count() == 2)
	{
		if (cmdLine[1] == "-d")
		{
			qDebug() << "Daemonizing...";
			daemon(1, 0);
		}
		else
			qDebug() << "Running as standalone application...";
	}

	IotServer iotServer;
	qDebug() << "Starting server...";
	iotServer.run();

	return app.exec();
}
