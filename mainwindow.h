#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <windows.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonRefreshTableWidgetWindowInfo_clicked();
    void onCheckboxToggled(bool checked, HWND hwnd);

    void on_pushButtonShowCheckedWindow_clicked();

    void on_pushButtonStart_clicked();

    void on_pushButtonStop_clicked();

    void on_actionOpenWorkingDir_triggered();

    void on_actionOpenAppDir_triggered();

    void on_actionOpenAboutDialog_triggered();

private:
    Ui::MainWindow *ui;
    QList<HWND> _targetWindowHandleList;
    HHOOK _hookId = nullptr;

    void RefreshTableWidgetWindowInfo();
    static BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam);
    static LRESULT HookCallback(int code, WPARAM wParam, LPARAM lParam);
};
#endif // MAINWINDOW_H
