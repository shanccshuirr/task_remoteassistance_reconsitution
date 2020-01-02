#ifndef CONNECTFAILVIEW_H
#define CONNECTFAILVIEW_H
#include "widgetbase.h"

class ConnectFailView : public WidgetBase
{
public:
    ConnectFailView();
    virtual QWidget* createDWidget() override;
};

#endif // CONNECTFAILVIEW_H
