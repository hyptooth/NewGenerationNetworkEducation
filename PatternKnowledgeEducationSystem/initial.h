/*========= 初始化模块 ========*/
#ifndef INITIAL_H
#define INITIAL_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>

#include "helper/clickablelabel.h"
#include "knowledge.h"
#include "teach.h"
#include "test.h"
#include "userinfowidget.h"

namespace Ui {
class initial;
}

class initial : public QWidget
{
    Q_OBJECT

public:
    initial(QWidget *parent = 0);
    ~initial();

    void setCurrentUserId(const QString& userId);

protected:
    //mouse func
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void timerUpDateSlot();
    void goToKnowledgeWindowSlot();
    void goToTeachWindowSlot();
    void goToTestWindowSlot();
    void goToUserWindowSlot();
    void updateCurrentKidSlot();

private:
    void initUI();
    void openDatabase();
    void init();
    void showFirstKnowledge();

private:
    Ui::initial* ui;
    QSqlDatabase db;
    QString curUserId;
    QTimer* timer                  = nullptr;
    knowledge* knowWindow          = nullptr;
    teach* teachWindow             = nullptr;
    test* testWindow               = nullptr;
    UserInfoWidget* userInfoWindow = nullptr;
    //mouse moving
    bool        mMove;
    QPoint      mPos;
};

#endif // INITIAL_H
