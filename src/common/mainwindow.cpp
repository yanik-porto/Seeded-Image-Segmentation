#include "mainwindow.h"
#include "ui_mainwindow.h"

//-----------------------------------------------------------------------------
// Constructor and destructors
//-----------------------------------------------------------------------------

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    label_image(new imgLabel()),
    beta(0.00005)
{
    ui->setupUi(this);

    ui->scrollArea->setWidget(label_image);
    ui->lineEdit_Beta->setText(QString::number(beta));
    HideGroupBox(1);
    ui->label_Instructions->setText("Load an image");
}

MainWindow::~MainWindow()
{
    delete label_image;
    delete ui;
}

//-----------------------------------------------------------------------------
// Private slots
//-----------------------------------------------------------------------------

void MainWindow::on_pushButton_Load_clicked()
{
    QString filename=QFileDialog::getOpenFileName();
    cout<<filename.toStdString()<<endl;
    label_image->setPhoto(filename);
    if(label_image->GetSize()<ui->scrollArea->height())
        label_image->SetSize((label_image->height() - label_image->GetSize())/2);
    else
        label_image->SetSize(0);

    matrixEngine.set_picturePath(filename);

    label_image->SwapDrawEnable();
    HideGroupBox(2);
    ui->label_Instructions->setText("Draw on the image");
}

void MainWindow::on_pushButton_Front_Draw_clicked()
{
    label_image->SetFrontDraw(true);
}

void MainWindow::on_pushButton_Back_Draw_clicked()
{
    label_image->SetFrontDraw(false);
}

void MainWindow::on_pushButton_CtrlZ_clicked()
{
    label_image->CtrlZ();
}

void MainWindow::on_pushButton_Small_Pencil_clicked()
{
    label_image->SetSizePencil(5);
}

void MainWindow::on_pushButton_Medium_Pencil_clicked()
{
    label_image->SetSizePencil(10);
}

void MainWindow::on_pushButton_Large_Pencil_clicked()
{
    label_image->SetSizePencil(20);
}


void MainWindow::on_pushButton_Extract_clicked()
{

    ui->progressBar->setValue(30);

    QPixmap extPix=label_image->getDrawing();
    QString fileSeeds = "extPix.png";
    extPix.save(fileSeeds,"PNG");

    cout<<beta<<endl;

    final_image = matrixEngine.segment_image(fileSeeds, beta);

    ui->progressBar->setValue(100);
    ui->label_Instructions->setText("Display the result and try again");

    HideGroupBox(5);
}



void MainWindow::on_pushButton_Save_clicked()
{
    namedWindow("Result", WINDOW_AUTOSIZE );
    imshow("Result", final_image);
    cout<<"Type :"<<final_image.type()<<endl;


    waitKey(0);

}

void MainWindow::on_pushButtonOK_2_clicked()
{
    HideGroupBox(3);
    label_image->SwapDrawEnable();
    ui->label_Instructions->setText("Choose a value for beta");
}

void MainWindow::on_pushButtonOK_3_clicked()
{
    HideGroupBox(4);
    beta = ui->lineEdit_Beta->text().toFloat();
    ui->label_Instructions->setText("Extract and wait for 100%");
}

void MainWindow::on_pushButtonOK_5_clicked()
{
    HideGroupBox(1);
}

//-----------------------------------------------------------------------------
// Private slots
//-----------------------------------------------------------------------------
void MainWindow::HideGroupBox(int Index)
{


    switch( Index )
    {
    case 1:
        ui->groupBox_Load->setEnabled(true);
        ui->groupBox_Draw->setEnabled(false);
        ui->groupBox_Algorithm->setEnabled(false);
        ui->groupBox_Extract->setEnabled(false);
        ui->groupBox_Result->setEnabled(false);
        break;

    case 2:
        ui->groupBox_Load->setEnabled(false);
        ui->groupBox_Draw->setEnabled(true);
        ui->groupBox_Algorithm->setEnabled(false);
        ui->groupBox_Extract->setEnabled(false);
        ui->groupBox_Result->setEnabled(false);
        break;

    case 3:
        ui->groupBox_Load->setEnabled(false);
        ui->groupBox_Draw->setEnabled(false);
        ui->groupBox_Algorithm->setEnabled(true);
        ui->groupBox_Extract->setEnabled(false);
        ui->groupBox_Result->setEnabled(false);
        break;

    case 4:
        ui->groupBox_Load->setEnabled(false);
        ui->groupBox_Draw->setEnabled(false);
        ui->groupBox_Algorithm->setEnabled(false);
        ui->groupBox_Extract->setEnabled(true);
        ui->groupBox_Result->setEnabled(false);
        break;

    case 5:
        ui->groupBox_Load->setEnabled(false);
        ui->groupBox_Draw->setEnabled(false);
        ui->groupBox_Algorithm->setEnabled(false);
        ui->groupBox_Extract->setEnabled(false);
        ui->groupBox_Result->setEnabled(true);
        break;


    }
}


