#ifndef SPEEDENEMY_H
#define SPEEDENEMY_H
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
//速度敌人
class SpeedEnemy : public Enemy
{
    Q_OBJECT
public:
    explicit SpeedEnemy(WayPoint *startWayPoint, MainWindow *game, const QPixmap &sprite = QPixmap(":/image/guard.png"));
    ~SpeedEnemy();
    void draw(QPainter *painter) const;
    void move();
    void getDamage(int damage);//血量
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
    int				m_maxHp;//最大血量
    int				m_currentHp;//当前血量
    qreal			m_walkingSpeed;//移动速度
    qreal			m_rotationSprite;
    QPoint			m_pos;//位置
    WayPoint *		m_destinationWayPoint;//目的地路点
    MainWindow *	m_game;
    QList<PurpleTower *>  m_PurpleTowerattackedTowersList;
    QList<BlueTower *>	  m_BlueTowerattackedTowersList;
    QList<RedTower *>	  m_RedTowerattackedTowersList;
    const QPixmap	m_sprite;
    static const QSize ms_fixedSize;
};

#endif // SPEEDENEMY_H
