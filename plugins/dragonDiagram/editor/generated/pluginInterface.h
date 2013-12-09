#pragma once

#include <QtCore/QStringList>
#include <QtCore/QMap>
#include <QtGui/QIcon>
#include <QPair>
#include "../../../../qrgui/editorPluginInterface/editorInterface.h"

class DragonDiagramMetamodelPlugin : public QObject, public qReal::EditorInterface
{
	Q_OBJECT
	Q_INTERFACES(qReal::EditorInterface)
	Q_PLUGIN_METADATA(IID "DragonDiagramMetamodel")

public:

	DragonDiagramMetamodelPlugin();

	virtual void initPlugin();
	virtual void initMouseGestureMap();
	virtual void initNameMap();
	virtual void initPropertyMap();
	virtual void initPropertyDefaultsMap();
	virtual void initDescriptionMap();
	virtual void initParentsMap();
	virtual void initPaletteGroupsMap();
	virtual void initPaletteGroupsDescriptionMap();
	virtual void initExplosionsMap();

	virtual QString id() const { return "DragonDiagramMetamodel"; }

	virtual QStringList diagrams() const;
	virtual QStringList elements(QString const &diagram) const;
	virtual QStringList getPropertiesWithDefaultValues(QString const &element) const;

	virtual QStringList getTypesContainedBy(QString const &element) const;
	virtual QList<QPair<QPair<QString,QString>,QPair<bool,QString> > > getPossibleEdges(QString const &element) const;
	virtual QList<qReal::EditorInterface::ExplosionData> explosions(QString const &diagram, QString const &element) const;

	virtual int isNodeOrEdge(QString const &element) const; 

	virtual QIcon getIcon(qReal::SdfIconEngineV2Interface *engine) const;
	virtual qReal::ElementImpl* getGraphicalObject(QString const &diagram, QString const &element) const;
	virtual QString getPropertyType(QString const &element, QString const &property) const;
	virtual QString getPropertyDefaultValue(QString const &element, QString const &property) const;
	virtual QStringList getPropertyNames(QString const &diagram, QString const &element) const;
	virtual QStringList getPortTypes(QString const &diagram, QString const &element) const;
	virtual QStringList getReferenceProperties(QString const &diagram, QString const &element) const;
	virtual QStringList getEnumValues(QString name) const;
	virtual QString getGroupsXML() const;
	virtual QList<QPair<QString, QString> > getParentsOf(QString const &diagram, QString const &element) const;

	virtual QString editorName() const;
	virtual QString diagramName(QString const &diagram) const;
	virtual QString diagramNodeName(QString const &diagram) const;
	virtual QString elementName(QString const &diagram, QString const &element) const;
	virtual QString elementDescription(QString const &diagram, QString const &element) const;
	virtual QString propertyDescription(QString const &diagram, QString const &element, QString const &property) const;
	virtual QString propertyDisplayedName(QString const &diagram, QString const &element, QString const &property) const;
	virtual QString elementMouseGesture(QString const &digram, QString const &element) const;

	virtual QList<qReal::ListenerInterface*> listeners() const;

	virtual bool isParentOf(QString const &parentDiagram, QString const &parentElement, QString const &childDiagram, QString const &childElement) const;

	virtual QStringList diagramPaletteGroups(QString const &diagram) const;
	virtual QStringList diagramPaletteGroupList(QString const &diagram, QString const &group) const;
	virtual QString diagramPaletteGroupDescription(QString const &diagram, QString const &group) const;

private:
	QMap<QString, QIcon> mIconMap;
	QMap<QString, QString> mDiagramNameMap;
	QMap<QString, QString> mDiagramNodeNameMap;
	QMap<QString, QMap<QString, QString> > mPropertyTypes;
	QMap<QString, QMap<QString, QString> > mPropertyDefault;
	QMap<QString, QMap<QString, QString> > mElementsNameMap;
	QMap<QString, QMap<QString, QString> > mElementsDescriptionMap;
	QMap<QString, QMap<QString, QMap<QString, QString> > > mPropertiesDescriptionMap;
	QMap<QString, QMap<QString, QMap<QString, QString> > > mPropertiesDisplayedNamesMap;
	QMap<QString, QMap<QString, QString> > mElementMouseGesturesMap;
	QMap<QString, QMap<QString, QList<QPair<QString, QString> > > > mParentsMap;  // Maps diagram and element to a list of diagram-element pairs of parents (generalization relation).
	QMap<QString, QMap<QString, QStringList > > mPaletteGroupsMap;  // Maps element`s lists of all palette groups.
	QMap<QString, QMap<QString, QString > > mPaletteGroupsDescriptionMap; 
	QMap<QString, QMap<QString, QList<qReal::EditorInterface::ExplosionData> > > mExplosionsMap;
};

