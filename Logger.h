#ifndef LOGGER_H
#define LOGGER_H

#include <QFile>
#include <QObject>
#include <QString>

class Logger : public QObject
{
	Q_OBJECT

public:
	explicit Logger(QObject *parent, QString fileName);
	~Logger();

private:
	QFile *m_file;

public slots:
	void write(const QString &msg);
};

#endif // LOGGER_H
