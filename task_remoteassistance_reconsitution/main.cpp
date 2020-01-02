#include "assistancewindow.h"
#include <DApplication>
#include <DMainWindow>
#include <DWidgetUtil>
#include <DGuiApplicationHelper>


DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();
    DApplication a(argc, argv);

    DGuiApplicationHelper::instance()->setPaletteType(DGuiApplicationHelper::LightType);

    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
    //a.setTheme("light");
    a.setOrganizationName("deepin");
    a.setApplicationName("远程协助");
    a.setApplicationVersion("1.0");
    a.setProductIcon(QIcon(":/images/004.png"));
    a.setProductName("远程协助");
    a.setApplicationDescription("远程协助");
    a.loadTranslator();

    AssistanceWindow w;

    w.setFixedSize(360,320);
    w.show();

   Dtk::Widget::moveToCenter(&w);

    return a.exec();
}
