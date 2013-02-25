#include <QtCore/QDir>
#include <QtCore/QDate>
#include <QtCore/QDebug>

#include "usabilityStatistics.h"

using namespace utils;

UsabilityStatistics* UsabilityStatistics::object = NULL;

QTextStream UsabilityStatistics::elementOnSceneCreationStream;
QTextStream UsabilityStatistics::errorReporterStream;
QTextStream UsabilityStatistics::totalTimeStream;

int UsabilityStatistics::creationNumber;
int UsabilityStatistics::errorReporterNumber;

QString const elementCreationFileName = "/elementOnSceneCreation.txt";
QString const errorReporterFileName = "/errorReporter.txt";
QString const totalTimeFileName = "/totalTime.txt";

UsabilityStatistics::UsabilityStatistics()
{
	QDir dir(".");

	mElementOnSceneCreationFile.setFileName(dir.absolutePath() + elementCreationFileName);//создать и открыть все файлы
	if (mElementOnSceneCreationFile.open(QFile::WriteOnly | QFile::Truncate)) {
		elementOnSceneCreationStream.setDevice(&mElementOnSceneCreationFile);
	}
	creationNumber = 1;

	mErrorReporterFile.setFileName(dir.absolutePath() + errorReporterFileName);
	if (mErrorReporterFile.open(QFile::WriteOnly | QFile::Truncate)) {
		errorReporterStream.setDevice(&mErrorReporterFile);
	}
	errorReporterNumber = 1;

	mTotalTimeFile.setFileName(dir.absolutePath() + totalTimeFileName);
	if (mTotalTimeFile.open(QFile::WriteOnly | QFile::Truncate)) {
		totalTimeStream.setDevice(&mTotalTimeFile);
	}
}

void UsabilityStatistics::reportCreationOfElements(const QString &editorName, const QString elementName)
{
	QDateTime now = QDateTime::currentDateTime();
	elementOnSceneCreationStream << creationNumber << " " << editorName << " " << elementName << " " << now.toString() << "\n";
	creationNumber++;
}

void UsabilityStatistics::reportErrorsOfElements(const QString &type, const QString &editorName, const QString &elementName, const QString &message)
{
	QDateTime now = QDateTime::currentDateTime();
	errorReporterStream << errorReporterNumber << " " << type << " " << editorName << " " << elementName << " " << message << " " << now.toString() << "\n";
	errorReporterNumber++;
}

void UsabilityStatistics::reportTotalTimeOfExec(const QString &totalTime, const int &exitCode)
{
	totalTimeStream << "TotalSessionTime: " << totalTime << "msecs Exit code:" << exitCode << "\n";
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
	mErrorReporterFile.close();
	mTotalTimeFile.close();

	QDir dir(".");
	QDateTime now = QDateTime::currentDateTime();

	QString const oldElementOnSceneCreationName = mElementOnSceneCreationFile.fileName();
	QString const oldErrorReporterName = mErrorReporterFile.fileName();
	QString const oldTotalTimeName = mTotalTimeFile.fileName();

	QString const newDirName = now.toString().replace(" ", "_").replace(".", "_").replace(":", "_");
	QString const newFileElementOnSceneCreationName = newDirName + elementCreationFileName;
	QString const newFileErrorReporterName = newDirName + errorReporterFileName;
	QString const newFileTotalTimeName = newDirName + totalTimeFileName;

	if (dir.cdUp()) {
		dir.cd("usabilityFiles");
		QString const dirAbsolutePathName = dir.absolutePath() + "/";
		QString const newElementOnSceneCreationName = dirAbsolutePathName + newFileElementOnSceneCreationName;
		QString const newErrorReporterName = dirAbsolutePathName + newFileErrorReporterName;
		QString const newTotalTimeName = dirAbsolutePathName + newFileTotalTimeName;

		qDebug() << oldTotalTimeName << " " << newTotalTimeName;
		dir.mkdir(newDirName);
		QFile::copy(oldElementOnSceneCreationName, newElementOnSceneCreationName);
		QFile::copy(oldErrorReporterName, newErrorReporterName);
		QFile::copy(oldTotalTimeName, newTotalTimeName);
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

void UsabilityStatistics::reportTotalTime(QString const &totalTime, int const &exitCode)
{
	instance()->reportTotalTimeOfExec(totalTime, exitCode);
}
