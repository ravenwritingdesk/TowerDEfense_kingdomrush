#include "bullet.h"
#include "enemy.h"
#include "mainwindow.h"
#include <QPainter>
#include <QPropertyAnimation>
#include <QMovie>
#include <QLabel>

const QSize Bullet::ms_fixedSize(40, 200);

Bullet::Bullet(QPoint startPos, QPoint targetPoint, int damage, Enemy *target,
               MainWindow *game, const QPixmap &sprite/* = QPixmap(":/image/bu.png")*/)
	: m_startPos(startPos)
	, m_targetPos(targetPoint)
	, m_sprite(sprite)
	, m_currentPos(startPos)
	, m_target(target)
	, m_game(game)
	, m_damage(damage)
{
}

void Bullet::draw(QPainter *painter) const
{
	painter->drawPixmap(m_currentPos, m_sprite);
}

void Bullet::move()
{
	// 100毫秒内击中敌人
    static const int duration = 200;
	QPropertyAnimation *animation = new QPropertyAnimation(this, "m_currentPos");
	animation->setDuration(duration);
	animation->setStartValue(m_startPos);
	animation->setEndValue(m_targetPos);
	connect(animation, SIGNAL(finished()), this, SLOT(hitTarget()));

	animation->start();
}

void Bullet::hitTarget()
{
	// 可能多个炮弹击中敌人,而其中一个将其消灭,导致敌人delete
	// 后续炮弹再攻击到的敌人就是无效内存区域
	// 因此先判断下敌人是否还有效
	if (m_game->enemyList().indexOf(m_target) != -1)
        m_target->getDamage(m_damage);{
      /*  QLabel *label;

        QMovie *movie = new QMovie(":/image/pheonix.gif");

        label->setMovie(movie);

        movie->start();*/
	m_game->removedBullet(this);
}
}

void Bullet::setCurrentPos(QPoint pos)
{
	m_currentPos = pos;
}

QPoint Bullet::currentPos() const
{
	return m_currentPos;
}
