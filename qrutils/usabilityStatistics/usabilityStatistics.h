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
	static void reportTotalTime(const QString &totalTime, const int &exitCode);
private:
	UsabilityStatistics();

	void reportCreationOfElements(const QString &editorName, const QString elementName);
	void reportErrorsOfElements(QString const &type, QString const &editorName, QString const &elementName, QString const &message);
	void reportTotalTimeOfExec(const QString &totalTime, const int &exitCode);

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

	//QTextStream mMenuElementUsingStream;

};
}
