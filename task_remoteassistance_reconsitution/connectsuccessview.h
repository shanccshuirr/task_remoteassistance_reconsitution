#ifndef CONNECTSUCCESSVIEW_H
#define CONNECTSUCCESSVIEW_H
#include "widgetbase.h"
#include <QWidget>

class ConnectSuccessView : public WidgetBase
{
public:
    ConnectSuccessView();
    virtual QWidget* createDWidget() override;
};

#endif // CONNECTSUCCESSVIEW_H
