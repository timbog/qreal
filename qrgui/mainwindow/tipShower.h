#ifndef TIPSHOWER_H
#define TIPSHOWER_H

#include <QObject>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>

class TipShower : public QObject
{
	Q_OBJECT
public:
	//explicit TipShower(QObject *parent = 0);

	static TipShower *instance();
public slots:
	QWidget *currentTip();

	void hideTip();

signals:

private:
	QWidget *mTip;

	static TipShower *mInstance;

	QString mTipText[5];

	int mTipNumber;

	TipShower();

	QLabel *mTipLabel;
};

#endif // TIPSHOWER_H
