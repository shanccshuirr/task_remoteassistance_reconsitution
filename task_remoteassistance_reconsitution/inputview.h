#ifndef INPUTVIEW_H
#define INPUTVIEW_H

#include <QWidget>
#include "widgetbase.h"
class InputView : public WidgetBase
{
public:
    InputView();
    virtual QWidget* createDWidget() override;
    virtual QWidget* createDPushButton();
};

#endif // INPUTVIEW_H
