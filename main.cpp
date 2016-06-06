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
	QString ip;
	QVariant tmp_qv;
	int port;
	
	QSettings settings("myapp.ini", QSettings::IniFormat);
	
	if(!settings.contains("tcpport"))
		settings.setValue("tcpport", 6666);
	if(!settings.contains("tcpip"))
		settings.setValue("tcpip", "127.0.0.1");

	tmp_qv = settings.value("tcpip");
	ip = tmp_qv.toString();

	tmp_qv = settings.value("tcpport");
	port = tmp_qv.toInt();

	qDebug() << "from setttings ip:" << ip;
	qDebug() << "from settings port: " << port;

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

	IotServer iotServer(ip, port);
	qDebug() << "Starting server...";
	iotServer.run();

	return app.exec();
}
