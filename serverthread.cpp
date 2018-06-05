#include "serverthread.h"
#include <iostream>
#include "AHRS/AHRS.hpp"
#include <QCoreApplication>
#include <unistd.h>
#include <sys/time.h>
#include <Common/InertialSensor.h>
#include "Pendulum/pendulumparam.h"
#include "Pendulum/imageconvertor.h"
#include "Pendulum/abstractimageconvertor.h"
#include "Pendulum/abstractlinedisplay.h"
#include "Pendulum/apa102display.h"
#include "Network/piserver.h"
#include <QQuaternion>
#include "deviceparam.h"
#include "serverthread.h"

using namespace std;


PendulumThread::PendulumThread()
{
}

void PendulumThread::run()
{
    QString imagePath = "/home/minsk/Изображения/red.jpg";
    DeviceParam *dp = new DeviceParam();
    QImage *img = new QImage(imagePath);
    AbstractImageConvertor *imgConverter = new ImageConvertor(dp);
    AbstractLineDisplay *apaDriver = new Apa102Display(dp);
    QQuaternion *vertQ = new QQuaternion(sqrt(2) / 2, 0, sqrt(2) / 2, 0);
    QQuaternion resQ;
    QObject::connect(this->pi,
                     SIGNAL(newDataRead(Message)),
                     imgConverter,
                     SLOT(convertMessage(Message)),
                     Qt::DirectConnection);
        auto imu = AHRS::getInertialSensor(dp->getSensorType().toStdString());

        if (!imu) {
            printf("Wrong sensor name. Select: mpu or 9250 or lsm\n");
            return EXIT_FAILURE;
        }

        if (!imu->probe()) {
            printf("Sensor not enable\n");
            return EXIT_FAILURE;
        }


        auto ahrs = std::unique_ptr <AHRS>{new AHRS(move(imu)) };

    -------------------- Setup gyroscope offset -----------------------------

    ahrs->setGyroOffset();
    int i = 0;
    while(i++ < 50000) {
        if(imgConverter->isEmpty()){
            AHRS::imuLoop(ahrs.get());
            resQ = *ahrs->getQ() * *vertQ;
            apaDriver->transfer(imgConverter->getImageLine(0));
            cout <<90 + resQ.z() * 2 * 90 / sqrt(2) << "\n";
        }
        usleep(2000);
    }
}
