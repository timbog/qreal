#include "mainwindow/mainWindow.h"
#include "thirdparty/windowsmodernstyle.h"
#include "../qrutils/usabilityStatistics/usabilityStatistics.h"

#include <QtCore/QtPlugin>
#include <QtGui/QApplication>

using namespace qReal;

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QTranslator appTranslator;
	QTranslator qtTranslator;
	if (app.arguments().count() <= 1 || app.arguments().at(1) != "--no-locale") {
		appTranslator.load(":/qrgui_" + QLocale::system().name());
		qtTranslator.load(":/qt_" + QLocale::system().name());
		app.installTranslator(&appTranslator);
		app.installTranslator(&qtTranslator);
	}

#ifndef NO_STYLE_WINDOWSMODERN
	app.setStyle(new WindowsModernStyle());
#endif

	MainWindow window;
	int exitCode = 0; // The window decided to not show itself, exiting now.
	if (window.isVisible())
		exitCode = app.exec();
	delete utils::UsabilityStatistics::instance();
	return exitCode;
}
