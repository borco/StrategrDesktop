//
// Created by Dmitry Khrykin on 2019-07-08.
//

#ifndef STRATEGR_APPLICATIONMENU_H
#define STRATEGR_APPLICATIONMENU_H

#include <QMenuBar>
#include <QMenu>
#include "selfupdater.h"

class MainWindow;

class ApplicationMenu : public QMenuBar {
Q_OBJECT
public:
    explicit ApplicationMenu(MainWindow *window);

    void updateRecentFilesActions();
private:
    MainWindow *window;

    QMenu *fileMenu = new QMenu(tr("File"));
    QMenu *editMenu = new QMenu(tr("Edit"));
    QMenu *viewMenu = new QMenu(tr("View"));
    QMenu *helpMenu = new QMenu(tr("Help"));

    QMenu *recentMenu = new QMenu(tr("Open Recent"));

    QVector<QAction *> recentFileActions;

    void setupRecentMenu();
    void setupFileMenu();
    void setupViewMenu();
    void setupEditMenu();

    void createRecentFilesActions();
    void addExportToCalendarAction() const;
};


#endif //STRATEGR_APPLICATIONMENU_H
