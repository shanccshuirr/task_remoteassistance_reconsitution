#ifndef COPYVIEW_H
#define COPYVIEW_H

#include <QWidget>
#include "widgetbase.h"
class CopyView : public WidgetBase
{
public:
    CopyView();
    virtual QWidget* createDWidget() override;
};

#endif // COPYVIEW_H
