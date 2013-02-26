#include <QtCore/QDir>
#include <QtCore/QDate>
#include <QtCore/QDebug>

#include "usabilityStatistics.h"

using namespace utils;

UsabilityStatistics* UsabilityStatistics::object = NULL;

QTextStream UsabilityStatistics::elementOnSceneCreationStream;
QTextStream UsabilityStatistics::errorReporterStream;
QTextStream UsabilityStatistics::totalTimeStream;
QTextStream UsabilityStatistics::menuElementUsingStream;

int UsabilityStatistics::creationNumber;
int UsabilityStatistics::errorReporterNumber;
int UsabilityStatistics::menuElementUsingNumber;

QString const elementCreationFileName = "/elementOnSceneCreation.txt";
QString const errorReporterFileName = "/errorReporter.txt";
QString const totalTimeFileName = "/totalTime.txt";
QString const menuElementUsingFileName = "/menuElementUsing.txt";

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

	mMenuElementUsingFile.setFileName(dir.absolutePath() + menuElementUsingFileName);
	if (mMenuElementUsingFile.open(QFile::WriteOnly | QFile::Truncate)) {
		menuElementUsingStream.setDevice(&mMenuElementUsingFile);
	}
	menuElementUsingNumber = 1;
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

void UsabilityStatistics::reportMenuElementsUsing(const QString &elementName, const QString &status)
{
	QDateTime now = QDateTime::currentDateTime();
	QString const statusText = (status == "none") ? "" : status + " ";
	menuElementUsingStream << menuElementUsingNumber << " " << elementName << " " << statusText << now.toString() << "\n";
	menuElementUsingNumber++;
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
	mMenuElementUsingFile.close();

	QDir dir(".");
	QDateTime now = QDateTime::currentDateTime();

	QString const oldElementOnSceneCreationName = mElementOnSceneCreationFile.fileName();
	QString const oldErrorReporterName = mErrorReporterFile.fileName();
	QString const oldTotalTimeName = mTotalTimeFile.fileName();
	QString const oldMenuElementUsingName = mMenuElementUsingFile.fileName();

	QString const newDirName = now.toString().replace(" ", "_").replace(".", "_").replace(":", "_");
	QString const newFileElementOnSceneCreationName = newDirName + elementCreationFileName;
	QString const newFileErrorReporterName = newDirName + errorReporterFileName;
	QString const newFileTotalTimeName = newDirName + totalTimeFileName;
	QString const newFileMenuElementUsingName = newDirName + menuElementUsingFileName;

	if (dir.cdUp()) {
		dir.cd("usabilityFiles");
		QString const dirAbsolutePathName = dir.absolutePath() + "/";
		QString const newElementOnSceneCreationName = dirAbsolutePathName + newFileElementOnSceneCreationName;
		QString const newErrorReporterName = dirAbsolutePathName + newFileErrorReporterName;
		QString const newTotalTimeName = dirAbsolutePathName + newFileTotalTimeName;
		QString const newMenuElementUsingName = dirAbsolutePathName + newFileMenuElementUsingName;

		dir.mkdir(newDirName);
		QFile::copy(oldElementOnSceneCreationName, newElementOnSceneCreationName);
		QFile::copy(oldErrorReporterName, newErrorReporterName);
		QFile::copy(oldTotalTimeName, newTotalTimeName);
		QFile::copy(oldMenuElementUsingName, newMenuElementUsingName);
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

void UsabilityStatistics::reportMenuElements(const QString &elementName, const QString &status)
{
	instance()->reportMenuElementsUsing(elementName, status);
}
