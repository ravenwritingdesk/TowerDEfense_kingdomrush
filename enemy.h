#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QPoint>
#include <QSize>
#include <QPixmap>

class WayPoint;
class QPainter;
class MainWindow;
class Tower;
class PurpleTower;
class RedTower;
class BlueTower;

class Enemy : public QObject
{
	Q_OBJECT
public:
    Enemy(WayPoint *startWayPoint, MainWindow *game, const QPixmap &sprite = QPixmap(":/image/dragon1.png"));
	~Enemy();

	void draw(QPainter *painter) const;
	void move();
	void getDamage(int damage);
	void getRemoved();
	void getAttacked(Tower *attacker);
	void gotLostSight(Tower *attacker);
    virtual void getAttacked(PurpleTower *attacker);
    virtual void getAttacked(BlueTower *attacker);
    virtual void getAttacked(RedTower *attacker);
    virtual void gotLostSight(PurpleTower *attacker);
    virtual void gotLostSight(BlueTower *attacker);
    virtual void gotLostSight(RedTower *attacker);
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
	QList<Tower *>	m_attackedTowersList;
    QList<PurpleTower *>	m_PurpleTowerattackedTowersList;
    QList<BlueTower *>	m_BlueTowerattackedTowersList;
    QList<RedTower *>	m_RedTowerattackedTowersList;

	const QPixmap	m_sprite;
	static const QSize ms_fixedSize;
};

#endif // ENEMY_H
