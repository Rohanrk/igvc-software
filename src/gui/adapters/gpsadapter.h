#ifndef GPSVISUALIZER_H
#define GPSVISUALIZER_H

#include <QWidget>
#include <QString>
#include <QPainter>
#include <QLabel>
#include <hardware/sensors/gps/GPS.hpp>

using namespace IGVC::Sensors;

namespace Ui {
class GPSAdapter;
}

class GPSAdapter : public QWidget
{
    Q_OBJECT

public:
    explicit GPSAdapter(GPS *gps, QWidget *parent = 0);
    void labelPrint();
    void paintEvent(QPaintEvent *event);
    ~GPSAdapter();

private slots:
    void on_user_Top_textChanged();

    void on_user_Right_textChanged();

    void on_user_Bottom_textChanged();

    void on_user_Left_textChanged();

private:

    Ui::GPSAdapter *ui;

    /*
     * First index identifies coordinates (0 -> n, newest -> oldest)
     * Second index identifies parts of coordinates (0=latitude, 1=longitude)
     */
    double coordinates[5][2];
    QLabel dataLabel;
    double horizontalFactor;
    double verticalFactor;
    double minLat;
    double maxLat;
    double minLong;
    double maxLong;

    void OnNewData(GPSData data);
    LISTENER(GPSAdapter,OnNewData,GPSData)
    GPS* _GPS;
};


#endif // GPSVISUALIZER_H