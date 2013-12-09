#include "tipShower.h"
#include "QtWidgets/QGroupBox"
#include "QtWidgets"
TipShower::TipShower(QObject *parent) :
	QObject(parent)
{
}

TipShower *TipShower::instance = 0;

TipShower *TipShower::Instance()
{
	if (instance == NULL) {
		instance = new TipShower();
	}
	return instance;
}

QWidget *TipShower::firstTip()
{
	QWidget *window = new QWidget();
	window->setGeometry(500, 400, 210, 75);
	window->setWindowFlags(Qt::ToolTip);
	QGroupBox *box = new QGroupBox(window);
	box->setGeometry(0, 0, 210, 75);
	QPushButton *okButton = new QPushButton(window);
	okButton->setGeometry(90, 50, 40, 20);
	okButton->setText("OK");
	okButton->activateWindow();
	QLabel *label = new QLabel(window);
	label->move(9, 9);
	label->setWordWrap(true);
	label->setAlignment(Qt::AlignCenter);
	label->setText("Привет!Это QRealRobots, программа для управления роботами. Нажмите 'Создать проект' чтобы продолжить");
	window->show();
	this->tip = window;
	window->activateWindow();
	window->raise();
	//connect(okButton,SIGNAL(clicked()),this,SLOT(hideTip()));
	return window;
}

void TipShower::hideTip()
{
	tip ->hide();
}
