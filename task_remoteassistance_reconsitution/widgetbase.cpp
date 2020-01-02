#include "widgetbase.h"
#include <QDebug>
WidgetBase::WidgetBase(QWidget *parent) : DWidget(parent)
{

    m_wordLabel = new QLabel ();
    m_pictureLabel = new QLabel ();
    m_bottPushBut = new QPushButton ();
    m_centralLayout =new QVBoxLayout ();
    m_pushBuLayout = new QVBoxLayout ();
    m_font = new QFont ();
    m_pe = new DPalette();
}

QWidget *WidgetBase::createDPushButton(QString &str)
{
    m_bottPushBut->setText(str);
    m_bottPushBut->setObjectName("WhiteButton");
    m_bottPushBut->setMinimumSize(200, 36);
    m_pushBuLayout->addWidget(m_bottPushBut);
    return wrapPushBottLayout(m_pushBuLayout);
}

QWidget *WidgetBase::createActions(QList<QWidget *> buttons)
{
    auto actionWidget = new QWidget;
    actionWidget->setMinimumHeight(10);
    QBoxLayout *actionLayout = nullptr;
    actionLayout = new QVBoxLayout(actionWidget);
    for (auto button : buttons) {
        button->setMinimumSize(200, 36);
        actionLayout->addWidget(button);
        actionLayout->setAlignment(button, Qt::AlignHCenter | Qt::AlignTop);
        actionLayout->setSpacing(20);
    }
    actionWidget->setTabOrder(buttons.last(), buttons.first());
    return actionWidget;
}

QWidget *WidgetBase::wrapPushBottLayout(QLayout *layout)
{
    QWidget* wrapWidget = new QWidget;
    wrapWidget->setLayout(layout);
    //wrapWidget->resize(200,200);
    return wrapWidget;
}

QWidget *WidgetBase::wrapWidgetLayout(QLayout *layout)
{
    this->setLayout(layout);
    return this;
}

WidgetBase::~WidgetBase()
{

}
