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
private:
	UsabilityStatistics();

	void reportCreationOfElements(const QString &editorName, const QString elementName);
	void reportErrorsOfElements(QString const &type, QString const &editorName, QString const &elementName, QString const &message);

	static UsabilityStatistics* object;
	//QTextStream mMouseClickPositionStream;
	QFile mElementOnSceneCreationFile;
	static QTextStream elementOnSceneCreationStream;
	static int creationNumber;

	QFile mErrorReporterFile;
	static QTextStream errorReporterStream;
	static int errorReporterNumber;
	//QTextStream mTotalTimeStream;
	//QTextStream mMenuElementUsingStream;

};
}
