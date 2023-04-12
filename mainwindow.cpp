#include "mainwindow.h"
#include <QVBoxLayout>
#include <QWebElement>
#include <QWebFrame>

#include <QToolBar>
#include <QAction>
#include <QColorDialog>
#include <QComboBox>
#include <QLabel>

#include "annotationwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    aw = new annotationWidget("Lenna.png",this);
    this->setCentralWidget(aw);
    this->createToolbar();
}

void MainWindow::createToolbar()
{

    // Create a toolbar
           QToolBar *toolbar = new QToolBar("Toolbar", this);
           addToolBar(toolbar);

           // Create a button for color selection
           QAction *colorAction = new QAction("Select Color", this);
           connect(colorAction, &QAction::triggered, this, &MainWindow::onColorActionTriggered);
           toolbar->addAction(colorAction);

           toolbar->addWidget(new QLabel("Size"));
           // Create a combo box for size selection
           QComboBox *sizeComboBox = new QComboBox(this);
           for (int i = 1; i <= 31; i+=3) {
               sizeComboBox->addItem(QString::number(i));
           }
           connect(sizeComboBox, QOverload<int>::of(&QComboBox::activated), this, &MainWindow::onSizeComboBoxActivated);
           toolbar->addWidget(sizeComboBox);

           QAction *save = new QAction("Save",this);
           connect(save, &QAction::triggered, this, &MainWindow::onSaveActionTriggered);
           toolbar->addAction(save);

}

void MainWindow::onSaveActionTriggered()
{
  QImage img = aw->getImage();
  img.save("toto.png");
  qDebug() << "onSaveActionTriggered ";
}

void MainWindow::onColorActionTriggered()
{
    // Show color dialog and get selected color
    QColor color = QColorDialog::getColor(Qt::white, this, "Select Color");
    if (color.isValid()) {
        aw->changedColor(color);
        QPixmap pixmap(100,100);
        pixmap.fill(color);
        QIcon theIcon(pixmap);
        qobject_cast<QAction*>(sender())->setIcon(theIcon);
        qobject_cast<QAction*>(sender())->setText("Color");
    }

}

void MainWindow::onSizeComboBoxActivated(int index)
{
    int size = ( index + 1) * 4;
    aw->changedSize(size);
}

MainWindow::~MainWindow()
{
}

