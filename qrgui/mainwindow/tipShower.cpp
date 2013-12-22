#include "tipShower.h"

#include "QtWidgets/QGroupBox"
#include "QtWidgets"

using namespace tipShower;

TipShower::TipShower()
{
	mTipText[0] = "Привет!Это QRealRobots, программа для управления роботами. Нажмите 'Создать проект' чтобы продолжить";
	mTipText[1] = "Отлично! Теперь на найдите на палитре раздел 'Инициализация'";
	mTipText[2] = "Перетащите на диаграмму блок с зеленым сигналом светофора";
	mTipText[3] = "Теперь перетащите на диаграмму блок с красным сигналом светофора";
	mTipText[4] = "Найдите на палитре раздел 'Действия'";
	mTipText[5] = "Перетащите на диаграмму блок с изображнием мотора и зеленой стрелкой";
	mTipText[6] = "Найдите на палитре раздел 'Ожидания'";
	mTipText[7] = "Перетащите последний блок из этого раздела на палитру";
	mTipText[8] = "Теперь нажмите на блок с зеленым сфетофором, который вы перенесли на диаграмму";
	mTipText[9] = "Нажмите на синий круг, и, не отрывая мыши, соедините первый блок с блоком с мотром";
	mTipText[10] = "Намите на блок с изображением мотора";
	mTipText[11] = "Аналогичным образом соедините его с блоком c таймером";
	mTipText[12] = "Намите на блок с изображением таймера";
	mTipText[13] = "Соедините его с последним блоком";
	mTipText[14] = "Нажмите на синюю стрелку";
	mTipText[15] = "Нажмите на черную стрелку";
	mTipText[16] = "Отлично! Вы создали свою первую программу, приводящую робота в движение. Удачи!";
	mTipText[17] = "govn";
	mCoordinats[0][0] = 725;
	mCoordinats[0][1] = 675;
	for (int i = 1; i < 14; ++i)
	{
		mCoordinats[i][0] = 725;
		mCoordinats[i][1] = 475;
	}
	mCoordinats[14][0] = 525;
	mCoordinats[14][1] = 100;
	mCoordinats[15][0] = 225;
	mCoordinats[15][1] = 575;
	mCoordinats[16][0] = 400;
	mCoordinats[16][1] = 575;
	mTipNumber = 0;
	mTipLabel = NULL;
	mBackStepsAmount = 1;
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
	if (mBackStepsAmount != 1) {
		mBackStepsAmount = 1;
		--mTipNumber;
	}
	if (mTipNumber == 0) {
		mTip = new QWidget();
		mTip->setGeometry(mCoordinats[0][0], mCoordinats[0][1], 210, 75);
		mTip->setWindowFlags(Qt::ToolTip);
		QGroupBox *box = new QGroupBox(mTip);
		box->setGeometry(0, 0, 210, 75);
		QPushButton *button = new QPushButton(mTip);
		button->setGeometry(90, 50, 40, 20);
		button->setText("OK");
		button->activateWindow();
		button->setFocus();
		mTipLabel = new QLabel(mTip);
		mTipLabel->move(9, 9);
		mTipLabel->setWordWrap(true);
		mTipLabel->setAlignment(Qt::AlignCenter);
		mTipLabel->setText(mTipText[mTipNumber]);
		mTip->activateWindow();
		mTip->raise();
	}
	else {
		mTip->hide();
		mTip->setGeometry(mCoordinats[mTipNumber][0], mCoordinats[mTipNumber][1], 210, 75);
		mTipLabel->setText(mTipText[mTipNumber]);
		if ((mTipNumber == 1) && (mBackButton == NULL)) {
			mBackButton = new QPushButton(mTip);
			mBackButton->setGeometry(30, 50, 50, 20);
			mBackButton->setText("Назад");
			mBackButton->activateWindow();
		}
		if (mBackButton->isHidden()) {
			mBackButton->show();
		}
		if (mTipNumber == 16) {
			mBackButton->hide();
		}
	}
	mTip->show();
	++mTipNumber;
	return mTip;
}

QWidget *TipShower::previousTip()
{
	int temp = mTipNumber - mBackStepsAmount - 1;
	if (temp < 0)
		return currentTip();
	mTip->hide();
	++mBackStepsAmount;
	mTip->setGeometry(mCoordinats[temp][0], mCoordinats[temp][1], 210, 75);
	mTipLabel->setText(mTipText[temp]);
	if (temp == 0) {
		mBackButton->hide();
	}
	mTip->show();
	return mTip;
}

void TipShower::hideTip()
{
	mTip->hide();
}

QWidget *TipShower::getTip()
{
	return this->mTip;
}

int TipShower::getTipNumber()
{
	return this->mTipNumber;
}

TipShower::~TipShower()
{
	delete mBackButton;
	delete mTipText;
	delete mTip;
	delete mInstance;
}

