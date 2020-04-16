#ifndef ARMORENEMY_H
#define ARMORENEMY_H

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
//护甲敌人
class ArmorEnemy : public Enemy
{
    Q_OBJECT
public:
    explicit ArmorEnemy(WayPoint *startWayPoint, MainWindow *game, const QPixmap &sprite = QPixmap(":/image/wizard.png"));
    ~ArmorEnemy();

    void draw(QPainter *painter) const;
    void move();
    void getDamage(int damage);
    void getRemoved();
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

#endif // ARMORENEMY_H
