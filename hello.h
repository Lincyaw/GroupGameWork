#ifndef HELLO_H
#define HELLO_H

#include <QMainWindow>

class Hello : public QMainWindow
{
    Q_OBJECT
public:
    explicit Hello(QWidget *parent = 0);

signals:

public slots:
};

#endif // HELLO_H