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
	
	for (QStringList::iterator it = cmdLine.begin(); it != cmdLine.end(); ++it)
	{
		
		if(*it == "-d")
		{
			qDebug() << "Daemonizing...";
			daemon(1, 0);
		
		} else if (*it == "-h" || *it == "--help")
		{
			qDebug() << "----- HELP -----\n"
				    "Start application with simply invoke ./cppserver "
				    "without any arguments.\n You can specify you ip address"
				    "and port in myapp.ini file.\n If file not exist, just "
				    "execute app first time and it will be created.\n Then just "
				    "replace default ip and port with values you want\n";
			exit(EXIT_SUCCESS);
		}
		
		//qDebug() << *it;
	}

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
	
	IotServer iotServer(ip, port);
	qDebug() << "Starting server...";
	iotServer.run();

	return app.exec();
}
