#include "displayview.h"

DisplayView::DisplayView() :WidgetBase ()
{
    m_topPushBut = new QPushButton ();
    m_timer = new QTimer();
}

QWidget *DisplayView::createDWidget()
{

    m_centralLayout->setContentsMargins(0, 10, 0, 0);

    QImage *img = new QImage;
    img->load(":/images/001.png");
    m_pictureLabel->setPixmap(QPixmap::fromImage(*img));
    m_pictureLabel->setScaledContents(true);

    m_centralLayout->addWidget(m_pictureLabel, 0, Qt::AlignCenter);
    m_centralLayout->addSpacing(20);

    m_font->setPointSize(25);
    m_wordLabel = new QLabel();
    m_wordLabel->setMinimumSize(300, 50);
    m_wordLabel->setFont(*m_font);
    m_wordLabel->setAlignment(Qt::AlignHCenter);

    m_centralLayout->addWidget(m_wordLabel, 0, Qt::AlignCenter);
    m_centralLayout->addWidget(createDPushButton(),0, Qt::AlignCenter);
    return  wrapWidgetLayout(m_centralLayout);
}

QWidget *DisplayView::createDPushButton()
{

    m_bottPushBut->setText(QObject::tr("返回"));//operator BT
    m_topPushBut->setText(QObject::tr("复制"));//operator BT
    auto desktopAction = createActions({m_topPushBut, m_bottPushBut});
    m_pushBuLayout->addWidget(desktopAction);
    return wrapPushBottLayout(m_pushBuLayout);

}




