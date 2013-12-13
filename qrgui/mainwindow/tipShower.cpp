#include "tipShower.h"
#include "QtWidgets/QGroupBox"
#include "QtWidgets"
/*TipShower::TipShower(QObject *parent) :
	QObject(parent)
{
}*/
TipShower::TipShower()
{
	mTipText[0] = "Привет!Это QRealRobots, программа для управления роботами. Нажмите 'Создать проект' чтобы продолжить";
	mTipText[1] = "что-то1";
	mTipText[2] = "что-то2";
	mTipText[3] = "что-то3";
	mTipText[4] = "что-то4";
	mTipNumber = 0;
	mTipLabel = NULL;
}

TipShower *TipShower::mInstance = 0;

TipShower *TipShower::instance()
{
	if (mInstance == NULL) {
		mInstance = new TipShower();
	}
	return mInstance;
}

QWidget *TipShower::currentTip()
{
	if (mTipNumber == 0)
	{
		mTip = new QWidget();
		mTip->setGeometry(725, 675, 210, 75);
		mTip->setWindowFlags(Qt::ToolTip);
		QGroupBox *box = new QGroupBox(mTip);
		box->setGeometry(0, 0, 210, 75);
		QPushButton *okButton = new QPushButton(mTip);
		okButton->setGeometry(90, 50, 40, 20);
		okButton->setText("OK");
		okButton->activateWindow();
		//connect(okButton,SIGNAL(clicked()),this,SLOT(hideTip()));
		mTipLabel = new QLabel(mTip);
		mTipLabel->move(9, 9);
		mTipLabel->setWordWrap(true);
		mTipLabel->setAlignment(Qt::AlignCenter);
		mTipLabel->setText(mTipText[mTipNumber]);
		mTip->activateWindow();
		mTip->raise();
	}
	else
		mTipLabel->setText(mTipText[mTipNumber]);
	mTip->show();
	++mTipNumber;
	return mTip;
}

void TipShower::hideTip()
{
	mTip->hide();
}
