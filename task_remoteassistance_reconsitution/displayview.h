#ifndef DISPLAYVIEW_H
#define DISPLAYVIEW_H

#include <QWidget>
#include "widgetbase.h"
class DisplayView : public WidgetBase
{
public:
    DisplayView();
    virtual QWidget* createDWidget() override;

};

#endif // DISPLAYVIEW_H
