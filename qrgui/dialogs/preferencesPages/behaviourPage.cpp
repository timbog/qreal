#include "../../../qrkernel/settingsManager.h"
#include "behaviourPage.h"
#include "ui_behaviourPage.h"

using namespace qReal;

PreferencesBehaviourPage::PreferencesBehaviourPage(QWidget *parent)
		: PreferencesPage(parent)
		, mUi(new Ui::PreferencesBehaviourPage)
{
	mIcon = QIcon(":/icons/preferences/behaviour.png");
	mUi->setupUi(this);
	mFilterObject = new FilterObject();

	connect(mUi->autoSaveCheckBox, SIGNAL(clicked(bool)), this, SLOT(showAutoSaveBox(bool)));
	connect(mUi->collectArgonomicalValuesCheckBox, SIGNAL(clicked(bool)), mFilterObject, SLOT(setStatusCollectUsabilityStatistics(bool)));

	mUi->warningWindowBox->setChecked(SettingsManager::value("warningWindow").toBool());
	mUi->arrangeLinksCheckBox->setChecked(SettingsManager::value("arrangeLinks").toBool());
	mUi->paletteTabCheckBox->setChecked(SettingsManager::value("PaletteTabSwitching").toBool());
	mUi->diagramCreateCheckBox->setChecked(SettingsManager::value("diagramCreateSuggestion").toBool());
	mUi->autoSaveCheckBox->setChecked(SettingsManager::value("Autosave").toBool());
	mUi->collectArgonomicalValuesCheckBox->setChecked(SettingsManager::value("collectArgonomicalValues").toBool());
	mUi->autoSaveSpinBox->setValue(SettingsManager::value("AutosaveInterval").toInt());
	mUi->gestureDelaySpinBox->setValue(SettingsManager::value("gestureDelay").toInt());
	mUi->usabilityModeCheckBox->setChecked(mUsabilityTestingMode = SettingsManager::value("usabilityTestingMode").toBool());

	showAutoSaveBox(mUi->autoSaveCheckBox->isChecked());
	mFilterObject->setStatusCollectUsabilityStatistics(mUi->collectArgonomicalValuesCheckBox->isChecked());
}

PreferencesBehaviourPage::~PreferencesBehaviourPage()
{
	delete mUi;
}

void PreferencesBehaviourPage::changeEvent(QEvent *e)
{
	switch (e->type()) {
	case QEvent::LanguageChange:
		mUi->retranslateUi(this);
		break;
	default:
		break;
	}
}

void PreferencesBehaviourPage::save()
{
	SettingsManager::setValue("diagramCreateSuggestion", mUi->diagramCreateCheckBox->isChecked());
	SettingsManager::setValue("PaletteTabSwitching", mUi->paletteTabCheckBox->isChecked());
	SettingsManager::setValue("arrangeLinks", mUi->arrangeLinksCheckBox->isChecked());
	SettingsManager::setValue("warningWindow", mUi->warningWindowBox->isChecked());
	SettingsManager::setValue("Autosave", mUi->autoSaveCheckBox->isChecked());
	SettingsManager::setValue("AutosaveInterval", mUi->autoSaveSpinBox->value());
	SettingsManager::setValue("gestureDelay", mUi->gestureDelaySpinBox->value());

	bool usabilityTestingMode = mUi->usabilityModeCheckBox->isChecked();
	SettingsManager::setValue("usabilityTestingMode", usabilityTestingMode);
	SettingsManager::setValue("collectArgonomicalValues", mUi->collectArgonomicalValuesCheckBox->isChecked() || usabilityTestingMode);
	if (mUsabilityTestingMode != usabilityTestingMode) {
		if (usabilityTestingMode)
			mUi->collectArgonomicalValuesCheckBox->setChecked(true);
		emit usabilityTestingModeChanged(mUsabilityTestingMode = usabilityTestingMode);
	}
}

void PreferencesBehaviourPage::showAutoSaveBox(bool show)
{
	mUi->autoSaveSpinBox->setVisible(show);
	mUi->autoSaveLabel->setVisible(show);
}
