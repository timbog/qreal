#pragma once

#include <QtGui/QApplication>

class QRealApplication : public QApplication
{
public:
	QRealApplication(int & argc, char ** argv);

protected:
	bool notify(QObject *, QEvent *);
};
