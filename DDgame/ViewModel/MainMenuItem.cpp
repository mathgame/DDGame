#include "MainMenuItem.h"

CMainMenuItem::CMainMenuItem(QObject *parent)
    : QObject(parent)
    , m_sMenuText("")
    , m_iValue(0)
    , m_sDescription("")
    , m_bEnabled(false)
    , m_sColor("white")
{
}

CMainMenuItem::CMainMenuItem(const CMainMenuItem &other)
{
    m_sMenuText = other.m_sMenuText;
}

CMainMenuItem::~CMainMenuItem()
{
}

void CMainMenuItem::SetMenuText(const QString &sMenuText)
{
    m_sMenuText = sMenuText;
    emit signalMenuTextChanged();
}

QString CMainMenuItem::GetMenuText() const
{
    return m_sMenuText;
}

void CMainMenuItem::SetValue(int iValue)
{
    m_iValue = iValue;
    emit signalValueChanged();
}

int CMainMenuItem::GetValue() const
{
    return m_iValue;
}

void CMainMenuItem::SetDescriptionText(const QString &sDescriptionText)
{
    m_sDescription = sDescriptionText;
    emit signalDescriptionChanged();
}

QString CMainMenuItem::GetDescriptionText() const
{
    return m_sDescription;
}

void CMainMenuItem::SetEnabled(bool value)
{
    m_bEnabled = value;
    emit signalEnabledChanged();
}

bool CMainMenuItem::GetEnabled() const
{
    return m_bEnabled;
}

void CMainMenuItem::SetColor(const QString &sColor)
{
    m_sColor = sColor;
    emit signalColorChanged();
}

QString CMainMenuItem::GetColor() const
{
    return m_sColor;
}
