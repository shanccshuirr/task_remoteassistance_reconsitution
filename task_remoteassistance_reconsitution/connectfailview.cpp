#include "connectfailview.h"

ConnectFailView::ConnectFailView()
{

}

QWidget* ConnectFailView::createDWidget()
{
    m_centralLayout->setContentsMargins(0, 30, 0, 0);

    m_font->setPointSize(15);
    m_pe->setColor(DPalette::WindowText, Qt::gray);

    m_pictureLabel->setFont(*m_font);
    m_pictureLabel->setText("连接失败");
    m_pictureLabel->setAlignment(Qt::AlignHCenter);


    m_font->setPointSize(10);
    m_wordLabel->setPalette(*m_pe);
    m_wordLabel->setWordWrap(true);
    m_wordLabel->setFont(*m_font);
    m_wordLabel->setText("网络状态不是很稳定，请点击重试按钮再次尝试连接");
    m_wordLabel->setAlignment(Qt::AlignHCenter);

    m_centralLayout->addWidget(m_pictureLabel, 0, Qt::AlignCenter);
    m_centralLayout->addSpacing(10);
    m_centralLayout->addWidget(m_wordLabel, 0, Qt::AlignCenter);
    m_centralLayout->addSpacing(10);
    QString pushWord = "重试";
    m_centralLayout->addWidget(createDPushButton(pushWord), 0, Qt::AlignCenter);
    return  wrapWidgetLayout(m_centralLayout);
}




