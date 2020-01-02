#include "connectview.h"

ConnectView::ConnectView() : WidgetBase ()
{
  spinnercon = new DSpinner();
  m_spinner = new DSpinner ();

}

QWidget *ConnectView::createDWidget()
{
    m_centralLayout->setContentsMargins(0, 30, 0, 0);

    spinnercon->setMinimumSize(50, 50);
    m_centralLayout->addWidget(spinnercon, 0, Qt::AlignCenter);

    m_font->setPointSize(12);
    m_wordLabel->setWordWrap(true);
    m_wordLabel->setFont(*m_font);
    m_wordLabel->setText("正在建立连接，请稍后");
    m_wordLabel->setAlignment(Qt::AlignHCenter);
    m_centralLayout->addWidget(m_wordLabel, 0, Qt::AlignCenter);
    m_centralLayout->addSpacing(0);
    QString pushWord = "取消";
    m_centralLayout->addWidget(createDPushButton(pushWord), 0, Qt::AlignCenter);

    return  wrapWidgetLayout(m_centralLayout);
}



