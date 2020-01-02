#ifndef WIDGETFACTORY_H
#define WIDGETFACTORY_H

#include <DMainWindow>
#include <DWidget>
#include <DSpinner>
#include <QTimer>
#include <QPainter>
#include <QLabel>
#include <ddialog.h>
#include <DThemeManager>
#include <DPushButton>
#include <DWidgetUtil>
#include <DStandardPaths>
#include <DHiDPIHelper>
#include <DTitlebar>
#include <DApplication>
#include <QClipboard>
#include <dtoast.h>
#include <DSuggestButton>
#include <dfilechooseredit.h>
#include <DMessageBox>
#include <QTextEdit>
#include <DSpinner>
#include <DToolButton>
DWIDGET_USE_NAMESPACE

class WidgetBase : public DWidget
{
    Q_OBJECT
public:
    explicit WidgetBase(QWidget *parent = nullptr);
    virtual QWidget* createDWidget() = 0;
    virtual QWidget* createDPushButton(QString&str);
    virtual QWidget* createActions(QList<QWidget *> buttons);
    virtual QWidget* wrapPushBottLayout(QLayout *layout);
    virtual QWidget* wrapWidgetLayout(QLayout *layout);
    virtual~WidgetBase();

    DSpinner* m_spinner  = nullptr;
    QTextEdit* m_textEdit  = nullptr;
    QLabel* m_wordLabel = nullptr;
    QLabel* m_pictureLabel = nullptr;
    QPushButton* m_topPushBut = nullptr;
    QPushButton* m_bottPushBut = nullptr;
    QLineEdit* m_lineEdit = nullptr;
    QVBoxLayout* m_centralLayout = nullptr;
    QVBoxLayout* m_pushBuLayout = nullptr;
    QTimer* m_timer = nullptr;
    QTimer* m_timerFive = nullptr;
    QTimer* m_timerTwo = nullptr;
    QFont* m_font = nullptr;
    DPalette* m_pe = nullptr;

signals:

public slots:
};

#endif // WIDGETFACTORY_H
