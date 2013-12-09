#ifndef TIPSHOWER_H
#define TIPSHOWER_H

#include <QObject>
#include <QtWidgets/QPushButton>

class TipShower : public QObject
{
	Q_OBJECT
public:
	explicit TipShower(QObject *parent = 0);

	static TipShower *Instance();

public slots:
	QWidget *firstTip();

	void hideTip();

signals:

private:
	QWidget *tip;

	static TipShower *instance;

	//TipShower();



};

#endif // TIPSHOWER_H
