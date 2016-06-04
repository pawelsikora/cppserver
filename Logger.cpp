#include <QDateTime>
#include <QFile>
#include <QTextStream>

#include "Logger.h"

Logger::Logger(QObject *parent, QString fileName) : QObject(parent)
{
	if (!fileName.isEmpty())
	{
		m_file = new QFile;
		m_file->setFileName(fileName);
		m_file->open(QIODevice::Append | QIODevice::Text);
	}
}

Logger::~Logger() {
	if (m_file != 0)
		m_file->close();
}

void Logger::write(const QString &msg)
{
	QString text = "";
	text = QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss ") + msg;
	QTextStream out(m_file);
	out.setCodec("UTF-8");
	
	if (m_file != 0) {
		out << text;
	}
	out.flush();
}
