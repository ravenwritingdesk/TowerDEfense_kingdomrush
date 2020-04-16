#ifndef CLOAKENEMY_H
#define CLOAKENEMY_H

#include <QObject>
#include <QPoint>
#include <QSize>
#include <QPixmap>
#include "enemy.h"

class WayPoint;
class QPainter;
class MainWindow;
class PurpleTower;
class RedTower;
class BlueTower;
class Enemy;
//隐身敌人
class CloakEnemy : public Enemy
{
    Q_OBJECT
public:
    CloakEnemy(WayPoint *startWayPoint, MainWindow *game, const QPixmap &sprite = QPixmap(":/image/dragon.png"));
    ~CloakEnemy();

    void draw(QPainter *painter) const;
    void move();
    void getDamage(int damage);
    void getRemoved();
    void setCloak(bool state);
    void getAttacked(PurpleTower *attacker);
    void getAttacked(BlueTower *attacker);
    void getAttacked(RedTower *attacker);

    void gotLostSight(PurpleTower *attacker);
    void gotLostSight(BlueTower *attacker);
    void gotLostSight(RedTower *attacker);
    QPoint pos() const;

public slots:
    void doActivate();

private:
    bool			m_active;
    bool			m_cloak;
    int				m_maxHp;
    int				m_currentHp;
    qreal			m_walkingSpeed;
    qreal			m_rotationSprite;
    QPoint			m_pos;
    WayPoint *		m_destinationWayPoint;
    MainWindow *	m_game;
    QList<PurpleTower *>	m_PurpleTowerattackedTowersList;
    QList<BlueTower *>	m_BlueTowerattackedTowersList;
    QList<RedTower *>	m_RedTowerattackedTowersList;
    const QPixmap	m_sprite;
    static const QSize ms_fixedSize;
};

#endif // CLOAKENEMY_H
