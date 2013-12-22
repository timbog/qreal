#pragma once

#include <QObject>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>

namespace tipShower {

/// Class which provides appearing of tips
class TipShower : public QObject
{
	Q_OBJECT

public:
	/// Singleton instance
	static TipShower *instance();

	~TipShower();

public slots:
	/// Tip whis is actual at the moment
	QWidget *currentTip();

	/// Previous tip
	QWidget *previousTip();

	/// Hide tip
	void hideTip();

	/// Returns tip
	QWidget *getTip();

	/// Returns tip number
	int getTipNumber();

private:
	/// Tip itself
	QWidget *mTip;

	static TipShower *mInstance;

	/// Array of texts of tips
	QString mTipText[20];

	/// Array of coordinats of tips
	int mCoordinats[20][2];

	/// Number of current tip
	int mTipNumber;

	/// Private constructor
	TipShower();

	/// Label whis is contained by tip
	QLabel *mTipLabel;

	/// Back button
	QPushButton *mBackButton;

	/// Amount of back button clicks
	int mBackStepsAmount;

};

}

