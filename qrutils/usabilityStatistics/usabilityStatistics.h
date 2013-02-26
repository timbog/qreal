#pragma once

#include <QtCore/QFile>
#include <QtCore/QTextStream>

#include "../utilsDeclSpec.h"

namespace utils {

class QRUTILS_EXPORT UsabilityStatistics {

public:
	static UsabilityStatistics* instance();
	~UsabilityStatistics();

	static void reportCreation(QString const &editorName, QString const elementName);
	static void reportErrors(QString const &type, QString const &editorName, QString const &elementName, QString const &message);
	static void reportTotalTime(QString const &totalTime, int const &exitCode);
	static void reportMenuElements(QString const &elementName, QString const &status = "none");
private:
	UsabilityStatistics();

	void reportCreationOfElements(QString const &editorName, QString const elementName);
	void reportErrorsOfElements(QString const &type, QString const &editorName, QString const &elementName, QString const &message);
	void reportTotalTimeOfExec(QString const &totalTime, int const &exitCode);
	void reportMenuElementsUsing(QString const &elementName, QString const &status = "none");

	static UsabilityStatistics* object;

	QFile mElementOnSceneCreationFile;
	static QTextStream elementOnSceneCreationStream;
	static int creationNumber;

	QFile mErrorReporterFile;
	static QTextStream errorReporterStream;
	static int errorReporterNumber;

	QFile mTotalTimeFile;
	static QTextStream totalTimeStream;

	//QTextStream mMouseClickPositionStream;

	QFile mMenuElementUsingFile;
	static QTextStream menuElementUsingStream;
	static int menuElementUsingNumber;

};
}
