#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_load_clicked()
{
    QString filename=QFileDialog::getOpenFileName();
    cout<<filename.toStdString()<<endl;
    ui->label_image->setPhoto(filename);
}

void MainWindow::on_pushButton_extract_clicked()
{
    QPixmap extPix=ui->label_image->getDrawing();
    ui->label_drawing->setGeometry(500,30,extPix.width(),extPix.height());
    ui->label_drawing->setPixmap(ui->label_image->getDrawing());
}

void MainWindow::on_pushButton_draw_clicked()
{
    bool draw=ui->label_image->isDrawEnabled();
    ui->label_image->setDrawEnable(!draw);

}
