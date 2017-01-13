#include "MainMenuDataModel.h"

CMainMenuDataModel::CMainMenuDataModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

CMainMenuDataModel::CMainMenuDataModel(const CMainMenuDataModel &obj)
{
}

CMainMenuDataModel::~CMainMenuDataModel()
{
    DeleteItems();
}

QHash<int, QByteArray> CMainMenuDataModel::roleNames() const
{
    static const QHash<int, QByteArray> roleNames = makeRoleNames();
    return roleNames;
}

QHash<int, QByteArray> CMainMenuDataModel::makeRoleNames() const
{
    QHash<int, QByteArray> roleNames;
    roleNames[TextRole] = "sMenuText";
    roleNames[ValueRole] = "iValue";
    roleNames[DescriptionRole] = "sDescription";
    roleNames[EnabledRole] = "bEnabled";
    roleNames[ColorRole] = "sColor";
    roleNames[SelectedRole] = "bSelected";
    return roleNames;
}

void CMainMenuDataModel::append(CMainMenuItem* pMenuItem)
{
    beginInsertRows(QModelIndex(),rowCount(),rowCount());
    m_lMenuItemsList.append(pMenuItem);
    endInsertRows();
    emit dataChanged(this->index(rowCount() - 1), this->index(rowCount() - 1));
}

void CMainMenuDataModel::clear()
{
    int cnt = rowCount();
    beginRemoveRows(QModelIndex(), 0,rowCount());
    DeleteItems();
    m_lMenuItemsList.clear();
    endRemoveRows();

    emit dataChanged(this->index(0), this->index(cnt));
}

void CMainMenuDataModel::DeleteItems()
{
    QList<CMainMenuItem*>::iterator itr = m_lMenuItemsList.begin();
    while (itr != m_lMenuItemsList.end()) {
        CMainMenuItem *pItem = *itr;
        itr = m_lMenuItemsList.erase(itr);
        if(pItem) {
            delete pItem;
            pItem = NULL;
        }
    }
}

CMainMenuItem* CMainMenuDataModel::at(int iIndex)
{
    return m_lMenuItemsList.at(iIndex);
}

int CMainMenuDataModel::rowCount(const QModelIndex &parent) const
{
    return m_lMenuItemsList.size();
}

QVariant CMainMenuDataModel::data(const QModelIndex &index, int role) const
{
    CMainMenuItem *itemData = m_lMenuItemsList.at(index.row());
    if (role == TextRole) return itemData->GetMenuText();
    if (role == ValueRole) return itemData->GetValue();
    if (role == DescriptionRole) return itemData->GetDescriptionText();
    if (role == EnabledRole) return itemData->GetEnabled();
    if (role == ColorRole) return itemData->GetColor();

    return QVariant();
}

QVariantMap CMainMenuDataModel::get(int row)
{
    QHash<int,QByteArray> names = roleNames();
    QHashIterator<int, QByteArray> i(names);
    QVariantMap res;
    while (i.hasNext()) {
        i.next();
        QModelIndex idx = index(row, 0);
        QVariant data = idx.data(i.key());
        res[i.value()] = data;
    }

    QModelIndex id = createIndex(row,0);

    emit dataChanged(id, id);

    return res;
}

void CMainMenuDataModel::update(int row)
{
    QModelIndex id = createIndex(row, 0);
    emit dataChanged(id, id);
}

bool CMainMenuDataModel::empty() const
{
    return m_lMenuItemsList.empty();
}

int CMainMenuDataModel::size() const
{
    return m_lMenuItemsList.size();
}
