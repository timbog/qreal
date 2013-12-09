#pragma once

#include <QBrush>
#include <QPainter>

#include "../../../../qrgui/editorPluginInterface/elementImpl.h"
#include "../../../../qrgui/editorPluginInterface/elementRepoInterface.h"
#include "../../../../qrgui/editorPluginInterface/labelFactoryInterface.h"
#include "../../../../qrgui/editorPluginInterface/labelInterface.h"
#include "ports.h"

	class DragonActionNode : public qReal::ElementImpl
	{
	public:
		void init(qReal::LabelFactoryInterface &, QList<qReal::LabelInterface*> &) {}

		void init(QRectF &contents, PortFactoryInterface const &portFactory, QList<PortInterface *> &ports
							, qReal::LabelFactoryInterface &factory, QList<qReal::LabelInterface*> &titles
							, qReal::SdfRendererInterface *renderer, qReal::ElementRepoInterface *elementRepo)
		{
			mRenderer = renderer;
			mRenderer->load(QString(":/generated/shapes/DragonActionNodeClass.sdf"));
			mRenderer->setElementRepo(elementRepo);
			contents.setWidth(80);
			contents.setHeight(60);
			ports << portFactory.createPort(QLineF(0.9875, 0.166667, 0.9875, 0.833333), false, false, false, false, 80, 60, new NonTyped());
			ports << portFactory.createPort(QLineF(0.0125, 0.166667, 0.0125, 0.833333), false, false, false, false, 80, 60, new NonTyped());
			ports << portFactory.createPort(QLineF(0.125, 0.0166667, 0.875, 0.0166667), false, false, false, false, 80, 60, new NonTyped());
			ports << portFactory.createPort(QLineF(0.125, 0.983333, 0.875, 0.983333), false, false, false, false, 80, 60, new NonTyped());
			title_1 = factory.createLabel(1, 0, 0, "process", false, 0);
			title_1->setBackground(Qt::transparent);
			title_1->setScaling(false, false);
			title_1->setHard(false);
			title_1->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_1);
		}

		 qReal::ElementImpl *clone() { return NULL; }
		~DragonActionNode() {}

		void paint(QPainter *painter, QRectF &contents)
		{
			mRenderer->render(painter, contents);
		}

		Qt::PenStyle getPenStyle() const { return Qt::SolidLine; }

		int getPenWidth() const { return 0; }

		QColor getPenColor() const { return QColor(); }

		void drawStartArrow(QPainter *) const {}
		void drawEndArrow(QPainter *) const {}

		void updateData(qReal::ElementRepoInterface *repo) const
		{
			mRenderer->setElementRepo(repo);
			title_1->setTextFromRepo(repo->logicalProperty("process"));
		}

		bool isNode() const
		{
			return true;
		}

		bool isResizeable() const
		{
			return true;
		}

		bool isContainer() const
		{
			return false;
		}

		bool isSortingContainer() const
		{
			return false;
		}

		QVector<int> sizeOfForestalling() const
		{
			QVector<int> result;
			result << 0 << 0 << 0 << 0;
;
			return result;
		}

		int sizeOfChildrenForestalling() const
		{
			return 0;
		}

		bool hasMovableChildren() const
		{
			return true;
		}

		bool minimizesToChildren() const
		{
			return false;
		}

		bool maximizesChildren() const
		{
			return false;
		}

		bool isDividable() const
		{
			return false;
		}

		QStringList fromPortTypes() const
		{
			return QStringList("NonTyped");
		}

		QStringList toPortTypes() const
		{
			return QStringList("NonTyped");
		}

		enums::linkShape::LinkShape shapeType() const
		{
			return enums::linkShape::square;
		}

		bool isPort() const
		{
			return false;
		}

		bool hasPin() const
		{
			return false;
		}

		bool createChildrenFromMenu() const
		{
			return false;
		}

		QList<double> border() const
		{
			QList<double> list;
			list << 0 << 0 << 0 << 0;
			return list;
		}

		QStringList bonusContextMenuFields() const
		{
			return QStringList();
		}

	private:
		qReal::SdfRendererInterface *mRenderer;
		qReal::LabelInterface *title_1;
	};

	class DragonDiagramNode : public qReal::ElementImpl
	{
	public:
		void init(qReal::LabelFactoryInterface &, QList<qReal::LabelInterface*> &) {}

		void init(QRectF &contents, PortFactoryInterface const &portFactory, QList<PortInterface *> &ports
							, qReal::LabelFactoryInterface &factory, QList<qReal::LabelInterface*> &titles
							, qReal::SdfRendererInterface *renderer, qReal::ElementRepoInterface *elementRepo)
		{
			mRenderer = renderer;
			mRenderer->load(QString(":/generated/shapes/DragonDiagramNodeClass.sdf"));
			mRenderer->setElementRepo(elementRepo);
			contents.setWidth(200);
			contents.setHeight(200);
			ports << portFactory.createPort(QPointF(0, 0.5), false, false, 200, 200, new NonTyped());
			ports << portFactory.createPort(QPointF(0.5, 0), false, false, 200, 200, new NonTyped());
			ports << portFactory.createPort(QPointF(1, 0.5), false, false, 200, 200, new NonTyped());
			ports << portFactory.createPort(QPointF(0.5, 1), false, false, 200, 200, new NonTyped());
			title_1 = factory.createLabel(1, 0.2, 0.05, "name", false, 0);
			title_1->setBackground(Qt::transparent);
			title_1->setScaling(false, false);
			title_1->setHard(false);
			title_1->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_1);
		}

		 qReal::ElementImpl *clone() { return NULL; }
		~DragonDiagramNode() {}

		void paint(QPainter *painter, QRectF &contents)
		{
			mRenderer->render(painter, contents);
		}

		Qt::PenStyle getPenStyle() const { return Qt::SolidLine; }

		int getPenWidth() const { return 0; }

		QColor getPenColor() const { return QColor(); }

		void drawStartArrow(QPainter *) const {}
		void drawEndArrow(QPainter *) const {}

		void updateData(qReal::ElementRepoInterface *repo) const
		{
			mRenderer->setElementRepo(repo);
			title_1->setTextFromRepo(repo->name());
		}

		bool isNode() const
		{
			return true;
		}

		bool isResizeable() const
		{
			return true;
		}

		bool isContainer() const
		{
			return true;
		}

		bool isSortingContainer() const
		{
			return false;
		}

		QVector<int> sizeOfForestalling() const
		{
			QVector<int> result;
			result << 0 << 0 << 0 << 0;
;
			return result;
		}

		int sizeOfChildrenForestalling() const
		{
			return 0;
		}

		bool hasMovableChildren() const
		{
			return true;
		}

		bool minimizesToChildren() const
		{
			return false;
		}

		bool maximizesChildren() const
		{
			return false;
		}

		bool isDividable() const
		{
			return false;
		}

		QStringList fromPortTypes() const
		{
			return QStringList("NonTyped");
		}

		QStringList toPortTypes() const
		{
			return QStringList("NonTyped");
		}

		enums::linkShape::LinkShape shapeType() const
		{
			return enums::linkShape::square;
		}

		bool isPort() const
		{
			return false;
		}

		bool hasPin() const
		{
			return false;
		}

		bool createChildrenFromMenu() const
		{
			return true;
		}

		QList<double> border() const
		{
			QList<double> list;
			list << 0 << 0 << 0 << 0;
			return list;
		}

		QStringList bonusContextMenuFields() const
		{
			return QStringList();
		}

	private:
		qReal::SdfRendererInterface *mRenderer;
		qReal::LabelInterface *title_1;
	};

	class DragonFieldTitleNode : public qReal::ElementImpl
	{
	public:
		void init(qReal::LabelFactoryInterface &, QList<qReal::LabelInterface*> &) {}

		void init(QRectF &contents, PortFactoryInterface const &portFactory, QList<PortInterface *> &ports
							, qReal::LabelFactoryInterface &factory, QList<qReal::LabelInterface*> &titles
							, qReal::SdfRendererInterface *renderer, qReal::ElementRepoInterface *elementRepo)
		{
			mRenderer = renderer;
			mRenderer->load(QString(":/generated/shapes/DragonFieldTitleNodeClass.sdf"));
			mRenderer->setElementRepo(elementRepo);
			contents.setWidth(60);
			contents.setHeight(30);
			ports << portFactory.createPort(QPointF(0.5, 0), false, false, 60, 30, new NonTyped());
			ports << portFactory.createPort(QPointF(0.5, 1), false, false, 60, 30, new NonTyped());
			title_1 = factory.createLabel(1, 0, 0, "process", false, 0);
			title_1->setBackground(Qt::transparent);
			title_1->setScaling(false, false);
			title_1->setHard(false);
			title_1->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_1);
		}

		 qReal::ElementImpl *clone() { return NULL; }
		~DragonFieldTitleNode() {}

		void paint(QPainter *painter, QRectF &contents)
		{
			mRenderer->render(painter, contents);
		}

		Qt::PenStyle getPenStyle() const { return Qt::SolidLine; }

		int getPenWidth() const { return 0; }

		QColor getPenColor() const { return QColor(); }

		void drawStartArrow(QPainter *) const {}
		void drawEndArrow(QPainter *) const {}

		void updateData(qReal::ElementRepoInterface *repo) const
		{
			mRenderer->setElementRepo(repo);
			title_1->setTextFromRepo(repo->logicalProperty("process"));
		}

		bool isNode() const
		{
			return true;
		}

		bool isResizeable() const
		{
			return true;
		}

		bool isContainer() const
		{
			return false;
		}

		bool isSortingContainer() const
		{
			return false;
		}

		QVector<int> sizeOfForestalling() const
		{
			QVector<int> result;
			result << 0 << 0 << 0 << 0;
;
			return result;
		}

		int sizeOfChildrenForestalling() const
		{
			return 0;
		}

		bool hasMovableChildren() const
		{
			return true;
		}

		bool minimizesToChildren() const
		{
			return false;
		}

		bool maximizesChildren() const
		{
			return false;
		}

		bool isDividable() const
		{
			return false;
		}

		QStringList fromPortTypes() const
		{
			return QStringList("NonTyped");
		}

		QStringList toPortTypes() const
		{
			return QStringList("NonTyped");
		}

		enums::linkShape::LinkShape shapeType() const
		{
			return enums::linkShape::square;
		}

		bool isPort() const
		{
			return false;
		}

		bool hasPin() const
		{
			return false;
		}

		bool createChildrenFromMenu() const
		{
			return false;
		}

		QList<double> border() const
		{
			QList<double> list;
			list << 0 << 0 << 0 << 0;
			return list;
		}

		QStringList bonusContextMenuFields() const
		{
			return QStringList();
		}

	private:
		qReal::SdfRendererInterface *mRenderer;
		qReal::LabelInterface *title_1;
	};

	class DragonFlow : public qReal::ElementImpl {
	public:
		void init(QRectF &, PortFactoryInterface const &, QList<PortInterface *> &,
											qReal::LabelFactoryInterface &, QList<qReal::LabelInterface *> &,
											qReal::SdfRendererInterface *, qReal::ElementRepoInterface *) {}

		void init(qReal::LabelFactoryInterface &factory, QList<qReal::LabelInterface*> &titles)
		{
			title_1 = factory.createLabel(1, 0, 0, "type", false, 0);
			title_1->setBackground(Qt::white);
			title_1->setScaling(false, false);
			title_1->setHard(false);
			title_1->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_1);
		}

		virtual ~DragonFlow() {}

		qReal::ElementImpl *clone() { return NULL; }
		void paint(QPainter *, QRectF &){}
		bool isNode() const { return false; }
		bool isResizeable() const { return true; }
		bool isContainer() const { return false; }
		bool isDividable() const { return true; }
		bool isSortingContainer() const { return false; }
		QVector<int> sizeOfForestalling() const { return QVector<int>(4, 0); }
		int sizeOfChildrenForestalling() const { return 0; }
		bool hasMovableChildren() const { return false; }
		bool minimizesToChildren() const { return false; }
		bool maximizesChildren() const { return false; }
		QStringList fromPortTypes() const
		{
			QStringList result;
			result << "NonTyped";
			return result;
		}
		QStringList toPortTypes() const
		{
			QStringList result;
			result << "NonTyped";
			return result;
		}
		enums::linkShape::LinkShape shapeType() const
		{
			return enums::linkShape::square;
		}
		bool isPort() const { return false; }
		bool hasPin() const { return false; }
		bool createChildrenFromMenu() const { return false; }
		QList<double> border() const
		{
			QList<double> list;
			list << 0 << 0 << 0 << 0;
			return list;
		}
		int getPenWidth() const { return 1; }
		QColor getPenColor() const { return QColor(0,0,0); }
		Qt::PenStyle getPenStyle() const { return Qt::SolidLine; }
		QStringList bonusContextMenuFields() const
		{
			return QStringList();
		}

	protected:
		virtual void drawStartArrow(QPainter * painter) const
		{
			QBrush old = painter->brush();
			QBrush brush;
			brush.setStyle(Qt::SolidPattern);
			painter->setBrush(brush);
			painter->setBrush(old);
		}

		virtual void drawEndArrow(QPainter * painter) const
		{
			QBrush old = painter->brush();
			QBrush brush;
			brush.setStyle(Qt::SolidPattern);
			painter->setBrush(brush);
			static const QPointF points[] = {
				QPointF(-5,10),
				QPointF(0,0),
				QPointF(5,10)
			};
			painter->drawPolyline(points, 3);
			painter->setBrush(old);
		}

		void updateData(qReal::ElementRepoInterface *repo) const
		{
			title_1->setTextFromRepo(repo->logicalProperty("type"));
		}

	private:
		qReal::LabelInterface *title_1;
	};

