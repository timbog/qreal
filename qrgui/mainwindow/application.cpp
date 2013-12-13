#include "application.h"
#include "tipShower.h"
/*Application::Application(QObject *parent) :
	QApplication(parent)
{
}*/
Application::Application(int &argc, char **argv)
		: QApplication(argc, argv)
{
}
bool Application::notify(QObject * receiver, QEvent * event)
{
	if (event->type() == QEvent::MouseButtonPress)
	{
		TipShower::instance()->currentTip();
	}
	return QApplication::notify(receiver, event);
}
