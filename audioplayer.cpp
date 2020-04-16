#include "audioplayer.h"
#include <QDir>
#include <QMediaPlayer>
#include <QMediaPlaylist>

// 使用绝对路径可以完成目标,
static const QString s_curDir = "/Users/wangchuwen/Desktop/TowerDefenseQt-1/TowerDefenseQt";

AudioPlayer::AudioPlayer(QObject *parent)
	: QObject(parent)
	, m_backgroundMusic(NULL)
{
	// 创建一直播放的背景音乐
    QUrl backgroundMusicUrl = QUrl::fromLocalFile(s_curDir + "/music/hello.mp3");
	if (QFile::exists(backgroundMusicUrl.toLocalFile()))
	{
		m_backgroundMusic = new QMediaPlayer(this);
		QMediaPlaylist *backgroundMusicList = new QMediaPlaylist();

		QMediaContent media(backgroundMusicUrl);
		backgroundMusicList->addMedia(media);
		backgroundMusicList->setCurrentIndex(0);
		// 设置背景音乐循环播放
		backgroundMusicList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
		m_backgroundMusic->setPlaylist(backgroundMusicList);
	}
}

void AudioPlayer::startBGM()
{
	if (m_backgroundMusic)
		m_backgroundMusic->play();
}

void AudioPlayer::playSound(SoundType soundType)
{
	static const QUrl mediasUrls[] =
	{
        QUrl::fromLocalFile(s_curDir + "/music/3.mp3"),
        QUrl::fromLocalFile(s_curDir + "/music/1.wav"),
        QUrl::fromLocalFile(s_curDir + "/music/4.mp3"),
        QUrl::fromLocalFile(s_curDir + "/music/2.wav")
	};
	static QMediaPlayer player;

	if (QFile::exists(mediasUrls[soundType].toLocalFile()))
	{
		player.setMedia(mediasUrls[soundType]);
		player.play();
	}
}
