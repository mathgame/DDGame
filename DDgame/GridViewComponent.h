#ifndef GRIDVIEWCOMPONENT_H
#define GRIDVIEWCOMPONENT_H
#include <QObject>
#include <QAbstractItemModel>

//class GridViewComponent : public QAbstractItemModel
//{
//    Q_OBJECT
//public:
//    explicit GridViewComponent(const QString &data, QObject *parent = 0);
//    GridViewComponent();
//    ~GridViewComponent();

//    QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
//    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
//    QModelIndex index(int row, int column,
//                      const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
//    QModelIndex parent(const QModelIndex &index) const Q_DECL_OVERRIDE;

//private:
//    void setupModelData(const QStringList &lines, GridViewComponent *parent);

//    GridViewComponent *rootItem;
//};

#endif // GRIDVIEWCOMPONENT_H
