#include "application.h"

#include <qrkernel/settingsManager.h>
#include "tipShower.h"

using namespace application;
using namespace qReal;
using namespace tipShower;

Application::Application(int &argc, char **argv)
		: QApplication(argc, argv)
{
}

bool Application::notify(QObject * receiver, QEvent * event)
{
	if (TipShower::instance()->getTipNumber() > 16) {
		if (SettingsManager::value("firstLaunch").toBool())
			SettingsManager::instance()->setValue("firstLaunch", false);
		if (event->type() == QEvent::MouseButtonPress) {
			TipShower::instance()->hideTip();
		}
		return QApplication::notify(receiver, event);
	}
	if (SettingsManager::value("firstLaunch").toBool()) {
		if ((event->type() == QEvent::MouseButtonRelease) && (!receiver->isWidgetType())) {
			if ((this->overrideCursor()->pos().x() >= TipShower::instance()->getTip()->pos().x() + 90) &&
					(this->overrideCursor()->pos().y() >= TipShower::instance()->getTip()->pos().y() + 50) &&
					(this->overrideCursor()->pos().x() <= TipShower::instance()->getTip()->pos().x() + 130 ) &&
					(this->overrideCursor()->pos().y() <= TipShower::instance()->getTip()->pos().y() + 70)) {
				TipShower::instance()->hideTip();
				return QApplication::notify(receiver, event);
			}
			if ((this->overrideCursor()->pos().x() >= TipShower::instance()->getTip()->pos().x() + 30) &&
					(this->overrideCursor()->pos().y() >= TipShower::instance()->getTip()->pos().y() + 50) &&
					(this->overrideCursor()->pos().x() <= TipShower::instance()->getTip()->pos().x() + 80 ) &&
					(this->overrideCursor()->pos().y() <= TipShower::instance()->getTip()->pos().y() + 70) &&
					(TipShower::instance()->getTipNumber() >= 1) && (TipShower::instance()->getTipNumber() < 16)) {
				TipShower::instance()->previousTip();
			}
			else
				TipShower::instance()->currentTip();
		}
	}
	return QApplication::notify(receiver, event);
}
