#ifndef WAITVIEW_H
#define WAITVIEW_H

#include <QWidget>
#include "widgetbase.h"
class WaitView :public WidgetBase
{
public:
    WaitView();
    virtual QWidget* createDWidget() override;
    DSpinner* spinnerWait = nullptr;
};

#endif // WAITVIEW_H
