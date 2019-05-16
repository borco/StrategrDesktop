#include "activitieslistitem.h"
#include <QLayout>
#include <QStyle>
#include <QStyleOption>
#include <QPainter>
#include <QDebug>

ActivitiesListItem::ActivitiesListItem(QString title, QWidget *parent) : QWidget(parent),
    _title(title)
{
    setFixedHeight(50);
    setStyleSheet("ActivitiesListItem {"
                  "border-bottom: 1px solid gray;"
                  "}"
                  "ActivitiesListItem::hover {"
                  "background-color: #eee;"
                  "border-bottom: 1px solid gray;"
                  "}");

    setLayout(new QHBoxLayout());
    layout()->setMargin(0);
    layout()->setSpacing(0);

    label = new QLabel();
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-weight: bold");
    label->setText(title);

    layout()->addWidget(label);
}

void ActivitiesListItem::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

QString ActivitiesListItem::title() const
{
    return _title;
}

void ActivitiesListItem::setTitle(const QString &title)
{
    _title = title;
    label->setText(title);
}

void ActivitiesListItem::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "mousePressEvent";
}

void ActivitiesListItem::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "mouseReleaseEvent";
    emit selected();

}

void ActivitiesListItem::mouseDoubleClickEvent(QMouseEvent *event)
{
    qDebug() << "mouseDoubleClickEvent";

}