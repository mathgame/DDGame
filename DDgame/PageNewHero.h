#ifndef PAGENEWHERO_H
#define PAGENEWHERO_H

#include <QObject>
#include <QVariant>

class PageNewHero : public QObject
{
    Q_OBJECT
public slots:
    void slotOnRaceSelected(int index);
    void slotOnClassSelected(int index);


    void slotInfoSelected(QString selectedFieldName);

signals:
    void signalInfoSelect(QString selectedFieldInfo);

public:
    PageNewHero();

    std::string GetSelectedRace() const;
    std::string GetSelectedClass() const;

private:
    std::string m_selectedRace;
    std::string m_selectedClass;
};

#endif // PAGENEWHERO_H
