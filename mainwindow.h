#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWebKitWidgets/QWebView>
#include <QtWebKitWidgets/QWebPage>
#include <QtWebKitWidgets/QWebFrame>

class annotationWidget ;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createToolbar();

    annotationWidget *aw;

private slots:
           void onColorActionTriggered();
           void onSaveActionTriggered();
           void onSizeComboBoxActivated(int index);



};
#endif // MAINWINDOW_H
