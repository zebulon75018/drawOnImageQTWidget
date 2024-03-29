#ifndef ANNOTATIONWIDGET_H
#define ANNOTATIONWIDGET_H

#include <QWidget>
#include <QtWebKitWidgets/QWebView>
#include <QtWebKitWidgets/QWebPage>
#include <QtWebKitWidgets/QWebFrame>

class QImage;

class annotationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit annotationWidget(QString filename, QWidget *parent = nullptr);
    explicit annotationWidget(QImage img, QWidget *parent = nullptr);
     void    init();

     void   changedColor(QColor color);
     void   changedSize(int size);
     QImage getImage();

    QWebView  *_view;
    QWebPage  *_page;
    QWebFrame *_frame;

    QImage   _image;
    QString  _filename;
    bool     isLoaded;
signals:
private slots:
    void loadedfinish(bool value);


};

#endif // ANNOTATIONWIDGET_H
