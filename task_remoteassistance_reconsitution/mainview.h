#ifndef MAINVIEW_H
#define MAINVIEW_H

#include "widgetbase.h"
#include <DToolButton>
class MainView : public WidgetBase
{
    Q_OBJECT
public:
    explicit MainView(QWidget *parent = nullptr);
    virtual QWidget* createDWidget() override;
    virtual QWidget* createDPushButton() ;
    DPushButton* iHelp = nullptr;
    DPushButton* hHelp = nullptr;


signals:

public slots:
};

#endif // MAINVIEW_H
