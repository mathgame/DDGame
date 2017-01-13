#ifndef CMAINMENUITEM_H
#define CMAINMENUITEM_H

#include <QObject>
#include <QString>
#include <QMetaType>

class CMainMenuItem : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString sMenuText READ GetMenuText WRITE SetMenuText NOTIFY signalMenuTextChanged)
    Q_PROPERTY(int iValue READ GetValue WRITE SetValue NOTIFY signalValueChanged)
    Q_PROPERTY(QString sDescription READ GetDescriptionText WRITE SetDescriptionText NOTIFY signalDescriptionChanged)
    Q_PROPERTY(bool bEnabled READ GetEnabled WRITE SetEnabled NOTIFY signalEnabledChanged)
    Q_PROPERTY(QString sColor READ GetColor WRITE SetColor NOTIFY signalColorChanged)
    Q_PROPERTY(bool bSelected READ GetSelected WRITE SetSelected NOTIFY signalSelectedChanged)

public:
    CMainMenuItem(QObject *parent=0);
    CMainMenuItem(const CMainMenuItem &other);
    ~CMainMenuItem();

public:

    void SetMenuText(const QString &sMenuText);
    void SetValue(int iValue);
    void SetDescriptionText(const QString &sDescriptionText);
    void SetEnabled(bool value);
    void SetColor(const QString& sColor);
    void SetSelected(bool value);

    QString GetMenuText() const;
    int GetValue() const;
    QString GetDescriptionText() const;
    bool GetEnabled() const;
    QString GetColor() const;
    bool GetSelected() const;

signals:
    void signalMenuTextChanged();
    void signalValueChanged();
    void signalDescriptionChanged();
    void signalEnabledChanged();
    void signalColorChanged();
    void signalSelectedChanged();
private:
    QString m_sMenuText;
    int m_iValue;
    QString m_sDescription;
    bool m_bEnabled;
    QString m_sColor;
    bool m_bSelected;
};

Q_DECLARE_METATYPE(CMainMenuItem)

#endif // CMAINMENUITEM_H
