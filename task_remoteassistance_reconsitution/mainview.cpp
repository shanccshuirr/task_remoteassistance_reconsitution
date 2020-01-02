#include "mainview.h"
#include "widgetbase.h"
MainView::MainView(QWidget *parent) : WidgetBase (parent)
{
    iHelp = new DPushButton();
    hHelp = new DPushButton();
    m_timerTwo = new QTimer();
}

QWidget *MainView::createDWidget()
{


    m_centralLayout->setContentsMargins(0, 10, 0, 0);
    QImage *img = new QImage;
    img->load(":/images/001.png");
    m_pictureLabel->setPixmap(QPixmap::fromImage(*img));
    m_pictureLabel->setScaledContents(true);
    m_centralLayout->addWidget(m_pictureLabel, 0, Qt::AlignCenter);
    m_centralLayout->addSpacing(20);

    m_pe->setColor(DPalette::WindowText, Qt::gray);
    m_font->setPointSize(8);

    m_wordLabel->setWordWrap(true);
    m_wordLabel->setFont(*m_font);
    m_wordLabel->setPalette(*m_pe);
    m_wordLabel->setText("这是由deepin团队开发的远程协助应用，如果您在使用的过程中遇到困难，或者友人求助于你，请点击下方的我要求助或帮助别人.");
    m_wordLabel->setAlignment(Qt::AlignHCenter);
    m_wordLabel->setMinimumSize(320, 40);
    m_centralLayout->addWidget(m_wordLabel, 0, Qt::AlignCenter);
    m_centralLayout->addSpacing(0);
    m_centralLayout->addWidget(createDPushButton(), 0, Qt::AlignCenter);//主界面 按钮的布局和槽函数
    return  wrapWidgetLayout(m_centralLayout);
}

QWidget *MainView::createDPushButton()
{

    iHelp->setText(QObject::tr("我要求助"));
    iHelp->setIcon(QIcon(QPixmap(":/images/002.png")));

    iHelp->setObjectName("WhiteButton");

    hHelp->setText(QObject::tr("帮助别人"));
    hHelp->setIcon(QIcon(QPixmap(":/images/003.png")));
    hHelp->setObjectName("WhiteButton");


    auto desktopAction = createActions({iHelp, hHelp});
    m_pushBuLayout->addWidget(desktopAction);
    return wrapPushBottLayout(m_pushBuLayout);
}


