#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>

class Application : public QApplication
{
	Q_OBJECT
public:
	//explicit Application(QObject *parent = 0);

	/// Constructor with command-line arguments.
	Application(int &argc, char **argv);

	bool notify(QObject *receiver, QEvent *event);
};

#endif // APPLICATION_H
