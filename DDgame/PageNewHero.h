#ifndef PAGENEWHERO_H
#define PAGENEWHERO_H

#include <QObject>
#include <QVariant>

class PageNewHero : public QObject
{
    Q_OBJECT
public slots:
    void slotOnRaceSelected(QString selectedRace);
    void slotOnClassSelected(QString selectedClass);
signals:
    void signalSetRaces( QVariant races );
    void signalSetClasses( QVariant classes );
    void signalSetAbilities( QVariant abilities );
public:
    //Signals functions
    void setRaces( QVariant races );
    void setClasses(QVariant classes );
    void setAbilities(QVariant abilities );
public:
    PageNewHero();

    std::string GetSelectedRace() const;

private:
    std::string m_selectedRace;
};

#endif // PAGENEWHERO_H
