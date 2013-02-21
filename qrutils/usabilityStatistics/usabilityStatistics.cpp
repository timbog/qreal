#include <QtCore/QDir>
#include <QtCore/QDate>
#include <QtCore/QDebug>

#include "usabilityStatistics.h"

using namespace utils;

UsabilityStatistics* UsabilityStatistics::object = NULL;
QTextStream UsabilityStatistics::elementOnSceneCreationStream;
QTextStream UsabilityStatistics::errorReporterStream;
int UsabilityStatistics::creationNumber;
int UsabilityStatistics::errorReporterNumber;

UsabilityStatistics::UsabilityStatistics()
{
	QDir dir(".");

	mElementOnSceneCreationFile.setFileName(dir.absolutePath() + "/elementOnSceneCreation.txt");//создать и открыть все файлы
	if (mElementOnSceneCreationFile.open(QFile::WriteOnly | QFile::Truncate)) {
		elementOnSceneCreationStream.setDevice(&mElementOnSceneCreationFile);
	}
	creationNumber = 1;
	mErrorReporterFile.setFileName(dir.absolutePath() + "/errorReporter.txt");
	if (mErrorReporterFile.open(QFile::WriteOnly | QFile::Truncate)) {
		errorReporterStream.setDevice(&mErrorReporterFile);
	}
	errorReporterNumber = 1;
}

void UsabilityStatistics::reportCreationOfElements(const QString &editorName, const QString elementName)
{
	elementOnSceneCreationStream << creationNumber << " " << editorName << " " << elementName << "\n";
	creationNumber++;
}

void UsabilityStatistics::reportErrorsOfElements(const QString &type, const QString &editorName, const QString &elementName, const QString &message)
{
	errorReporterStream << errorReporterNumber << " " << type << " " << editorName << " " << elementName << " " << message <<  "\n";
	errorReporterNumber++;
}

UsabilityStatistics *UsabilityStatistics::instance()
{
	if (object == NULL) {
			object = new UsabilityStatistics();
		}
		return object;
}

UsabilityStatistics::~UsabilityStatistics()
{
	mElementOnSceneCreationFile.close();
	QDir dir(".");
	QDateTime now = QDateTime::currentDateTime();
	QString const oldName = mElementOnSceneCreationFile.fileName();
	QString const newDirName = now.toString().replace(" ", "_").replace(".", "_").replace(":", "_");
	QString const newFileName = newDirName + "/elementOnSceneCreation.txt";

	if (dir.cdUp()) {
		dir.cd("usabilityFiles");
		QString const newName = dir.absolutePath() + "/" + newFileName;
		//qDebug() << oldName << " " << newName;
		dir.mkdir(newDirName);
		QFile::copy(oldName, newName);
	}
	//закрыть все файлы и переместить в отдельное место хранения
}

void UsabilityStatistics::reportCreation(const QString &editorName, const QString elementName)
{
	instance()->reportCreationOfElements(editorName, elementName);
}

void UsabilityStatistics::reportErrors(const QString &type, const QString &editorName, const QString &elementName, const QString &message)
{
	instance()->reportErrorsOfElements(type, editorName, elementName, message);
}
