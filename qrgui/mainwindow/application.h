#pragma once

#include <QApplication>
#include <qrkernel/settingsManager.h>

namespace application {

/// Class which sets the order of tip changing
class Application : public QApplication
{
	Q_OBJECT
public:
	/// Constructor with command-line arguments.
	Application(int &argc, char **argv);

	/// Reimplemented function
	bool notify(QObject *receiver, QEvent *event);
};

}

