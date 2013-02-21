#include "filterobject.h"
#include <QtCore/QDebug>
#include <QEvent>

FilterObject::FilterObject(QObject *parent) :
	QObject(parent)
{
}

bool FilterObject::eventFilter(QObject *object, QEvent *event)
{
	if (event->type() == QEvent::MouseButtonPress)
		qDebug() << "eventFilter" << object;
	return false;
}
