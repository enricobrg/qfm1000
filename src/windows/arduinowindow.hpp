/*
 * qFM1000
 * Copyright (C) 2017  Luca Cireddu
 * sardylan@gmail.com
 * http://www.lucacireddu.it
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef __QFM1000_WINDOWS_ARDUINOWINDOW_H
#define __QFM1000_WINDOWS_ARDUINOWINDOW_H

#include <QDialog>

namespace Ui {
    class ArduinoWindow;
}

class ArduinoWindow : public QDialog {
Q_OBJECT

public:
    explicit ArduinoWindow(QWidget *parent = nullptr);

    ~ArduinoWindow() override;

public slots:

    Q_INVOKABLE void start();

    Q_INVOKABLE void finish();

    Q_INVOKABLE void log(QString text);

    Q_INVOKABLE void progress(int maximum, int value);

private:
    Ui::ArduinoWindow *ui;

    void signalConnect();

    void initUi();


private slots:

    void handleClose();

};

#endif
