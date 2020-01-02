#ifndef CONNECTVIEW_H
#define CONNECTVIEW_H

#include <QWidget>
#include "widgetbase.h"
class ConnectView : public WidgetBase
{
public:
    ConnectView();
    virtual QWidget* createDWidget() override;
    DSpinner* spinnercon = nullptr;
};

#endif // CONNECTVIEW_H
