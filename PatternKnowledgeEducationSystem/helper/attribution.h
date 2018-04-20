/*------- 知识库查看部分属性显示 --------*/
#ifndef ATTRIBUTION_H
#define ATTRIBUTION_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>

#include "ui_attribution.h"

class attribution : public QWidget
{
    Q_OBJECT

public:
    attribution(QWidget *parent = 0);
    ~attribution();

private:
    Ui::attribution ui;
    QSqlDatabase db;
    void init();
    void openDB();
    void openXml(QString);
};

#endif // ATTRIBUTION_H