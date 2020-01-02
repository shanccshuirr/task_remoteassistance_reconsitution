#include "waitview.h"
#include<QString>
WaitView::WaitView() : WidgetBase()
{
    spinnerWait = new DSpinner();
}

QWidget *WaitView::createDWidget()
{


    m_centralLayout->setContentsMargins(0, 30, 0, 0);

    spinnerWait->setMinimumSize(50, 50);
    m_centralLayout->addWidget(spinnerWait, 0, Qt::AlignCenter);

    m_font->setPointSize(12);

    m_wordLabel->setWordWrap(true);
    m_wordLabel->setFont(*m_font);
    m_wordLabel->setText("正在生成请求验证码，请稍后...");
    m_wordLabel->setAlignment(Qt::AlignHCenter);
    m_centralLayout->addWidget(m_wordLabel, 0, Qt::AlignCenter);
    QString pushWord = "取消";
    m_centralLayout->addWidget(createDPushButton(pushWord), 0, Qt::AlignCenter);
    return  wrapWidgetLayout(m_centralLayout);
}



