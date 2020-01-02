#include "inputview.h"

InputView::InputView() : WidgetBase ()
{
   m_topPushBut = new QPushButton ();
   m_lineEdit = new QLineEdit ();
   m_timerFive = new QTimer();
}

QWidget *InputView::createDWidget()
{

    m_centralLayout->setContentsMargins(0, 10, 0, 0);
    m_font->setPointSize(25);
    m_lineEdit->setMinimumSize(300, 40);
    m_lineEdit->setFont(*m_font);
    m_lineEdit->setAlignment(Qt::AlignHCenter);
    m_centralLayout->addWidget(m_lineEdit, 0, Qt::AlignCenter);
    m_centralLayout->addSpacing(10);

    m_font->setPointSize(10);
    m_pe->setColor(DPalette::WindowText, Qt::gray);


    m_wordLabel->setWordWrap(true);
    m_wordLabel->setFont(*m_font);
    m_wordLabel->setPalette(*m_pe);
    m_wordLabel->setWordWrap(true);

    m_wordLabel->setText("请你输入协助别人的六位数字验证码，完成后点击开始协助对方");
    m_wordLabel->setAlignment(Qt::AlignHCenter);
    m_centralLayout->addWidget(m_wordLabel, 0, Qt::AlignCenter);
    m_centralLayout->addSpacing(10);
    m_centralLayout->addWidget(createDPushButton(), 0, Qt::AlignCenter);
    return  wrapWidgetLayout(m_centralLayout);
}

QWidget *InputView::createDPushButton()
{

    m_bottPushBut->setText(QObject::tr("返回"));//operator BT
    m_topPushBut->setText(QObject::tr("取消"));//operator BT
    auto desktopAction = createActions({m_topPushBut, m_bottPushBut});
    m_pushBuLayout->addWidget(desktopAction);
    return wrapPushBottLayout(m_pushBuLayout);

}

