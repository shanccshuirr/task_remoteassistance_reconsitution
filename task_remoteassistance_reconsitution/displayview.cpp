#include "displayview.h"

DisplayView::DisplayView() :WidgetBase ()
{
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
    QString pushWord = "复制";
    m_centralLayout->addWidget(createDPushButton(pushWord),0, Qt::AlignCenter);
    return  wrapWidgetLayout(m_centralLayout);
}



