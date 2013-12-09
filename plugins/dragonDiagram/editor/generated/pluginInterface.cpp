#include "pluginInterface.h"

#include "elements.h"


DragonDiagramMetamodelPlugin::DragonDiagramMetamodelPlugin()
{
	initPlugin();
}

void DragonDiagramMetamodelPlugin::initPlugin()
{
	initNameMap();
	initMouseGestureMap();
	initPropertyMap();
	initPropertyDefaultsMap();
	initDescriptionMap();
	initParentsMap();
	initPaletteGroupsMap();
	initPaletteGroupsDescriptionMap();
	initExplosionsMap();
}

void DragonDiagramMetamodelPlugin::initNameMap()
{
	mDiagramNameMap["DragonDiagram"] = QString::fromUtf8("Dragon Diagram");
	mDiagramNodeNameMap["DragonDiagram"] = "DragonDiagramNode";

	mElementsNameMap["DragonDiagram"]["DragonActionNode"] = QString::fromUtf8("Action Node");
	mElementsNameMap["DragonDiagram"]["DragonDiagramNode"] = QString::fromUtf8("Dragon Diagram");
	mElementsNameMap["DragonDiagram"]["DragonFieldTitleNode"] = QString::fromUtf8("Field Title Node");
	mElementsNameMap["DragonDiagram"]["DragonFlow"] = QString::fromUtf8("Control Flow");
}

void DragonDiagramMetamodelPlugin::initPaletteGroupsMap()
{
}

void DragonDiagramMetamodelPlugin::initPaletteGroupsDescriptionMap()
{
}

void DragonDiagramMetamodelPlugin::initMouseGestureMap()
{
	mElementMouseGesturesMap["DragonDiagram"]["DragonDiagramNode"] = "10, 0 : 90, 0 "
			": 90, 100 : 10, 100 : 0, 90 : 0, 10 : 100, 10 : 100, 90 : ";
}

void DragonDiagramMetamodelPlugin::initPropertyMap()
{
	mPropertyTypes["DragonDiagramNode"]["isView"] = "Bool";
	mPropertyTypes["DragonFlow"]["type"] = "Bool";
}

void DragonDiagramMetamodelPlugin::initPropertyDefaultsMap()
{
}

void DragonDiagramMetamodelPlugin::initDescriptionMap()
{
}

void DragonDiagramMetamodelPlugin::initParentsMap()
{
	mParentsMap["DragonDiagram"]["DragonDiagramNode"]
		<< qMakePair(QString("DragonDiagram"), QString("Diagram"))
	;
}

void DragonDiagramMetamodelPlugin::initExplosionsMap()
{
}

QStringList DragonDiagramMetamodelPlugin::diagrams() const
{
	return mDiagramNameMap.keys();
}

QStringList DragonDiagramMetamodelPlugin::diagramPaletteGroups(QString const &diagram) const
{
	return mPaletteGroupsMap[diagram].keys();
}

QStringList DragonDiagramMetamodelPlugin::diagramPaletteGroupList(QString const &diagram, QString const &group) const
{
	return mPaletteGroupsMap[diagram][group];
}

QString DragonDiagramMetamodelPlugin::diagramPaletteGroupDescription(QString const &diagram, QString const &group) const
{
	return mPaletteGroupsDescriptionMap[diagram][group];
}

QStringList DragonDiagramMetamodelPlugin::elements(QString const &diagram) const
{
	return mElementsNameMap[diagram].keys();
}

QStringList DragonDiagramMetamodelPlugin::getPropertiesWithDefaultValues(QString const &element) const
{
	return mPropertyDefault[element].keys();
}

QIcon DragonDiagramMetamodelPlugin::getIcon(qReal::SdfIconEngineV2Interface *engine) const
{
	return QIcon(engine);
}

QString DragonDiagramMetamodelPlugin::editorName() const
{
	 return "DragonDiagramMetamodel Editor";
}

QString DragonDiagramMetamodelPlugin::diagramName(QString const &diagram) const
{
	return mDiagramNameMap[diagram];
}

QString DragonDiagramMetamodelPlugin::diagramNodeName(QString const &diagram) const
{
	return mDiagramNodeNameMap[diagram];
}

QString DragonDiagramMetamodelPlugin::elementName(QString const &diagram, QString const &element) const
{
	return mElementsNameMap[diagram][element];
}

QString DragonDiagramMetamodelPlugin::elementDescription(QString const &diagram, QString const &element)const
{
	return mElementsDescriptionMap[diagram][element];
}

QString DragonDiagramMetamodelPlugin::propertyDescription(QString const &diagram, QString const &element, QString const &property) const
{
	return mPropertiesDescriptionMap[diagram][element][property];
}

QString DragonDiagramMetamodelPlugin::propertyDisplayedName(QString const &diagram, QString const &element, QString const &property) const
{
	return mPropertiesDisplayedNamesMap[diagram][element][property];
}

QString DragonDiagramMetamodelPlugin::elementMouseGesture(QString const &diagram, QString const &element) const
{
	return mElementMouseGesturesMap[diagram][element];
}

QList<qReal::EditorInterface::ExplosionData>DragonDiagramMetamodelPlugin::explosions(QString const &diagram, QString const &element) const 
{
	return mExplosionsMap[diagram][element];
}

qReal::ElementImpl* DragonDiagramMetamodelPlugin::getGraphicalObject(QString const &/*diagram*/, QString const &element) const
{
	if (element == "DragonActionNode") {
		return new DragonActionNode();
	}
	else if (element == "DragonDiagramNode") {
		return new DragonDiagramNode();
	}
	else if (element == "DragonFieldTitleNode") {
		return new DragonFieldTitleNode();
	}
	else if (element == "DragonFlow") {
		return new DragonFlow();
	}
	else {
		Q_ASSERT(!"Request for creation of an element with unknown name");
		return NULL;
	}
}

bool DragonDiagramMetamodelPlugin::isParentOf(QString const &parentDiagram, QString const &parentElement, QString const &childDiagram, QString const &childElement) const
{
	if (childDiagram == parentDiagram && childElement == parentElement)
		return true;
	if (mParentsMap[childDiagram][childElement].contains(qMakePair(parentDiagram, parentElement)))
		return true;
	typedef QPair<QString, QString> StringPair;
	foreach (StringPair const &pair, mParentsMap[childDiagram][childElement])
		if (isParentOf(parentDiagram, parentElement, pair.first, pair.second))
			return true;
	return false;
}
QList<QPair<QString, QString> > DragonDiagramMetamodelPlugin::getParentsOf(QString const &diagram, QString const &element) const
{
	return mParentsMap[diagram][element];
}
QStringList DragonDiagramMetamodelPlugin::getPropertyNames(QString const &/*diagram*/, QString const &element) const
{
	QStringList result;
	if (element == "DragonActionNode") {
		result  << "process";
	}
	else if (element == "DragonDiagramNode") {
		result  << "isView" << "language";
	}
	else if (element == "DragonFieldTitleNode") {
		result  << "process";
	}
	else if (element == "DragonFlow") {
		result  << "type" << "type_number";
	}
	return result;
}

QStringList DragonDiagramMetamodelPlugin::getPortTypes(QString const &/*diagram*/, QString const &element) const
{
	QStringList result;
	if (element == "DragonActionNode") {
		result << "NonTyped";
	}
	else if (element == "DragonDiagramNode") {
		result << "NonTyped";
	}
	else if (element == "DragonFieldTitleNode") {
		result << "NonTyped";
	}
	return result;
}

QStringList DragonDiagramMetamodelPlugin::getReferenceProperties(QString const &/*diagram*/, QString const &element) const
{
	QStringList result;
	if (element == "DragonActionNode") {
	}
	else if (element == "DragonDiagramNode") {
	}
	else if (element == "DragonFieldTitleNode") {
	}
	else if (element == "DragonFlow") {
	}
	return result;
}

QStringList DragonDiagramMetamodelPlugin::getTypesContainedBy(QString const &element) const
{
	QStringList result;
	if (element == "DragonDiagramNode") {
		result << "Action" ;
	}
	return result;
}

QList<QPair<QPair<QString,QString>,QPair<bool,QString> > > DragonDiagramMetamodelPlugin::getPossibleEdges(QString const &element) const
{
	QList<QPair<QPair<QString,QString>,QPair<bool,QString> > > result;
	if (element == "DragonFlow") {
		result << qMakePair(qMakePair(QString("ActionNode"),QString("ActionNode")),qMakePair(false,QString("DragonFlow")));
	}
	return result;
}

//(-1) means "edge", (+1) means "node"
int DragonDiagramMetamodelPlugin::isNodeOrEdge(QString const &element) const
{
	if (element == "DragonActionNode")
		return 1;
	else if (element == "DragonDiagramNode")
		return 1;
	else if (element == "DragonFieldTitleNode")
		return 1;
	else if (element == "DragonFlow")
		return -1;
	return 0;
}
QString DragonDiagramMetamodelPlugin::getGroupsXML() const 
{
	return QString::fromUtf8(" <groups>\n  <group name=\"atom1\" inNode=\"start\" outNode=\"end\">\n   <groupNode yPosition=\"0\" type=\"DragonActionNode\" name=\"start\" xPosition=\"0\"/>\n   <groupNode yPosition=\"100\" type=\"DragonActionNode\" name=\"end\" xPosition=\"0\"/>\n   <groupEdge to=\"end\" type=\"DragonFlow\" from=\"start\"/>\n  </group>\n  <group name=\"atom2\" inNode=\"all\" outNode=\"all\">\n   <groupNode yPosition=\"0\" type=\"DragonActionNode\" name=\"all\" xPosition=\"0\"/>\n  </group>\n </groups>\n");
}

QStringList DragonDiagramMetamodelPlugin::getEnumValues(QString name) const 
{
	QStringList result;
	if (name == "VisibilityKind")
		result << QString::fromUtf8("private") << QString::fromUtf8("protected") << QString::fromUtf8("public") << QString::fromUtf8("package");
	else if (name == "AggregationKind")
		result << QString::fromUtf8("none") << QString::fromUtf8("shared") << QString::fromUtf8("composite");
	else if (name == "Bool")
		result << QString::fromUtf8("false") << QString::fromUtf8("true");
	else if (name == "ParameterDirectionKind")
		result << QString::fromUtf8("in") << QString::fromUtf8("inout") << QString::fromUtf8("out") << QString::fromUtf8("return");
	return result;
}

QString DragonDiagramMetamodelPlugin::getPropertyType(QString const &element, QString const &property) const
{
	return mPropertyTypes[element][property];
}

QString DragonDiagramMetamodelPlugin::getPropertyDefaultValue(QString const &element, QString const &property) const
{
	return mPropertyDefault[element][property];
}

QList<qReal::ListenerInterface*> DragonDiagramMetamodelPlugin::listeners() const
{
	QList<qReal::ListenerInterface*> result;
	return result;
}
