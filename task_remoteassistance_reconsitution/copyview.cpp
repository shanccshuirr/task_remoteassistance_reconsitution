#include "copyview.h"

CopyView::CopyView() : WidgetBase()
{

}

QWidget *CopyView::createDWidget()
{

    m_centralLayout->setContentsMargins(0, 10, 0, 0);
    m_pe->setColor(DPalette::WindowText, Qt::gray);
    m_font->setPointSize(15);

    m_pictureLabel->setFont(*m_font);
    m_pictureLabel->setText("复制成功到粘贴板");
    m_pictureLabel->setAlignment(Qt::AlignHCenter);


    m_font->setPointSize(8);

    m_wordLabel->setWordWrap(true);
    m_wordLabel->setFont(*m_font);
    m_wordLabel->setPalette(*m_pe);
    m_wordLabel->setText("连接成功后，此界面会自动隐藏到任务栏");
    m_wordLabel->setAlignment(Qt::AlignHCenter);
    m_centralLayout->addWidget(m_pictureLabel, 0, Qt::AlignCenter);
    m_centralLayout->addSpacing(10);
    m_centralLayout->addWidget(m_wordLabel, 0, Qt::AlignCenter);
    m_centralLayout->addSpacing(10);
    QString pushWord = "返回";
    m_centralLayout->addWidget(createDPushButton(pushWord), 0, Qt::AlignCenter);
    return  wrapWidgetLayout(m_centralLayout);
}




