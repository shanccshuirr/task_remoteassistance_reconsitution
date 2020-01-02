#include "connectsuccessview.h"

ConnectSuccessView::ConnectSuccessView() : WidgetBase ()
{

}

QWidget *ConnectSuccessView::createDWidget()
{
    m_centralLayout->setContentsMargins(0, 30, 0, 0);

    m_font->setPointSize(15);
    m_pe->setColor(DPalette::WindowText, Qt::gray);

    m_pictureLabel->setFont(*m_font);
    m_pictureLabel->setText("您正在进行远程协助");
    m_pictureLabel->setAlignment(Qt::AlignHCenter);

    m_font->setPointSize(10);

    m_wordLabel->setPalette(*m_pe);
    m_wordLabel->setWordWrap(true);
    m_wordLabel->setFont(*m_font);
    m_wordLabel->setText("当前已经有一个连接回话，如果您想建立新的连接，请先断开");
    m_wordLabel->setAlignment(Qt::AlignHCenter);

    m_centralLayout->addWidget(m_pictureLabel, 0, Qt::AlignCenter);
    m_centralLayout->addSpacing(20);
    m_centralLayout->addWidget(m_wordLabel, 0, Qt::AlignCenter);
    m_centralLayout->addSpacing(30);
    QString pushWord = "断开";
    m_centralLayout->addWidget(createDPushButton(pushWord),0, Qt::AlignCenter);
    return  wrapWidgetLayout(m_centralLayout);
}



