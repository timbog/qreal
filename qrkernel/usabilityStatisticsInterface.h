#pragma once

#include <QtCore/QString>
#include <QtCore/QVariant>

namespace qReal {
class UsabilityStatisticsInterface {

public:
	virtual ~UsabilityStatisticsInterface() {}

	virtual void reportSettingsChanges(QString const &name, QVariant const &oldValue, QVariant const &newValue) = 0;
};
}
