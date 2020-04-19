#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"

#include "variantdata.h"
#include "reader.h"

class Variabili
{
    public:
        QVector<double> get(void) { return x; }

        void set(QVector<double> input){
            x = input;
        }

        QVector<double> resize(int numero)
        {
            x.resize(numero);
            return x;
        }

        int size()
        {
            return x.size();
        }


        QVector<double> scala(float numero)
        {
            QVector<double> t(x.size());
            for(int s=0; s==x.size();s++)
            {
                t[s]=x[s]*numero;
                qDebug() << x[s];
            }
            return t;
        }

private:
        QVector<double> x;
}
 ;


Variabili l,g;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString filePath = "/home/luca/ss/7.csv";

    QList<QStringList> readData = QtCSV::Reader::readToList(filePath,";");

    QVector<double> x(readData.size()), y(readData.size());

    //l.resize(readData.size());

  for ( int i = 0; i < readData.size(); ++i )
  {
      x[i] = readData.at(i).value(1).toDouble()-1587149254484;
      y[i] = readData.at(i).value(2).toDouble();

  }

  //l.set(y);
  //g.set(x);


    ui->customPlot->setInteraction(QCP::iRangeDrag,true);
    ui->customPlot->setInteraction(QCP::iRangeZoom,true);


    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x,y);
    ui->customPlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    ui->customPlot->graph(0)->setPen(QPen(Qt::blue));
    connect(ui->customPlot,SIGNAL(mousePress(QMouseEvent *)),SLOT (clickedGraph(QMouseEvent*)));
    connect(ui->customPlot,SIGNAL(mouseMove(QMouseEvent *)),SLOT (MouseGraph(QMouseEvent*)));

    ui->customPlot->addGraph();

    ui->customPlot->xAxis->setLabel("Time");
    ui->customPlot->yAxis->setLabel("Acc");

    //double x_min = *std::min_element(x.constBegin(), x.constEnd());
    //double x_max = *std::max_element(x.constBegin(), x.constEnd());
    //double y_min = *std::min_element(y.constBegin(), y.constEnd());
    //double y_max = *std::max_element(y.constBegin(), y.constEnd());
    //ui->customPlot->xAxis->setRange(x_min, x_max);
    //ui->customPlot->yAxis->setRange(y_min, y_max);

    ui->customPlot->rescaleAxes();
    ui->customPlot->replot();
    //qDebug() << ui->customPlot->xAxis->pixelToCoord(mouseEvent->pos().x()) << ui->customPlot->yAxis->pixelToCoord(mouseEvent->pos().y());
}

void MainWindow::clickedGraph(QMouseEvent *event)
{
    QPoint point = event->pos();
    qDebug() << ui->customPlot->xAxis->pixelToCoord(point.x());
    qDebug() << ui->customPlot->yAxis->pixelToCoord(point.y());

}

void MainWindow::MouseGraph(QMouseEvent *event)
{
    QPoint point = event->pos();
    qDebug() << ui->customPlot->xAxis->pixelToCoord(point.x());
    qDebug() << ui->customPlot->yAxis->pixelToCoord(point.y());

    QVariant xi = ui->customPlot->xAxis->pixelToCoord(point.x());
    QVariant yi = ui->customPlot->yAxis->pixelToCoord(point.y());

    ui->xmouse->setText(xi.toString());
    ui->ymouse->setText(yi.toString());


}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    //QVector <double> tt[l.size()];
    //qDebug() << ui->horizontalSlider->value();
    //tt = l.scala(value);
    //ui->customPlot->removeGraph(0);
    //ui->customPlot->graph(0)->setData(g.get(),l.get());
    //ui->customPlot->replot();
    //ui->customPlot->addGraph();
}


