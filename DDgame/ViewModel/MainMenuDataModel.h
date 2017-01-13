#ifndef CMAINMENUDATAMODEL_H
#define CMAINMENUDATAMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include "MainMenuItem.h"

class CMainMenuDataModel : public QAbstractListModel
{
    Q_OBJECT

public:

    enum MenuItemRoles {
        TextRole = Qt::UserRole + 1,
        ValueRole,
        DescriptionRole,
        EnabledRole,
        ColorRole,
        SelectedRole,
    };

    CMainMenuDataModel(QObject *parent = 0);
    CMainMenuDataModel(const CMainMenuDataModel &obj);
    virtual ~CMainMenuDataModel();

public:
    virtual void append( CMainMenuItem* pMenuItem);
    virtual int rowCount(const QModelIndex & parent = QModelIndex()) const;

    bool empty() const;
    Q_INVOKABLE int size() const;

    Q_INVOKABLE QVariantMap get(int row);
    void update(int row);
    QHash<int, QByteArray> roleNames() const;
    QHash<int, QByteArray> makeRoleNames() const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

    void clear();
    CMainMenuItem* at(int iIndex);
    int GetLastSelectedIndex() const;
    void DeleteItems();

private:
    QList<CMainMenuItem *> m_lMenuItemsList;
};

#endif // CMAINMENUDATAMODEL_H
