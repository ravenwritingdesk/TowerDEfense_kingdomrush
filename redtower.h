#ifndef REDTOWER_H
#define REDTOWER_H
#include <QPoint>
#include <QSize>
#include <QPixmap>
#include <QObject>
#include "tower.h"

class QPainter;
class Enemy;
class MainWindow;
class QTimer;
class Tower;

class RedTower : public Tower
{
    Q_OBJECT
public:
     explicit RedTower(QPoint pos, MainWindow *game, const QPixmap &sprite = QPixmap(":/image/arrowtower.png"));
     ~ RedTower();

    void draw(QPainter *painter) const;
    void checkEnemyInRange();
    void targetKilled();
    void attackEnemy();
    void chooseEnemyForAttack(Enemy *enemy);
    void removeBullet();
    void damageEnemy();
    void lostSightOfEnemy();

private slots:
    void shootWeapon();

private:
    bool			m_attacking;
    int				m_attackRange;	// 代表塔可以攻击到敌人的距离
    int				m_damage;		// 代表攻击敌人时造成的伤害
    int				m_fireRate;		// 代表再次攻击敌人的时间间隔
    qreal			m_rotationSprite;

    Enemy *			m_chooseEnemy;
    MainWindow *	m_game;
    QTimer *		m_fireRateTimer;

    const QPoint	m_pos;
    const QPixmap	m_sprite;

    static const QSize ms_fixedSize;
};
#endif // REDTOWER_H
