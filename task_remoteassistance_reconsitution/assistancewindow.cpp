#include <QDebug>
#include <QStack>
#include <QDate>
#include <QTimer>
#include <QPainter>
#include <QLabel>
#include <QFileDialog>
#include <QDesktopServices>
#include <QMouseEvent>

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
//#include <QMessageBox>
//#include <DMessageBox>
#include <QTextEdit>
#include <DSpinner>
#include <DToolButton>
#include "assistancewindow.h"
#include "connectview.h"
#include "connectsuccessview.h"
#include "connectfailview.h"
#include "mainview.h"
#include "copyview.h"
#include "waitview.h"
#include "inputview.h"
#include "displayview.h"
DWIDGET_USE_NAMESPACE


class AssistanceWindowPrivate: public QObject
{
    

public:
    AssistanceWindowPrivate(AssistanceWindow *parent) : q_ptr(parent)
    {


        mainView = new MainView();
        waitCodeView = new WaitView();
        inPutView = new InputView();
        copyView = new CopyView();
        connectView = new ConnectView();
        connectFailView = new ConnectFailView();
        connectSuccessView = new ConnectSuccessView();
        displayCodeView = new DisplayView();

        createMainSlot();
        createCopySlot();
        createInputSlot();
        createWaitSlot();
        createDisolayCodeSlot();
        createConnectSlot();
        createConnectFailSlot();
        createConnectSuccessSlot();





    }
    ~ AssistanceWindowPrivate()
    {

    }
    void initUI();//初始化
    void setBackground(const QPixmap &pixmap);
    



    QWidget *wrapLayout(QLayout *layout);
    QString copyText(QLabel *code);//复制验证码到粘贴板
    QString random(unsigned int n);//随机数
    void setTitle(bool flag, QString);//设置标题



    
    QWidget *createMainSlot();//主界面 按钮的布局和槽函数
    QWidget *createCopySlot();//复制成功界面 按钮的布局和槽函数
    QWidget *createInputSlot();//输入界面 按钮的布局和槽函数
    QWidget *createWaitSlot();//等待界面 按钮的布局和槽函数
    QWidget *createDisolayCodeSlot();//验证码显示界面 按钮的布局和槽函数
    QWidget *createConnectSlot();//连接界面 按钮的布局和槽函数
    QWidget *createConnectFailSlot();//连接失败界面 按钮的布局和槽函数
    QWidget *createConnectSuccessSlot();//连接成功界面 按钮的布局和槽函数
    
    
    //QStack<QWidget *> viewStack;
    QVBoxLayout *centralLayout      = Q_NULLPTR;//布局
    MainView *mainView               = Q_NULLPTR;//主界面
    WaitView *waitCodeView         = Q_NULLPTR;//等待界面
    DisplayView *displayCodeView       = Q_NULLPTR;//验证码显示界面
    InputView *inPutView               = Q_NULLPTR;//输入界面
    ConnectView *connectView            = Q_NULLPTR;//连接界面
    ConnectFailView *connectFailView            = Q_NULLPTR;//连接失败界面
    ConnectSuccessView *connectSuccessView            = Q_NULLPTR;//连接成功界面
    CopyView *copyView          = Q_NULLPTR;//复制成功界面
    QWidget *recordWidget           = Q_NULLPTR;
    /********************/
    QString m_code = "";




    DWidget *head                  = Q_NULLPTR;//标题
    QPixmap backgroundPixmap;
    AssistanceWindow *q_ptr;


private:
    Q_DECLARE_PUBLIC(AssistanceWindow)
};



AssistanceWindow::AssistanceWindow(QWidget *parent) :
    DMainWindow(parent), dd_ptr(new AssistanceWindowPrivate(this))
{
    Q_D(AssistanceWindow);
    stackMainWindows = new QStackedWidget(this);
    setCentralWidget(stackMainWindows);
    tit = this->titlebar();
    d->initUI();
}

AssistanceWindow::~AssistanceWindow()
{

}

bool AssistanceWindow::eventFilter(QObject *target, QEvent *event)
{


}






QWidget *AssistanceWindowPrivate::createMainSlot()
{
    Q_Q(AssistanceWindow);
    connect(mainView->iHelp,&DPushButton::clicked, q ,[ = ]() {

        q->stackMainWindows->setCurrentWidget(waitCodeView);
        recordWidget = waitCodeView;
        waitCodeView->spinnerWait->start();
        qDebug() << "createHelpAction iHelp";
        m_code = random(999999);
        mainView->m_timerTwo->start(2000);
        setTitle(true, "我要求助");

    });

    connect(mainView->m_timerTwo, &QTimer::timeout, q, [ = ]() {

        displayCodeView->m_wordLabel->setText(m_code);
        q->stackMainWindows->setCurrentWidget(displayCodeView);
        recordWidget = displayCodeView;
        qDebug() << "createBtAction funButton";
        mainView->m_timerTwo->stop();
    });


   connect(mainView->hHelp, &DPushButton::clicked, q, [ = ]() {
        q->stackMainWindows->setCurrentWidget(inPutView);
        recordWidget = inPutView;
        setTitle(true, "帮助别人");
    });
}

QWidget *AssistanceWindowPrivate::createCopySlot()
{
    Q_Q(AssistanceWindow);
    connect(copyView->m_bottPushBut, &DPushButton::clicked, [ = ]() {

        q->stackMainWindows->setCurrentWidget(mainView);
        recordWidget = mainView;
        setTitle(false, "远程协助");
        qDebug() << "createCopyAction funButton";
        displayCodeView->m_timer->stop();
    });
    connect(displayCodeView->m_timer, &QTimer::timeout, q, [ = ]() {


        q->stackMainWindows->setCurrentWidget(mainView);
        recordWidget = mainView;
        qDebug() << "createConnectAction success funButton";
        displayCodeView->m_timer->stop();
    });
}

QWidget *AssistanceWindowPrivate::createInputSlot()
{
    Q_Q(AssistanceWindow);
   connect(inPutView->m_bottPushBut, &DSuggestButton::clicked, q, [ = ]() {

        q->stackMainWindows->setCurrentWidget(mainView);
        recordWidget = mainView;
        setTitle(false, "远程协助");
        inPutView->m_lineEdit->clear();
    });

   connect(inPutView->m_timerFive, &QTimer::timeout, q, [ = ]() {

       if (!inPutView->m_lineEdit->text().compare(m_code)) {
           q->stackMainWindows->setCurrentWidget(connectSuccessView);
           recordWidget = connectSuccessView;
           qDebug() << "createConnectAction success funButton";
       } else {
           q->stackMainWindows->setCurrentWidget(connectFailView);
           recordWidget = connectFailView;
           qDebug() << "createConnectAction fail funButton";
       }
       inPutView->m_timerFive->stop();
   });


    connect(inPutView->m_lineEdit, &QLineEdit::textChanged,
    [ = ]() {

        QRegExp wx("[0-9]{1,6}");
        QValidator *latitude = new QRegExpValidator(wx);
        inPutView->m_lineEdit->setValidator(latitude);
        QString fullkey = inPutView->m_lineEdit->text();
        if (fullkey.length() == 6) {
            inPutView->m_topPushBut->setText("连接");
            inPutView->m_topPushBut->setEnabled(true);
        } else {
            inPutView->m_topPushBut->setText("取消");
        }
        QFont font;
        DPalette pe;
        int pos = 6;
        QRegExpValidator keyValidator(wx);
        bool keyValid = !((keyValidator.validate(fullkey, pos) != QValidator::Acceptable));
        bool flag = fullkey.isEmpty();
        if (!keyValid && !flag) {

            inPutView->m_wordLabel->setText("输入非法，可能是非数字");
            pe.setColor(DPalette::WindowText, Qt::red);
             inPutView->m_wordLabel->setPalette(pe);
        } else {
             inPutView->m_wordLabel->setText("请你输入协助别人的六位数字验证码，完成后点击开始协助对方");
            pe.setColor(DPalette::WindowText, Qt::gray);
             inPutView->m_wordLabel->setPalette(pe);
        }
    });

    connect(inPutView->m_topPushBut, &DSuggestButton::clicked, q, [ = ]() {
        if (!inPutView->m_topPushBut->text().compare("连接")) {
            q->stackMainWindows->setCurrentWidget(connectView);
            recordWidget = connectView;
            connectView->spinnercon->start();
            inPutView->m_timerFive->start(5000);
        } else {
            q->stackMainWindows->setCurrentWidget(mainView);
            recordWidget = connectView;
             inPutView->m_lineEdit->clear();
        }

    });
}

QWidget *AssistanceWindowPrivate::createWaitSlot()
{
    Q_Q(AssistanceWindow);
    connect(waitCodeView->m_bottPushBut, &DPushButton::clicked, q, [ = ]() {
        q->stackMainWindows->setCurrentWidget(mainView);
        recordWidget = mainView;
        setTitle(false, "远程协助");
        mainView->m_timerTwo->stop();
        qDebug() << "createBtAction funButton";
    });

}

QWidget *AssistanceWindowPrivate::createDisolayCodeSlot()
{
    Q_Q(AssistanceWindow);
    connect(displayCodeView->m_bottPushBut, &DPushButton::clicked, q, [ = ]() {
        QString pasteValue = copyText(displayCodeView->m_wordLabel);
        if (pasteValue != "") {
            q->stackMainWindows->setCurrentWidget(copyView);
            recordWidget = copyView;
            displayCodeView->m_timer->start(10000);
            qDebug() << "createDisolayCodeAction funButton";
        } else {
            qDebug() << "copy fail!";
        }

    });
}

QWidget *AssistanceWindowPrivate::createConnectSlot()
{
    Q_Q(AssistanceWindow);
    connect(connectView->m_bottPushBut, &DPushButton::clicked, q, [ = ]() {
        q->stackMainWindows->setCurrentWidget(inPutView);
        recordWidget = inPutView;
        inPutView->m_timerFive->stop();
        qDebug() << "createConnectAction funButton";
    });


}

QWidget *AssistanceWindowPrivate::createConnectFailSlot()
{
    Q_Q(AssistanceWindow);
    connect(connectFailView->m_bottPushBut, &DPushButton::clicked, q, [ = ]() {

        q->stackMainWindows->setCurrentWidget(inPutView);
        recordWidget = connectView;
//        timerFive->start(5000);
        qDebug() << "createConnectAction success funButton";
    });
    
}

QWidget *AssistanceWindowPrivate::createConnectSuccessSlot()
{
    Q_Q(AssistanceWindow);
    connect(connectSuccessView->m_bottPushBut, &DPushButton::clicked, q, [ = ]() {
        q->stackMainWindows->setCurrentWidget(mainView);
        recordWidget = mainView;
        qDebug() << "createConnectSuccessAction funButton";
    });
}



QWidget *AssistanceWindowPrivate::wrapLayout(QLayout *layout)
{
    auto wrapWidget = new QWidget;
    wrapWidget->setLayout(layout);
    //wrapWidget->resize(200,200);
    return wrapWidget;
}



QString AssistanceWindowPrivate::copyText(QLabel *code)
{
    QClipboard *clipboard = QApplication::clipboard();   //获取系统剪贴板指针
    clipboard->setText(displayCodeView->m_wordLabel->text());
    QString originalText = clipboard->text();//获取剪贴板上文本信息
    qDebug() << "copyText :" << originalText;
    return originalText;
}

QString AssistanceWindowPrivate::random(unsigned int n)
{
    QTime time;
    time = QTime::currentTime();
    qsrand(time.msec() + time.second() * 1000);
    int code = qrand() % n;
    if (code < 100000) {
        code += 100000;
    }
    return QString::number(code);
}


void AssistanceWindowPrivate::setTitle(bool flag, QString title)
{
    Q_Q(AssistanceWindow);
    head = new DWidget();
    QHBoxLayout *centralLayout = new QHBoxLayout();
    QLabel *leftLab = new QLabel();
    if (flag) {
        if (!title.compare("我要求助")) {
            leftLab->setPixmap((QPixmap(":/images/005.png")));
        } else {
            leftLab->setPixmap((QPixmap(":/images/006.png")));
        }


    } else {
        leftLab = nullptr;
    }

    QLabel *rightLab = new QLabel();

    rightLab->setText(title);
    centralLayout->addSpacing(100);
    centralLayout->addWidget(leftLab, 0, Qt::AlignCenter);
    centralLayout->addWidget(rightLab, 0, Qt::AlignCenter);
    centralLayout->addSpacing(0);
    head->setLayout(centralLayout);
    q->tit->setCustomWidget(head);
}


void AssistanceWindowPrivate::initUI()
{
    Q_Q(AssistanceWindow);



    mainView->createDWidget();
    waitCodeView->createDWidget();
    inPutView->createDWidget();
    connectView->createDWidget();
    displayCodeView->createDWidget();
    copyView->createDWidget();
    connectFailView->createDWidget();
    connectSuccessView->createDWidget();




    q->stackMainWindows->addWidget(mainView);
    q->stackMainWindows->addWidget(waitCodeView);
    q->stackMainWindows->addWidget(inPutView);
    q->stackMainWindows->addWidget(connectView);
    q->stackMainWindows->addWidget(displayCodeView);
    q->stackMainWindows->addWidget(copyView);
    q->stackMainWindows->addWidget(connectFailView);
    q->stackMainWindows->addWidget(connectSuccessView);
    q->stackMainWindows->setCurrentWidget(mainView);


}

void AssistanceWindowPrivate::setBackground(const QPixmap &pixmap)
{

}












